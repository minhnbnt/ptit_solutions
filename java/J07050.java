import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Item {

	private final String id, name, category;
	private final double purchase, selling;

	public Item(String id, String name, String category, //
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
		return String.format("%s %s %s %.2f", //
		                     id, name, category, interest);
	}
}

public class J07050 {
	public static void main(String[] args) throws FileNotFoundException {

		File inputFile = new File("MATHANG.in");

		try (Scanner stdin = new Scanner(inputFile)) {

			int size = stdin.nextInt();

			List<Item> items = new ArrayList<>(size);
			for (int i = 1; i <= size; i++) {

				String id = String.format("MH%02d", i);

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
