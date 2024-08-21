import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Candidate {

	private final String id, name;
	private final Float[] scores;
	private boolean passed;

	public Candidate(String id, String name, Float[] scores) {
		this.scores = scores;
		this.name = name;
		this.id = id;
	}

	public void setPassed(boolean passed) {
		this.passed = passed;
	}

	public float getPriorPoint() {

		String area = this.id.substring(0, 3);

		switch (area) {
		case "KV1":
			return 0.5F;

		case "KV2":
			return 1.0F;

		case "KV3":
			return 2.5F;

		default:
			return 0F;
		}
	}

	public float getTotalScore() {

		float totalScore = Arrays.stream(scores).reduce(0F, Float::sum);
		totalScore += scores[0];

		return totalScore + getPriorPoint();
	}

	@Override
	public String toString() {

		String totalScore = Utils.formatFloat(getTotalScore());
		String priorScore = Utils.formatFloat(getPriorPoint());

		String status = this.passed ? "TRUNG TUYEN" : "TRUOT";

		return String.format("%s %s %s %s %s", //
		                     id, name, priorScore, totalScore, status);
	}
}

public class J05059 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int size = stdin.nextInt();

		Candidate[] candidates = new Candidate[size];

		for (int i = 0; i < size; i++) {

			String id = stdin.skip("\\s+").nextLine();
			String name = stdin.nextLine();

			Float[] score = new Float[3];

			for (int j = 0; j < 3; j++) {
				score[j] = stdin.nextFloat();
			}

			candidates[i] = new Candidate(id, name, score);
		}

		stdin.close();

		Arrays.sort(candidates,
		            Comparator.comparing(Candidate::getTotalScore).reversed());

		int numberOfPassed = stdin.nextInt();
		float minimumScore = 0;

		for (int i = 0; i < size; i++) {

			Candidate candidate = candidates[i];

			if (candidate.getTotalScore() == minimumScore) {
				candidate.setPassed(true);
				continue;
			}

			if (i >= numberOfPassed) {
				candidate.setPassed(false);
				continue;
			}

			candidate.setPassed(true);
			minimumScore = candidate.getTotalScore();
		}

		System.out.printf("%.1f%n", minimumScore);
		Arrays.stream(candidates).forEach(System.out::println);
	}
}

class Utils {
	public static String formatFloat(float n) {

		if (n == (float)Math.round(n)) {
			return String.format("%.0f", n);
		}

		return String.format("%.1f", n);
	}
}
