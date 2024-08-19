import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.Collectors;

class Student {

	private final String id, name, grade;
	private final Float[] scores;

	public Student(String id, String name, String grade, Float[] scores) {
		this.scores = scores;
		this.grade = grade;
		this.name = name;
		this.id = id;
	}

	@Override
	public String toString() {

		String scores = Arrays.stream(this.scores)
		                    .map(score -> String.format("%.1f", score))
		                    .collect(Collectors.joining(" "));

		return String.format("%s %s %s %s", id, name, grade, scores);
	}

	public String getName() {
		return this.name;
	}
}

public class J05031 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int size = stdin.nextInt();

		List<Student> students = new ArrayList<>(size);

		for (int i = 1; i <= size; i++) {

			stdin.skip("\\s+");

			String id = stdin.nextLine();
			String name = stdin.nextLine();
			String grade = stdin.nextLine();

			Float[] scores = new Float[3];
			for (int j = 0; j < scores.length; j++) {
				scores[j] = stdin.nextFloat();
			}

			students.add(new Student(id, name, grade, scores));
		}

		stdin.close();

		AtomicInteger counter = new AtomicInteger();

		students.stream()
		    .sorted(Comparator.comparing(Student::getName))
		    .forEach((s) -> {
			    int position = counter.addAndGet(1);
			    System.out.printf("%d %s%n", position, s);
		    });
	}
}
