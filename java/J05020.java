import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Student implements Comparable<Student> {

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

	@Override
	public int compareTo(Student other) {
		if (this.grade.equals(other.grade)) {
			return this.id.compareTo(other.id);
		}

		return this.grade.compareTo(other.grade);
	}
}

public class J05020 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int size = stdin.nextInt();
		stdin.skip("\\s+");

		List<Student> students = new ArrayList<>(size);

		for (int i = 1; i <= size; i++) {

			String id = stdin.nextLine();
			String name = stdin.nextLine();
			String grade = stdin.nextLine();
			String email = stdin.nextLine();

			students.add(new Student(id, name, grade, email));
		}

		stdin.close();

		students.stream().sorted().forEach(System.out::println);
	}
}
