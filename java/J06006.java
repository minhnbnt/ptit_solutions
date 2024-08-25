import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

class Customer {

	private final String name, address;

	public Customer(String name, String address) {
		this.address = address;
		this.name = name;
	}

	@Override
	public String toString() {
		return String.format("%s %s", name, address);
	}
}

class Item {

	private final String name;
	private final long purchase, selling;

	public Item(String name, long purchase, long selling) {
		this.purchase = purchase;
		this.selling = selling;
		this.name = name;
	}

	public long getPurchase() {
		return this.purchase;
	}

	public long getSelling() {
		return this.selling;
	}

	public String getName() {
		return this.name;
	}
}

class Bill {

	private final String id;
	private final Customer customer;
	private final Item item;
	private final long quantity;

	public Bill(String id, Customer customer, Item item, long quantity) {
		this.id = id;
		this.customer = customer;
		this.item = item;
		this.quantity = quantity;
	}

	public long getTotalProfit() {
		long profitPerItem = item.getSelling() - item.getPurchase();
		return profitPerItem * quantity;
	}

	public long getTotalPrice() {
		return item.getSelling() * quantity;
	}

	@Override
	public String toString() {
		return String.format("%s %s %s %d %d %d",          //
		                     id, customer, item.getName(), //
		                     quantity, getTotalPrice(), getTotalProfit());
	}
}

class BillGenerator {

	public Map<String, Item> itemMap;
	public Map<String, Customer> customerMap;

	public BillGenerator() {
		customerMap = new HashMap<>();
		itemMap = new HashMap<>();
	}

	public void addItem(String id, Item item) {
		itemMap.put(id, item);
	}

	public void addCustomer(String id, Customer c) {
		customerMap.put(id, c);
	}

	public Bill getBill(String id, String customerId, String itemId,
	                    long quantity) {

		Item item = itemMap.get(itemId);
		Customer customer = customerMap.get(customerId);

		return new Bill(id, customer, item, quantity);
	}
}

public class J06006 {
	public static void main(String[] args) throws ParseException {

		SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");
		Scanner stdin = new Scanner(System.in);

		BillGenerator generator = new BillGenerator();

		int customerSize = stdin.nextInt();
		stdin.skip("\\s*");

		for (int i = 1; i <= customerSize; i++) {

			String id = String.format("KH%03d", i);

			String name = stdin.nextLine();
			String _gender = stdin.nextLine();
			Date _birth = dateFormat.parse(stdin.nextLine());
			String address = stdin.nextLine();

			Customer c = new Customer(name, address);
			generator.addCustomer(id, c);
		}

		int itemSize = stdin.nextInt();

		for (int i = 1; i <= itemSize; i++) {

			String id = String.format("MH%03d", i);

			stdin.skip("\\s*");

			String name = stdin.nextLine();
			String _unit = stdin.nextLine();
			long purchase = stdin.nextLong();
			long selling = stdin.nextLong();

			Item it = new Item(name, purchase, selling);
			generator.addItem(id, it);
		}

		int numberOfBills = stdin.nextInt();
		List<Bill> bills = new ArrayList<>(numberOfBills);

		for (int i = 1; i <= numberOfBills; i++) {

			String id = String.format("HD%03d", i);

			String customerId = stdin.next();
			String itemId = stdin.next();
			long quantity = stdin.nextLong();

			Bill bill = generator.getBill(id, customerId, itemId, quantity);
			bills.add(bill);
		}

		stdin.close();

		bills.stream()
		    .sorted(Comparator.comparing(Bill::getTotalProfit).reversed())
		    .forEach(System.out::println);
	}
}
