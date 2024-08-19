import java.util.ArrayList;
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

	public String getGrade() {
		return this.grade;
	}
}

public class J05022 {
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

		int queries = stdin.nextInt();
		stdin.skip("\\s+");

		while (queries-- > 0) {

			String grade = stdin.nextLine();
			System.out.printf("DANH SACH SINH VIEN LOP %s:%n", grade);

			students.stream()
			    .filter(s -> s.getGrade().equals(grade))
			    .forEachOrdered(System.out::println);
		}

		stdin.close();
	}
}
