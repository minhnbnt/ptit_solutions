import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Student {

	public final String id, name, phoneNumber, email;

	Student(String id, String name, String phoneNumber, String email) {
		this.id = id;
		this.name = name;
		this.phoneNumber = phoneNumber;
		this.email = email;
	}

	public String getLastName() {
		String[] tokens = name.split("\\s+");
		return tokens[tokens.length - 1];
	}

	public String getName() {
		return name;
	}

	public String getId() {
		return id;
	}

	@Override
	public String toString() {
		return String.format("%s %s %s %s", id, name, phoneNumber, email);
	}
}

public class J07081 {

	static void solve(Scanner scanner) {

		int size = scanner.nextInt();
		Student[] students = new Student[size];

		for (int i = 0; i < size; i++) {

			String id = scanner.next();
			String name = scanner.skip("\\s+").nextLine();
			String phoneNumber = scanner.next();
			String email = scanner.next();

			students[i] = new Student(id, name, phoneNumber, email);
		}

		Arrays.stream(students)
		    .sorted(Comparator.comparing(Student::getLastName)
		                .thenComparing(Student::getName)
		                .thenComparing(Student::getId))
		    .forEach(System.out::println);
	}

	public static void main(String[] args) throws FileNotFoundException {
		try (Scanner scanner = new Scanner(new File("SINHVIEN.in"))) {
			solve(scanner);
		}
	}
}
