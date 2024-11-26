import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Item {

	private final String id, name;
	private final int price, guarantee;

	public Item(String id, String name, int price, int guarantee) {
		this.id = id;
		this.name = name;
		this.price = price;
		this.guarantee = guarantee;
	}

	public String getId() {
		return id;
	}

	public int getPrice() {
		return price;
	}

	@Override
	public String toString() {
		return String.format("%s %s %d %d", id, name, price, guarantee);
	}
}

public class Main {
	public static void main(String[] args) throws FileNotFoundException {

		Scanner scanner = new Scanner(new File("SANPHAM.in"));

		int size = scanner.nextInt();
		Item[] items = new Item[size];

		for (int i = 0; i < size; i++) {

			scanner.skip("\\s+");

			String id = scanner.nextLine();
			String name = scanner.nextLine();

			int price = scanner.nextInt();
			int guarantee = scanner.nextInt();

			items[i] = new Item(id, name, price, guarantee);
		}

		scanner.close();

		Arrays.stream(items)
		    .sorted(Comparator.comparing(Item::getPrice)
		                .reversed()
		                .thenComparing(Item::getId))
		    .forEach(System.out::println);
	}
}
