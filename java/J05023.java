import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Student {

	private final String id, name, grade, email;

	public Student(String id, String name, String grade, String email) {
		this.grade = grade;
		this.email = email;
		this.name = name;
		this.id = id;
	}

	@Override
	public String toString() {
		return String.format("%s %s %s %s", //
		                     id, name, grade, email);
	}

	public String getYear() {
		return "20" + Integer.parseInt(grade.substring(1, 3));
	}
}

public class J05023 {
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

		while (queries-- > 0) {

			String year = stdin.next();
			System.out.printf("DANH SACH SINH VIEN KHOA %s:%n", year);

			students.stream()
			    .filter(s -> s.getYear().equals(year))
			    .forEachOrdered(System.out::println);
		}

		stdin.close();
	}
}
