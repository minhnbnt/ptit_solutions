import java.io.File;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.Duration;
import java.time.Instant;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class J07084 {

	static void solve(Scanner scanner, SimpleDateFormat format)
	    throws ParseException {

		int size = scanner.nextInt();

		Student[] students = new Student[size];
		for (int i = 0; i < size; i++) {

			String fullname = scanner.skip("\\s*").nextLine();

			Instant start = format.parse(scanner.nextLine()).toInstant();
			Instant finish = format.parse(scanner.nextLine()).toInstant();
			students[i] = new Student(fullname, start, finish);
		}

		Arrays.stream(students)
		    .sorted(Comparator.comparing(Student::getOnlineMinute).reversed())
		    .forEach(System.out::println);
	}

	public static void main(String[] args) throws Exception {

		SimpleDateFormat formatter =
		    new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");

		try (Scanner scanner = new Scanner(new File("ONLINE.in"))) {
			solve(scanner, formatter);
		}
	}

	static class Student {

		private final String name;
		private final Instant start, finish;

		Student(String name, Instant start, Instant finish) {
			this.name = name;
			this.start = start;
			this.finish = finish;
		}

		public long getOnlineMinute() {
			return Duration.between(start, finish).toMinutes();
		}

		@Override
		public String toString() {
			return String.format("%s %d", name, getOnlineMinute());
		}
	}
}
