import java.io.File;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

class Item {

	private final String id;
	private final long price;
	private final int warrantyMonth;

	public Item(String id, long price, int guaranteeMonth) {
		this.id = id;
		this.price = price;
		this.warrantyMonth = guaranteeMonth;
	}

	public long getPrice() {
		return price;
	}

	public int getWarrantyMonth() {
		return warrantyMonth;
	}

	public String getId() {
		return id;
	}
}

class Customer {

	private final String id, fullname, address;
	private final Date purchaseDate;
	private final int quantity;
	private final Item bought;

	public Customer(String id, String fullname, String address, int quantity,
	                Item bought, Date purchaseDate) {
		this.id = id;
		this.fullname = fullname;
		this.address = address;
		this.quantity = quantity;
		this.bought = bought;
		this.purchaseDate = purchaseDate;
	}

	public Date getWarrantyExpiration() {

		Calendar calendar = Calendar.getInstance();

		calendar.setTime(purchaseDate);
		calendar.add(Calendar.MONTH, bought.getWarrantyMonth());

		return calendar.getTime();
	}

	public long getPaid() {
		return bought.getPrice() * quantity;
	}

	public String getId() {
		return id;
	}

	public String toString(SimpleDateFormat dateFormat) {

		String formattedExp = dateFormat.format(this.getWarrantyExpiration());

		return String.format("%s %s %s %s %d %s",   //
		                     id, fullname, address, //
		                     bought.getId(), this.getPaid(), formattedExp);
	}
}

public class J07049 {

	static Map<String, Item> getItemMap(Scanner scanner) {

		int itemSize = scanner.nextInt();
		Map<String, Item> itemMap = new HashMap<>();

		for (int i = 0; i < itemSize; i++) {

			String id = scanner.next();
			String _name = scanner.skip("\\s+").nextLine();
			long price = scanner.nextLong();
			int warrantyMonth = scanner.nextInt();

			itemMap.put(id, new Item(id, price, warrantyMonth));
		}

		return itemMap;
	}

	static void solve(Scanner scanner, SimpleDateFormat dateFormat)
	    throws ParseException {

		Map<String, Item> itemMap = getItemMap(scanner);

		int customerSize = scanner.nextInt();
		Customer[] customers = new Customer[customerSize];

		for (int i = 0; i < customerSize; i++) {

			String id = String.format("KH%02d", i + 1);
			String fullName = scanner.skip("\\s*").nextLine();
			String address = scanner.nextLine();
			Item item = itemMap.get(scanner.next());
			int quantity = scanner.nextInt();
			Date purchaseDate = dateFormat.parse(scanner.next());

			customers[i] = new Customer(id, fullName, address, quantity, item,
			                            purchaseDate);
		}

		Arrays.stream(customers)
		    .sorted(Comparator //
		                .comparing(Customer::getWarrantyExpiration)
		                .thenComparing(Customer::getId))
		    .map(customer -> customer.toString(dateFormat))
		    .forEach(System.out::println);
	}

	public static void main(String[] args) throws Exception {

		SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");

		try (Scanner scanner = new Scanner(new File("MUAHANG.in"))) {
			solve(scanner, dateFormat);
		}
	}
}
