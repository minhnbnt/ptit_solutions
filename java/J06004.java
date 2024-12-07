import java.util.*;

class Student {

	private final Group group;
	private final String id, name, phoneNumber;

	Student(String id, String name, String phoneNumber, Group group) {
		this.phoneNumber = phoneNumber;
		this.group = group;
		this.name = name;
		this.id = id;
	}

	@Override
	public String toString() {
		return String.format("%s %s %s %s", id, name, phoneNumber, group);
	}

	public String getId() {
		return id;
	}
}

class Group {

	private final int id;
	private String topic;

	Group(int id, String topic) {
		this.id = id;
		this.setTopic(topic);
	}

	public void setTopic(String topic) {
		this.topic = topic;
	}

	@Override
	public String toString() {
		return String.format("%d %s", id, topic);
	}
}

public class J06004 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int numberOfStudent = stdin.nextInt();
		int numberOfGroup = stdin.nextInt();

		Map<Integer, Group> groupMap = new LinkedHashMap<>();

		for (int id = 1; id <= numberOfGroup; id++) {
			groupMap.put(id, new Group(id, null));
		}

		Student[] students = new Student[numberOfStudent];
		for (int i = 0; i < numberOfStudent; i++) {

			String id = stdin.next();
			String name = stdin.skip("\\s+").nextLine();
			String phoneNumber = stdin.next();

			int groupId = stdin.nextInt();
			Group group = groupMap.get(groupId);

			students[i] = new Student(id, name, phoneNumber, group);
		}

		groupMap.forEach((id, group) -> { //
			group.setTopic(stdin.skip("\\s*").nextLine());
		});

		Arrays.stream(students)
		    .sorted(Comparator.comparing(Student::getId))
		    .forEach(System.out::println);

		stdin.close();
	}
}
