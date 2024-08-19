import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

class Student {

	private final String id, name, grade;
	private int attendancePoint;

	public Student(String id, String name, String grade) {
		this.id = id;
		this.name = name;
		this.grade = grade;
	}

	public String toString() {

		String result = String.format("%s %s %s %d", //
		                              id, name, grade, attendancePoint);

		if (attendancePoint == 0) {
			result += " KDDK";
		}

		return result;
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

public class J05074 {

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

		stdin.close();

		studentMap.forEach((id, stu) -> System.out.println(stu));
	}
}
