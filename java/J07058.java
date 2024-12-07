import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Subject {

	private final String id, name, method;

	Subject(String id, String name, String method) {
		this.id = id;
		this.name = name;
		this.method = method;
	}

	@Override
	public String toString() {
		return String.format("%s %s %s", id, name, method);
	}

	public String getId() {
		return id;
	}
}

public class J07058 {

	static void solve(Scanner scanner) {

		int size = scanner.nextInt();
		Subject[] subjects = new Subject[size];

		for (int i = 0; i < size; i++) {

			String id = scanner.next();
			String name = scanner.skip("\\s+").nextLine();
			String method = scanner.nextLine();

			subjects[i] = new Subject(id, name, method);
		}

		Arrays.stream(subjects)
		    .sorted(Comparator.comparing(Subject::getId))
		    .forEach(System.out::println);
	}

	public static void main(String[] args) throws FileNotFoundException {
		try (Scanner scanner = new Scanner(new File("MONHOC.in"))) {
			solve(scanner);
		}
	}
}
