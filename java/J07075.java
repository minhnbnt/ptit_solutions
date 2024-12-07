import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

class Subject {

	private final String id, name;
	private final int token;

	public Subject(String id, String name, int token) {
		this.id = id;
		this.name = name;
		this.token = token;
	}

	public String getName() {
		return name;
	}
}

class TeachCalendar {

	private final Subject subject;
	private final String groupId, room;
	private final byte dayOfWeek, timePosition;

	TeachCalendar(String groupId, Subject subject, String room, byte dayOfWeek,
	              byte timePosition) {
		this.groupId = groupId;
		this.subject = subject;
		this.room = room;
		this.dayOfWeek = dayOfWeek;
		this.timePosition = timePosition;
	}

	public byte getDayOfWeek() {
		return dayOfWeek;
	}

	@Override
	public String toString() {
		return String.format("%s %s %d %d %s",           //
		                     groupId, subject.getName(), //
		                     dayOfWeek, timePosition, room);
	}
}

public class J07075 {

	static Map<String, Subject> getSubjectMap(Scanner scanner) {

		Map<String, Subject> subjectMap = new HashMap<>();

		int size = scanner.nextInt();

		for (int i = 0; i < size; i++) {

			String id = scanner.next();
			String name = scanner.skip("\\s+").nextLine();
			int token = scanner.nextInt();

			subjectMap.put(id, new Subject(id, name, token));
		}

		return subjectMap;
	}

	static void solve(Map<String, Subject> subjectMap, Scanner scanner) {

		int size = scanner.nextInt();

		Map<String, List<TeachCalendar>> teachCalendarMap = new HashMap<>();

		for (int i = 0; i < size; i++) {

			String groupId = String.format("HP%03d", i + 1);

			Subject subject = subjectMap.get(scanner.next());
			byte dayOfWeek = scanner.nextByte();
			byte timePosition = scanner.nextByte();

			String teacherName = scanner.skip("\\s+").nextLine();
			String room = scanner.next();

			teachCalendarMap
			    .computeIfAbsent(teacherName, name -> new ArrayList<>())
			    .add(new TeachCalendar(groupId, subject, room, dayOfWeek,
			                           timePosition));
		}

		String teacherName = scanner.skip("\\s+").nextLine();
		List<TeachCalendar> teachCalendar = teachCalendarMap.get(teacherName);
		if (teachCalendar == null) {
			teachCalendar = new ArrayList<>();
		}

		System.out.printf("LICH GIANG DAY GIANG VIEN %s:%n", teacherName);

		teachCalendar.stream()
		    .sorted(Comparator.comparing(TeachCalendar::getDayOfWeek))
		    .forEach(System.out::println);
	}

	public static void main(String[] args) throws FileNotFoundException {

		Map<String, Subject> subjectMap;

		try (Scanner scanner = new Scanner(new File("MONHOC.in"))) {
			subjectMap = getSubjectMap(scanner);
		}

		try (Scanner scanner = new Scanner(new File("LICHGD.in"))) {
			solve(subjectMap, scanner);
		}
	}
}
