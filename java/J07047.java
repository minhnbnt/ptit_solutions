import java.io.File;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.concurrent.TimeUnit;

class RoomType {

	private final char type;
	private final String name;
	private final double dailyPrice, servicePrice;

	RoomType(char type, String name, double dailyPrice, double servicePrice) {
		this.type = type;
		this.name = name;
		this.dailyPrice = dailyPrice;
		this.servicePrice = servicePrice;
	}

	public char getType() {
		return type;
	}

	public double getDailyPrice() {
		return dailyPrice;
	}

	public double getServicePrice() {
		return servicePrice;
	}
}

class Customer {

	private final String id, name, room;
	private final RoomType roomType;
	private final Date arriveDate, leaveDate;

	Customer(String id, String name, String room, RoomType roomType,
	         Date arriveDate, Date leaveDate) {

		this.id = id;
		this.name = name;
		this.room = room;
		this.roomType = roomType;
		this.arriveDate = arriveDate;
		this.leaveDate = leaveDate;
	}

	public long getNumberOfDay() {
		long timeDelta = leaveDate.getTime() - arriveDate.getTime();
		return TimeUnit.DAYS.convert(timeDelta, TimeUnit.MILLISECONDS);
	}

	public float getDiscount() {

		long numberOfDay = this.getNumberOfDay();

		if (numberOfDay < 10) {
			return 0;
		}

		if (numberOfDay < 20) {
			return 0.02F;
		}

		if (numberOfDay < 30) {
			return 0.04F;
		}

		return 0.06F;
	}

	public double getTotalPrice() {

		long numberOfDay = this.getNumberOfDay();
		if (numberOfDay < 1) {
			numberOfDay = 1;
		}

		double withoutService = roomType.getDailyPrice() * numberOfDay;
		double withService = withoutService * (1 + roomType.getServicePrice());

		return withService * (1 - this.getDiscount());
	}

	public String toString() {
		return String.format("%s %s %s %d %.2f", //
		                     id, name, room,     //
		                     getNumberOfDay(), getTotalPrice());
	}
}

public class J07047 {

	static void solution(Scanner scanner) throws ParseException {

		SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");

		int numberOfRoomType = scanner.nextInt();

		Map<Character, RoomType> roomTypeMap = new HashMap<>();
		for (int i = 0; i < numberOfRoomType; i++) {

			char type = scanner.next().charAt(0);
			String name = scanner.next();
			double dailyPrice = scanner.nextDouble();
			double servicePrice = scanner.nextDouble();

			roomTypeMap.put(type,
			                new RoomType(type, name, dailyPrice, servicePrice));
		}

		int numberOfCustomer = scanner.nextInt();

		Customer[] customers = new Customer[numberOfCustomer];
		for (int i = 0; i < numberOfCustomer; i++) {

			scanner.skip("\\s+");

			String id = String.format("KH%02d", i + 1);

			String name = scanner.nextLine();

			String room = scanner.next();
			RoomType roomType = roomTypeMap.get(room.charAt(2));

			Date arriveDate = dateFormat.parse(scanner.next());
			Date leaveDate = dateFormat.parse(scanner.next());

			customers[i] = new Customer(id, name, room, roomType, //
			                            arriveDate, leaveDate);
		}

		Arrays.stream(customers)
		    .sorted(Comparator.comparing(Customer::getNumberOfDay).reversed())
		    .forEach(System.out::println);
	}

	public static void main(String[] args) throws Exception {
		try (Scanner scanner = new Scanner(new File("DATA.in"))) {
			solution(scanner);
		}
	}
}
