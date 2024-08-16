import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Item {

	private final String id, name, unit;
	private final int purchase, selling;

	public Item(String id, String name, String unit, //
	            int purchase, int selling) {

		this.id = id;
		this.name = name;
		this.unit = unit;
		this.purchase = purchase;
		this.selling = selling;
	}

	public int getInterest() {
		return selling - purchase;
	}

	@Override
	public String toString() {

		int interest = this.getInterest();

		return String.format("%s %s %s %d %d %d", //
		                     id, name, unit, purchase, selling, interest);
	}
}

public class J05081 {
	public static void main(String[] args) {
		try (Scanner stdin = new Scanner(System.in)) {

			int size = stdin.nextInt();

			List<Item> items = new ArrayList<>(size);
			for (int i = 1; i <= size; i++) {

				String id = String.format("MH%03d", i);

				String name = stdin.skip("\\s+").nextLine();
				String unit = stdin.nextLine();

				int purchase = stdin.nextInt();
				int selling = stdin.nextInt();

				items.add(new Item(id, name, unit, purchase, selling));
			}

			items.stream()
			    .sorted(Comparator.comparing(Item::getInterest).reversed())
			    .forEach(System.out::println);
		}
	}
}
