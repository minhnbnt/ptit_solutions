import java.util.*;
import java.util.stream.Collectors;

class WordSet {

	private final Set<String> wordSet;

	public WordSet(TreeSet<String> words) {
		this.wordSet = words;
	}

	public WordSet(String line) {

		String[] tokens = line.toLowerCase().split("\\s+");

		wordSet = new TreeSet<>();
		Collections.addAll(wordSet, tokens);
	}

	public WordSet intersection(WordSet other) {

		// clang-format off
        TreeSet<String> result = wordSet.stream()
                .filter(other.wordSet::contains)
                .collect(Collectors.toCollection(TreeSet::new));

		// clang-format on
		return new WordSet(result);
	}

	public WordSet union(WordSet other) {

		TreeSet<String> result = new TreeSet<>(wordSet);
		result.addAll(other.wordSet);

		return new WordSet(result);
	}

	public String toString() {
		return String.join(" ", wordSet) + " ";
	}
}

public class J04022 {
	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);

		WordSet s1 = new WordSet(in.nextLine());
		WordSet s2 = new WordSet(in.nextLine());

		in.close();

		System.out.println(s1.union(s2));
		System.out.println(s1.intersection(s2));
	}
}
