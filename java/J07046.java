import java.io.File;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Date;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;

class Customer {

	private final String id, name, room;
	private final Date arriveDate, leaveDate;

	Customer(String id, String name, String room, //
	         Date arriveDate, Date leaveDate) {

		this.id = id;
		this.name = name;
		this.room = room;
		this.arriveDate = arriveDate;
		this.leaveDate = leaveDate;
	}

	public long getNumberOfDay() {
		long timeDelta = leaveDate.getTime() - arriveDate.getTime();
		return TimeUnit.DAYS.convert(timeDelta, TimeUnit.MILLISECONDS);
	}

	public String toString() {
		return String.format("%s %s %s %d", id, name, room, getNumberOfDay());
	}
}

public class J07046 {

	static void solution(Scanner scanner) throws ParseException {

		SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");

		int numberOfCustomer = scanner.nextInt();

		Customer[] customers = new Customer[numberOfCustomer];
		for (int i = 0; i < numberOfCustomer; i++) {

			scanner.skip("\\s+");

			String id = String.format("KH%02d", i + 1);

			String name = scanner.nextLine();
			String room = scanner.next();

			Date arriveDate = dateFormat.parse(scanner.next());
			Date leaveDate = dateFormat.parse(scanner.next());

			customers[i] = new Customer(id, name, room, arriveDate, leaveDate);
		}

		Arrays.stream(customers)
		    .sorted(Comparator.comparing(Customer::getNumberOfDay).reversed())
		    .forEach(System.out::println);
	}

	public static void main(String[] args) throws Exception {
		try (Scanner scanner = new Scanner(new File("KHACH.in"))) {
			solution(scanner);
		}
	}
}
