import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Candidate {

	private final int position;
	private final String id, name, grade, email, corp;

	public Candidate(int position, String id, String name, String grade,
	                 String email, String corp) {
		this.position = position;
		this.grade = grade;
		this.email = email;
		this.name = name;
		this.corp = corp;
		this.id = id;
	}

	@Override
	public String toString() {
		return String.format("%d %s %s %s %s %s", //
		                     position, id, name, grade, email, corp);
	}

	public String getName() {
		return this.name;
	}

	public String getCorp() {
		return this.corp;
	}
}

public class J05034 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int size = stdin.nextInt();
		stdin.skip("\\s+");

		List<Candidate> candidates = new ArrayList<>(size);

		for (int i = 1; i <= size; i++) {

			String id = stdin.nextLine();
			String name = stdin.nextLine();
			String grade = stdin.nextLine();
			String email = stdin.nextLine();
			String corp = stdin.nextLine();

			candidates.add(new Candidate(i, id, name, grade, email, corp));
		}

		candidates.sort(Comparator.comparing(Candidate::getName));

		stdin.skip("\\s+");

		for (int queries = stdin.nextInt(); queries > 0; queries--) {

			String corp = stdin.nextLine();

			candidates.stream()
			    .filter(c -> c.getCorp().equals(corp))
			    .forEach(System.out::println);
		}

		stdin.close();
	}
}
