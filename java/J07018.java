import java.io.File;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;
import java.util.stream.Collectors;

class Student {

	private final String id, fullname, grade;
	private final Date birth;
	private final float GPA;

	public Student(String id, String fullname, String grade, Date birth,
	               float gpa) {
		this.id = id;
		this.fullname = fullname;
		this.grade = grade;
		this.birth = birth;
		GPA = gpa;
	}

	@Override
	public String toString() {

		String formattedBirth = Utils.dateFormat.format(birth);

		return String.format("%s %s %s %s %.2f", //
		                     id, fullname, grade, formattedBirth, GPA);
	}
}

public class J07018 {

	static void solve(Scanner scanner) throws ParseException {

		int size = scanner.nextInt();
		Student[] students = new Student[size];

		for (int i = 0; i < size; i++) {

			String id = String.format("B20DCCN%03d", i + 1);
			String name = Utils.titleString(scanner.skip("\\s*").nextLine());
			String grade = scanner.next();
			Date birth = Utils.dateFormat.parse(scanner.next());
			float GPA = scanner.nextFloat();

			students[i] = new Student(id, name, grade, birth, GPA);
		}

		Arrays.stream(students).forEach(System.out::println);
	}

	public static void main(String[] args) throws Exception {
		try (Scanner scanner = new Scanner(new File("SINHVIEN.in"))) {
			solve(scanner);
		}
	}
}

class Utils {

	static SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");

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
