import java.io.File;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Date;
import java.util.Scanner;
import java.util.stream.Collectors;

class Customer {

	private final String id, name, gender, address;
	private final Date birth;

	Customer(String id, String name, String gender, //
	         String address, Date birth) {
		this.id = id;
		this.name = name;
		this.gender = gender;
		this.address = address;
		this.birth = birth;
	}

	public Date getBirth() {
		return birth;
	}

	@Override
	public String toString() {
		return String.format("%s %s %s %s %td/%<tm/%<tY", //
		                     id, name, gender, address, birth);
	}
}

public class J07025 {

	public static void main(String[] args) throws Exception {

		SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");

		try (Scanner scanner = new Scanner(new File("KHACHHANG.in"))) {
			solve(scanner, dateFormat);
		}
	}

	static void solve(Scanner scanner, SimpleDateFormat dateFormat)
	    throws ParseException {

		int size = scanner.nextInt();

		Customer[] customers = new Customer[size];
		for (int i = 0; i < size; i++) {

			String id = String.format("KH%03d", i + 1);
			String name = scanner.skip("\\s*").nextLine();
			name = Utils.titleString(name);

			String gender = scanner.next();
			Date birth = dateFormat.parse(scanner.next());
			String address = scanner.skip("\\s*").nextLine();

			customers[i] = new Customer(id, name, gender, address, birth);
		}

		Arrays.stream(customers)
		    .sorted(Comparator.comparing(Customer::getBirth))
		    .forEach(System.out::println);
	}
}

class Utils {

	static String titleString(String s) {

		String[] tokens = s.trim().split("\\s+");
		if (tokens.length > 1) {
			return Arrays.stream(tokens)
			    .map(Utils::titleString)
			    .collect(Collectors.joining(" "));
		}

		char[] chars = tokens[0].toCharArray();
		for (int i = 0; i < chars.length; i++) {
			chars[i] = Character.toLowerCase(chars[i]);
		}

		chars[0] = Character.toUpperCase(chars[0]);

		return new String(chars);
	}
}
