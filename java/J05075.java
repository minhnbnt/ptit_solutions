import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

class Student {

	private int attendancePoint;
	private final String id, name, grade;

	public Student(String id, String name, String grade) {
		this.grade = grade;
		this.name = name;
		this.id = id;
	}

	public String toString() {

		String result = String.format("%s %s %s %d", //
		                              id, name, grade, attendancePoint);

		if (attendancePoint == 0) {
			result += " KDDK";
		}

		return result;
	}

	public String getGrade() {
		return this.grade;
	}

	public void setAttendancePoint(String stats) {

		int point = 10 - stats.codePoints()
		                     .map(stat -> {
			                     switch (stat) {
			                     case 'v':
				                     return 2;
			                     case 'm':
				                     return 1;

			                     default:
				                     return 0;
			                     }
		                     })
		                     .sum();

		if (point < 0) point = 0;

		this.attendancePoint = point;
	}
}

public class J05075 {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int size = stdin.nextInt();
		stdin.skip("\\s+");

		Map<String, Student> studentMap = new LinkedHashMap<>();

		for (int i = 0; i < size; i++) {

			String id = stdin.nextLine();
			String name = stdin.nextLine();
			String grade = stdin.nextLine();

			studentMap.put(id, new Student(id, name, grade));
		}

		for (int i = 0; i < size; i++) {

			String id = stdin.next();
			String stats = stdin.next();

			studentMap.get(id).setAttendancePoint(stats);
		}

		String targetGrade = stdin.skip("\\s+").nextLine();

		studentMap.values()
		    .stream()
		    .filter(student -> student.getGrade().equals(targetGrade))
		    .forEach(System.out::println);

		stdin.close();
	}
}
