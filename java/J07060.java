import java.io.File;
import java.io.FileNotFoundException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

class Utils {

	static SimpleDateFormat dateFormat =
	    new SimpleDateFormat("dd/MM/yyyy HH:mm");
}

class Subject {

	private final String name, _method;

	Subject(String name, String method) {
		this.name = name;
		_method = method;
	}

	public String getName() {
		return name;
	}
}

class Exam {

	private final Date time;
	private final String room;

	Exam(Date time, String room) {
		this.time = time;
		this.room = room;
	}

	public Date getTime() {
		return time;
	}

	public String getRoom() {
		return room;
	}
}

class ExamCalendar {

	private final Exam exam;
	private final Subject subject;
	private final int group, candidate;

	ExamCalendar(Subject subject, Exam exam, int group, int candidate) {
		this.subject = subject;
		this.exam = exam;
		this.group = group;
		this.candidate = candidate;
	}

	public Exam getExam() {
		return exam;
	}

	@Override
	public String toString() {

		return String.format(                        //
		    "%s %s %s %02d %d",                      //
		    Utils.dateFormat.format(exam.getTime()), //
		    exam.getRoom(),                          //
		    subject.getName(),                       //
		    group,                                   //
		    candidate                                //
		);
	}
}

public class J07060 {

	static Map<String, Subject> getSubjectMap(Scanner scanner) {

		int size = scanner.nextInt();

		Map<String, Subject> subjectMap = new HashMap<>();
		for (int i = 0; i < size; i++) {

			String id = scanner.next();
			String name = scanner.skip("\\s*").nextLine();
			String method = scanner.nextLine();

			subjectMap.put(id, new Subject(name, method));
		}

		return subjectMap;
	}

	static Map<String, Exam> getExamMap(Scanner scanner) {

		int size = scanner.nextInt();

		Map<String, Exam> examMap = new HashMap<>();
		for (int i = 0; i < size; i++) {

			String id = String.format("C%03d", i + 1);

			String date = scanner.next();
			String time = scanner.next();

			Date dateTime;
			try {
				dateTime = Utils.dateFormat.parse(date + " " + time);
			} catch (ParseException e) {
				throw new RuntimeException(e);
			}

			String room = scanner.next();

			examMap.put(id, new Exam(dateTime, room));
		}

		return examMap;
	}

	public static void main(String[] args) throws FileNotFoundException {

		Map<String, Subject> subjectMap;
		try (Scanner scanner = new Scanner(new File("MONTHI.in"))) {
			subjectMap = getSubjectMap(scanner);
		}

		Map<String, Exam> examMap;
		try (Scanner scanner = new Scanner(new File("CATHI.in"))) {
			examMap = getExamMap(scanner);
		}

		try (Scanner scanner = new Scanner(new File("LICHTHI.in"))) {
			solve(scanner, subjectMap, examMap);
		}
	}

	private static void solve(           //
	    Scanner scanner,                 //
	    Map<String, Subject> subjectMap, //
	    Map<String, Exam> examMap        //
	) {

		int size = scanner.nextInt();

		ExamCalendar[] examCalendars = new ExamCalendar[size];
		for (int i = 0; i < size; i++) {

			String examId = scanner.next();
			Exam exam = examMap.get(examId);

			String subjectId = scanner.next();
			;
			Subject subject = subjectMap.get(subjectId);

			int group = scanner.nextInt();
			int candidates = scanner.nextInt();

			examCalendars[i] =
			    new ExamCalendar(subject, exam, group, candidates);
		}

		Arrays.stream(examCalendars)
		    .sorted(
		        Comparator.comparing(calendar -> calendar.getExam().getTime()))
		    .forEach(System.out::println);
	}
}
