import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

class Student {

	private final String id, name, grade;
	private final Date birth;
	private final float gpa;

	public Student(String id, String name, String grade, Date birth,
	               float gpa) {
		this.id = id;
		this.name = name;
		this.grade = grade;
		this.birth = birth;
		this.gpa = gpa;
	}

	@Override
	public String toString() {
		return String.format("%s %s %s %td/%<tm/%<tY %.2f", //
		                     id, name, grade, birth, gpa);
	}
}

public class J05003 {

	public static void main(String[] args) throws ParseException {

		SimpleDateFormat format = new SimpleDateFormat("dd/MM/yyyy");

		try (Scanner stdin = new Scanner(System.in)) {

			int size = stdin.nextInt();

			List<Student> students = new ArrayList<>(size);

			for (int i = 0; i < size; i++) {

				String id = String.format("B20DCCN%03d", i + 1);

				String name = stdin.skip("\\s+").nextLine();
				String grade = stdin.nextLine();
				Date birth = format.parse(stdin.nextLine());
				float gpa = stdin.nextFloat();

				students.add(new Student(id, name, grade, birth, gpa));
			}

			students.forEach(System.out::println);
		}
	}
}
