import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

class Teacher implements Comparable<Teacher> {

	private final String id, name, subject;

	public Teacher(String id, String name, String subject) {
		this.subject = subject;
		this.name = name;
		this.id = id;
	}

	@Override
	public String toString() {
		return String.format("%s %s %s", id, name, subject);
	}

	public String getLastName() {
		String[] words = name.split("\\s+");
		return words[words.length - 1];
	}

	@Override
	public int compareTo(Teacher other) {

		String thisLastName = this.getLastName();
		String otherLastName = other.getLastName();

		if (thisLastName.equals(otherLastName)) {
			return this.id.compareTo(other.id);
		}

		return thisLastName.compareTo(otherLastName);
	}
}

public class J05025 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int size = stdin.nextInt();
		stdin.skip("\\s+");

		List<Teacher> teachers = new ArrayList<>(size);

		for (int i = 1; i <= size; i++) {

			String id = String.format("GV%02d", i);
			String name = stdin.nextLine();
			String subject = Utils.getAbbreviation(stdin.nextLine());

			teachers.add(new Teacher(id, name, subject));
		}

		stdin.close();

		teachers.stream().sorted().forEach(System.out::println);
	}
}

class Utils {
	public static String getAbbreviation(String s) {
		return Arrays.stream(s.split("\\s+"))
		    .map(token -> token.substring(0, 1).toUpperCase())
		    .collect(Collectors.joining());
	}
}
