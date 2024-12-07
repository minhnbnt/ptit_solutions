import java.io.File;
import java.io.FileNotFoundException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Customer {

	private final String name, _gender, address;
	private final Date _birth;

	public Customer(String name, String gender, Date birth, String address) {
		this.name = name;
		this._birth = birth;
		this._gender = gender;
		this.address = address;
	}

	@Override
	public String toString() {
		return String.format("%s %s", name, address);
	}
}

class Item {

	private final long buy, sell;
	private final String name, unit;

	Item(String name, String unit, long buy, long sell) {
		this.name = name;
		this.unit = unit;
		this.buy = buy;
		this.sell = sell;
	}

	@Override
	public String toString() {
		return String.format("%s %s %d %d", name, unit, buy, sell);
	}

	public long getSell() {
		return sell;
	}
}

class Bill {

	private final Item item;
	private final int quantity;
	private final Customer customer;

	Bill(Customer customer, Item item, int quantity) {
		this.customer = customer;
		this.quantity = quantity;
		this.item = item;
	}

	public long getPrice() {
		return item.getSell() * quantity;
	}

	@Override
	public String toString() {
		return String.format("%s %s %d %d", //
		                     customer, item, quantity, getPrice());
	}
}

public class J07020 {

	static Map<String, Customer> getCustomerMap(Scanner scanner)
	    throws ParseException {

		SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");

		int size = scanner.nextInt();

		Map<String, Customer> result = new HashMap<>();
		for (int i = 1; i <= size; i++) {

			String id = String.format("KH%03d", i);

			String name = scanner.skip("\\s*").nextLine();
			String gender = scanner.next();

			Date birth = dateFormat.parse(scanner.next());
			String address = scanner.skip("\\s*").nextLine();

			result.put(id, new Customer(name, gender, birth, address));
		}

		return result;
	}

	static Map<String, Item> getItemMap(Scanner scanner) {

		int size = scanner.nextInt();

		Map<String, Item> result = new HashMap<>();
		for (int i = 1; i <= size; i++) {

			String id = String.format("MH%03d", i);

			String name = scanner.skip("\\s*").nextLine();
			String unit = scanner.skip("\\s*").nextLine();

			long buy = scanner.nextLong();
			long sell = scanner.nextLong();

			result.put(id, new Item(name, unit, buy, sell));
		}

		return result;
	}

	public static void main(String[] args)
	    throws FileNotFoundException, ParseException {

		Map<String, Customer> customerMap;
		try (Scanner scanner = new Scanner(new File("KH.in"))) {
			customerMap = getCustomerMap(scanner);
		}

		Map<String, Item> itemMap;
		try (Scanner scanner = new Scanner(new File("MH.in"))) {
			itemMap = getItemMap(scanner);
		}

		try (Scanner scanner = new Scanner(new File("HD.in"))) {
			solve(scanner, customerMap, itemMap);
		}
	}

	static void solve(Scanner scanner, Map<String, Customer> customerMap,
	                  Map<String, Item> itemMap) {

		int numberOfBill = scanner.nextInt();

		for (int i = 1; i <= numberOfBill; i++) {

			Customer customer = customerMap.get(scanner.next());
			Item item = itemMap.get(scanner.next());

			int quantity = scanner.nextInt();

			System.out.printf("HD%03d ", i);
			System.out.println(new Bill(customer, item, quantity));
		}
	}
}
