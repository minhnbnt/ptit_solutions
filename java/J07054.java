import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.stream.Collectors;

class Student {

	private final String id, name;
	private final float[] scores;
	private float avgScore = -1;

	Student(String id, String name, float[] scores) {
		this.id = id;
		this.name = name;
		this.scores = scores;
	}

	public String getId() {
		return id;
	}

	public float getAvgScore() {

		if (avgScore != -1) {
			return avgScore;
		}

		float totalScore = 0;
		for (float score : scores) {
			totalScore += score;
		}

		totalScore *= 2;
		for (int i = 0; i < Math.min(2, scores.length); i++) {
			totalScore += scores[i];
		}

		avgScore = totalScore / (scores.length * 2 + 2);

		return getAvgScore();
	}

	@Override
	public String toString() {
		return String.format("%s %s %.2f", id, name, getAvgScore());
	}
}

public class J07054 {

	public static void main(String[] args) throws FileNotFoundException {
		try (Scanner scanner = new Scanner(new File("BANGDIEM.in"))) {
			solve(scanner);
		}
	}

	static void solve(Scanner scanner) {

		int size = scanner.nextInt();

		Student[] students = new Student[size];
		for (int i = 0; i < size; i++) {

			String id = String.format("SV%02d", i + 1);

			String name = scanner.skip("\\s*").nextLine();
			name = Utils.titleString(name);

			float[] scores = new float[3];
			for (int j = 0; j < scores.length; j++) {
				scores[j] = scanner.nextFloat();
			}

			students[i] = new Student(id, name, scores);
		}

		Arrays.sort(students, Comparator.comparing(Student::getAvgScore)
		                          .reversed()
		                          .thenComparing(Student::getId));

		float prevScore = 0;
		int prevRank = 0;

		for (int i = 0; i < size; i++) {

			int rank = i + 1;

			if (students[i].getAvgScore() == prevScore) {
				rank = prevRank;
			}

			prevRank = rank;
			prevScore = students[i].getAvgScore();

			System.out.printf("%s %d%n", students[i], rank);
		}
	}
}

class Utils {
	static String titleString(String s) {

		s = s.trim();
		String[] tokens = s.split("\\s+");

		if (tokens.length > 1) {
			return Arrays.stream(tokens)
			    .map(Utils::titleString)
			    .collect(Collectors.joining(" "));
		}

		char[] chars = s.toCharArray();
		for (int i = 0; i < chars.length; i++) {
			chars[i] = Character.toLowerCase(chars[i]);
		}

		chars[0] = Character.toUpperCase(chars[0]);

		return new String(chars);
	}
}
