import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Student {

	private final String id, name, grade, email;

	public Student(String id, String name, String grade, String email) {
		this.id = id;
		this.name = name;
		this.grade = grade;
		this.email = email;
	}

	@Override
	public String toString() {
		return String.format("%s %s %s %s", id, name, grade, email);
	}

	public String getId() {
		return this.id;
	}
}

public class J05021 {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		List<Student> students = new ArrayList<>();

		while (stdin.hasNext()) {

			String id = stdin.nextLine();
			String name = stdin.nextLine();
			String grade = stdin.nextLine();
			String email = stdin.nextLine();

			students.add(new Student(id, name, grade, email));
		}

		stdin.close();

		students.stream()
		    .sorted(Comparator.comparing(Student::getId))
		    .forEach(System.out::println);
	}
}
