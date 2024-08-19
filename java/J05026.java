import java.util.*;
import java.util.stream.Collectors;

class Teacher {

	private final String id, name, subject;

	public Teacher(String id, String name, String subject) {
		this.subject = subject;
		this.name = name;
		this.id = id;
	}

	@Override
	public String toString() {
		String subject = Utils.getAbbreviation(this.subject);
		return String.format("%s %s %s", id, name, subject);
	}

	public String getSubject() {
		return this.subject;
	}
}

public class J05026 {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int size = stdin.nextInt();
		stdin.skip("\\s+");

		List<Teacher> teachers = new ArrayList<>(size);

		for (int i = 1; i <= size; i++) {

			String id = String.format("GV%02d", i);
			String name = stdin.nextLine();
			String subject = stdin.nextLine();

			teachers.add(new Teacher(id, name, subject));
		}

		int query = stdin.nextInt();
		stdin.skip("\\s+");

		while (query-- > 0) {

			String subject = stdin.nextLine();

			System.out.printf("DANH SACH GIANG VIEN BO MON %s:%n",
			                  Utils.getAbbreviation(subject));

			teachers.stream()
			    .filter(t -> t.getSubject().equals(subject))
			    .forEach(System.out::println);
		}

		stdin.close();
	}
}

class Utils {
	public static String getAbbreviation(String s) {
		return Arrays.stream(s.split("\\s+"))
		    .map(token -> token.substring(0, 1).toUpperCase())
		    .collect(Collectors.joining());
	}
}
