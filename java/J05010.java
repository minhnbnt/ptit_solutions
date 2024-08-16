import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Item {

	private final int id;
	private final String name, category;
	private final double purchase, selling;

	public Item(int id, String name, String category, //
	            double purchase, double selling) {

		this.id = id;
		this.name = name;
		this.category = category;
		this.purchase = purchase;
		this.selling = selling;
	}

	public double getInterest() {
		return selling - purchase;
	}

	@Override
	public String toString() {
		double interest = this.getInterest();
		return String.format("%d %s %s %.2f", //
		                     id, name, category, interest);
	}
}

public class J05010 {
	public static void main(String[] args) {
		try (Scanner stdin = new Scanner(System.in)) {

			int size = stdin.nextInt();

			List<Item> items = new ArrayList<>(size);
			for (int id = 1; id <= size; id++) {

				String name = stdin.skip("\\s+").nextLine();
				String category = stdin.nextLine();

				double purchase = stdin.nextDouble();
				double selling = stdin.nextDouble();

				items.add(new Item(id, name, category, purchase, selling));
			}

			items.stream()
			    .sorted(Comparator.comparing(Item::getInterest).reversed())
			    .forEach(System.out::println);
		}
	}
}
