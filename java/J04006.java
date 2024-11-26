import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

class Student {

	private final String id, name, grade;
	private final Date birth;
	private final float gpa;

	Student(String id, String name, String grade, Date birth, float gpa) {
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

public class Main {
	public static void main(String[] args) throws ParseException {

		SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");

		Scanner stdin = new Scanner(System.in);

		String id = "B20DCCN001";

		String name = stdin.nextLine();
		String grade = stdin.nextLine();
		Date birth = dateFormat.parse(stdin.nextLine());
		float gpa = stdin.nextFloat();

		Student s = new Student(id, name, grade, birth, gpa);
		System.out.println(s);
	}
}
