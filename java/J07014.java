import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;
import java.util.stream.Collectors;

class WordSet {

	private final Set<String> wordSet;

	public WordSet(TreeSet<String> words) {
		this.wordSet = words;
	}

	public WordSet(String URI) throws IOException {

		File stream = new File(URI);

		Set<String> words = new TreeSet<>();

		try (Scanner sc = new Scanner(stream)) {
			while (sc.hasNext()) {
				words.add(sc.next().toLowerCase());
			}
		}

		this.wordSet = words;
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

public class J07014 {
	public static void main(String[] args) throws IOException {
		WordSet s1 = new WordSet("DATA1.in");
		WordSet s2 = new WordSet("DATA2.in");
		System.out.println(s1.union(s2));
		System.out.println(s1.intersection(s2));
	}
}
