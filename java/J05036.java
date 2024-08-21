import java.util.Arrays;
import java.util.Scanner;

class Item {

	private final String id, name, unit;
	private final long purchase, quantity;

	public Item(String id, String name, String unit, //
	            long purchase, long qunatity) {
		this.id = id;
		this.name = name;
		this.unit = unit;
		this.purchase = purchase;
		this.quantity = qunatity;
	}

	public long getShipPrice() {
		double result = purchase * quantity * 0.05;
		return Math.round(result);
	}

	public long getTotalPrice() {
		return purchase * quantity + getShipPrice();
	}

	public long getSellPrice() {
		double result = this.getTotalPrice() * 1.02;
		return Math.round(result);
	}

	@Override
	public String toString() {
		return String.format("%s %s %s %d %d %d", //
		                     id, name, unit,      //
		                     getShipPrice(), getTotalPrice(), getSellPrice());
	}
}

public class J05036 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int size = stdin.nextInt();

		Item[] items = new Item[size];

		for (int i = 0; i < size; i++) {

			String id = String.format("MH%02d", i + 1);
			String name = stdin.skip("\\s+").nextLine();
			String unit = stdin.nextLine();

			long purchase = stdin.nextLong();
			long quantity = stdin.nextLong();

			items[i] = new Item(id, name, unit, purchase, quantity);
		}

		stdin.close();

		Arrays.stream(items).forEach(System.out::println);
	}
}
