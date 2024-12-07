import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import java.util.stream.Collectors;

class Subject {

	private final String id, name;
	private final int _token;

	Subject(String id, String name, int token) {
		this.id = id;
		this.name = name;
		this._token = token;
	}

	public String getName() {
		return name;
	}

	public String getId() {
		return id;
	}
}

class Student {

	private final String id, name, grade, _email;
	private final Map<Subject, Double> scores;

	Student(String id, String name, String grade, String email) {
		this.id = id;
		this.name = name;
		this.grade = grade;
		this._email = email;
		scores = new TreeMap<>(Comparator.comparing(Subject::getId));
	}

	public String getId() {
		return id;
	}

	public String getName() {
		return name;
	}

	public String getGrade() {
		return grade;
	}

	public Map<Subject, Double> getScores() {
		return scores;
	}
}

public class J07036 {

	static Map<String, Subject> getSubjectMap(Scanner scanner) {

		int size = scanner.nextInt();
		Map<String, Subject> subjectMap = new HashMap<>();

		for (int i = 0; i < size; i++) {

			String id = scanner.next();
			String name = scanner.skip("\\s+").nextLine();
			int token = scanner.nextInt();

			subjectMap.put(id, new Subject(id, name, token));
		}

		return subjectMap;
	}

	static Map<String, Student> getStudentMap(Scanner scanner) {

		int size = scanner.nextInt();
		Map<String, Student> studentMap = new HashMap<>();

		for (int i = 0; i < size; i++) {

			String id = scanner.next();
			String name = scanner.skip("\\s+").nextLine();
			name = Utils.titleString(name);
			String grade = scanner.next();
			String email = scanner.next();

			studentMap.put(id, new Student(id, name, grade, email));
		}

		return studentMap;
	}

	static void solve(Scanner scanner, Map<String, Subject> subjectMap,
	                  Map<String, Student> studentMap) {

		for (int queries = scanner.nextInt(); queries > 0; queries--) {

			String studentId = scanner.next();
			Student student = studentMap.get(studentId);

			String subjectId = scanner.next();
			Subject subject = subjectMap.get(subjectId);

			double score = scanner.nextDouble();
			student.getScores().put(subject, score);
		}

		Map<String, List<Student>> gradeMap = new HashMap<>();
		studentMap.forEach((id, student) -> {
			gradeMap
			    .computeIfAbsent(student.getGrade(), (k) -> new ArrayList<>())
			    .add(student);
		});

		for (int queries = scanner.nextInt(); queries > 0; queries--) {
			String grade = scanner.next();
			handleQuery(gradeMap, grade);
		}
	}

	static void handleQuery(Map<String, List<Student>> gradeMap, String grade) {

		Map<Subject, Map<Student, Double>> scores =
		    new TreeMap<>(Comparator.comparing(Subject::getId));

		for (Student s : gradeMap.get(grade)) {
			for (Map.Entry<Subject, Double> score : s.getScores().entrySet()) {

				Subject subject = score.getKey();
				double subjectScore = score.getValue();

				scores
				    .computeIfAbsent(
				        subject,
				        k
				        -> new TreeMap<>(Comparator.comparing(Student::getId)))
				    .put(s, subjectScore);
			}
		}

		System.out.printf("BANG DIEM lop %s:%n", grade);
		scores.forEach((subject, scoreMap) -> {
			scoreMap.forEach((student, score) -> {
				System.out.printf("%s %s %s %s %s%n", student.getId(),
				                  student.getName(), subject.getId(),
				                  subject.getName(), Utils.formatScore(score));
			});
		});
	}

	public static void main(String[] args) throws FileNotFoundException {

		Map<String, Subject> subjectMap;

		try (Scanner scanner = new Scanner(new File("MONHOC.in"))) {
			subjectMap = getSubjectMap(scanner);
		}

		Map<String, Student> studentMap;

		try (Scanner scanner = new Scanner(new File("SINHVIEN.in"))) {
			studentMap = getStudentMap(scanner);
		}

		try (Scanner scanner = new Scanner(new File("BANGDIEM.in"))) {
			solve(scanner, subjectMap, studentMap);
		}
	}
}

class Utils {

	static String formatScore(double score) {

		String format = "%s";
		if (score == (int)score) {
			format = "%.0f";
		}

		return String.format(format, score);
	}

	static String titleString(String s) {

		String[] tokens = s.trim().split("\\s+");
		if (tokens.length > 1) {
			return Arrays.stream(tokens)
			    .map(Utils::titleString)
			    .collect(Collectors.joining(" "));
		}

		char[] chars = tokens[0].toCharArray();
		for (int i = 0; i < chars.length; i++) {
			chars[i] = Character.toLowerCase(chars[i]);
		}

		chars[0] = Character.toUpperCase(chars[0]);

		return new String(chars);
	}
}
