import java.util.*;

class Student {

	private final String id, name, phoneNumber;

	Student(String id, String name, String phoneNumber) {
		this.phoneNumber = phoneNumber;
		this.name = name;
		this.id = id;
	}

	@Override
	public String toString() {
		return String.format("%s %s %s", id, name, phoneNumber);
	}
}

class Group {

	private final int id;
	private final List<Student> students;
	private String topic;

	Group(int id, List<Student> students, String topic) {
		this.id = id;
		this.students = students;
		this.topic = topic;
	}

	public int getId() {
		return id;
	}

	public List<Student> getStudents() {
		return students;
	}

	public String getTopic() {
		return topic;
	}

	public void setTopic(String topic) {
		this.topic = topic;
	}
}

public class J06003 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int numberOfStudent = stdin.nextInt();
		int numberOfGroup = stdin.nextInt();

		Map<Integer, Group> groupMap = new LinkedHashMap<>();

		for (int id = 1; id <= numberOfGroup; id++) {
			groupMap.put(id, new Group(id, new ArrayList<>(), null));
		}

		for (int i = 0; i < numberOfStudent; i++) {

			String id = stdin.next();
			String name = stdin.skip("\\s+").nextLine();
			String phoneNumber = stdin.next();

			int groupId = stdin.nextInt();

			groupMap.get(groupId).getStudents().add(
			    new Student(id, name, phoneNumber));
		}

		groupMap.forEach((id, group) -> { //
			group.setTopic(stdin.skip("\\s*").nextLine());
		});

		int numberOfQuery = stdin.nextInt();
		for (int i = 0; i < numberOfQuery; i++) {

			int groupId = stdin.nextInt();
			Group target = groupMap.get(groupId);

			System.out.printf("DANH SACH NHOM %d:%n", target.getId());
			target.getStudents().forEach(System.out::println);

			System.out.printf("Bai tap dang ky: %s%n", target.getTopic());
		}

		stdin.close();
	}
}
