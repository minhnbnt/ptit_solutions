import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Student implements Comparable<Student> {

	private final String name;
	private final int accepted, submitted;

	public Student(String name, int accepted, int submitted) {
		this.name = name;
		this.accepted = accepted;
		this.submitted = submitted;
	}

	@Override
	public String toString() {
		return String.format("%s %d %d", name, accepted, submitted);
	}

	@Override
	public int compareTo(Student other) {

		if (this.accepted != other.accepted) {
			return other.accepted - this.accepted;
		}

		if (this.submitted != other.submitted) {
			return this.submitted - other.submitted;
		}

		return this.name.compareTo(other.name);
	}
}

public class J05042 {
	public static void main(String[] args) {
		try (Scanner stdin = new Scanner(System.in)) {

			int size = stdin.nextInt();

			List<Student> students = new ArrayList<>(size);
			while (students.size() < size) {

				String name = stdin.skip("\\s+").nextLine();

				int accepted = stdin.nextInt();
				int submitted = stdin.nextInt();

				students.add(new Student(name, accepted, submitted));
			}

			students.stream().sorted().forEach(System.out::println);
		}
	}
}
