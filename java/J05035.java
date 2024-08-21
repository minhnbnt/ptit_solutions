import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

class Candidate {

	private final int position;
	private final String id, name, grade, email, corp;

	public Candidate(int position, String id, String name, //
	                 String grade, String email, String corp) {
		this.position = position;
		this.id = id;
		this.name = name;
		this.grade = grade;
		this.email = email;
		this.corp = corp;
	}

	@Override
	public String toString() {
		return String.format("%d %s %s %s %s %s", //
		                     position, id, name, grade, email, corp);
	}

	public String getCorp() {
		return this.corp;
	}

	public String getId() {
		return this.id;
	}
}

public class J05035 {

	static Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {

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

		candidates.sort(Comparator.comparing(Candidate::getId));

		int queries = stdin.nextInt();
		stdin.skip("\\s+");

		for (; queries > 0; queries--) {

			String corp = stdin.nextLine();

			candidates.stream()
			    .filter(c -> c.getCorp().equals(corp))
			    .forEach(System.out::println);
		}
	}
}
