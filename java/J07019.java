import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class Item {

	private final String name;
	private final long type1Price, type2Price;

	Item(String name, long type1Price, long type2Price) {
		this.name = name;
		this.type1Price = type1Price;
		this.type2Price = type2Price;
	}

	public static int getDiscountPercent(int quantity) {

		if (quantity >= 150) {
			return 50;
		}

		if (quantity >= 100) {
			return 30;
		}

		if (quantity >= 50) {
			return 15;
		}

		return 0;
	}

	public String getName() {
		return name;
	}

	public long getType1Price() {
		return type1Price;
	}

	public long getType2Price() {
		return type2Price;
	}
}

public class J07019 {

	static Map<String, Item> getItemMap(Scanner scanner) {

		int size = scanner.nextInt();

		Map<String, Item> itemMap = new HashMap<>();
		for (int i = 0; i < size; i++) {

			String id = scanner.next();
			String name = scanner.skip("\\s+").nextLine();

			long type1Price = scanner.nextLong();
			long type2Price = scanner.nextLong();

			itemMap.put(id, new Item(name, type1Price, type2Price));
		}

		return itemMap;
	}

	static void solve(Map<String, Item> itemMap, Scanner scanner) {

		int cases = scanner.nextInt();
		for (int i = 1; i <= cases; i++) {

			String id = scanner.next();
			id += String.format("-%03d", i);

			int quantity = scanner.nextInt();

			String itemId = id.substring(0, 2);
			Item item = itemMap.get(itemId);

			int type = id.codePointAt(2) - '0';

			long pricePerItem = type == 1 //
			                        ? item.getType1Price()
			                        : item.getType2Price();

			long withoutDiscount = pricePerItem * quantity;
			int discountPercent = Item.getDiscountPercent(quantity);

			long discount = withoutDiscount * discountPercent / 100;
			long withDiscount = withoutDiscount - discount;

			System.out.printf("%s %s %d %d%n", //
			                  id, item.getName(), discount, withDiscount);
		}
	}

	public static void main(String[] args) throws FileNotFoundException {

		Map<String, Item> itemMap;
		try (Scanner scanner = new Scanner(new File("DATA1.in"))) {
			itemMap = getItemMap(scanner);
		}

		try (Scanner scanner = new Scanner(new File("DATA2.in"))) {
			solve(itemMap, scanner);
		}
	}
}
