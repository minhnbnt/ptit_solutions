import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.stream.Collectors;

class Student {

	private final float gpa;
	private final Date birth;
	private final String id, name, grade;

	public Student(String id, String name, String grade, //
	               Date birth, float gpa) {

		this.grade = grade;
		this.birth = birth;
		this.name = name;
		this.gpa = gpa;
		this.id = id;
	}

	@Override
	public String toString() {
		return String.format("%s %s %s %td/%<tm/%<tY %.2f", //
		                     id, name, grade, birth, gpa);
	}
}

public class J05004 {
	public static void main(String[] args) throws ParseException {

		SimpleDateFormat format = new SimpleDateFormat("dd/MM/yyyy");
		Scanner stdin = new Scanner(System.in);

		int size = stdin.nextInt();

		List<Student> students = new ArrayList<>(size);

		for (int i = 1; i <= size; i++) {

			String id = String.format("B20DCCN%03d", i);

			String name = stdin.skip("\\s+").nextLine();
			name = Utils.correctString(name);

			String grade = stdin.nextLine();
			Date birth = format.parse(stdin.nextLine());
			float gpa = stdin.nextFloat();

			students.add(new Student(id, name, grade, birth, gpa));
		}

		stdin.close();

		students.forEach(System.out::println);
	}
}

class Utils {
	public static String titleString(String s) {

		char[] chars = s.toCharArray();

		for (int i = 0; i < chars.length; i++) {
			chars[i] = Character.toLowerCase(chars[i]);
		}

		chars[0] = Character.toUpperCase(chars[0]);

		return new String(chars);
	}

	public static String correctString(String s) {
		return Arrays.stream(s.split("\\s+"))
		    .map(Utils::titleString)
		    .collect(Collectors.joining(" "));
	}
}
