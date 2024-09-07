import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.TreeSet;
import java.util.stream.Collectors;
import java.util.stream.Stream;

class WordSet {

	TreeSet<String> wordSet;

	public WordSet() {
		wordSet = new TreeSet<>();
	}

	public WordSet(TreeSet<String> set) {
		this.wordSet = set;
	}

	public WordSet(String URI) throws IOException {

		this();

		Path path = Paths.get(URI);
		try (Stream<String> lines = Files.lines(path)) {
			lines.map(line -> line.toLowerCase().split("\\s+"))
			    .flatMap(Arrays::stream)
			    .forEachOrdered(wordSet::add);
		}
	}

	public WordSet difference(WordSet other) {

		// clang-format off
		TreeSet<String> set = this.wordSet.stream()
		        .filter(word -> !other.wordSet.contains(word))
		        .collect(Collectors.toCollection(TreeSet::new));

		// clang-format on
		return new WordSet(set);
	}

	@Override
	public String toString() {
		return String.join(" ", this.wordSet) + " ";
	}
}

public class J07024 {
	public static void main(String[] args) throws IOException {

		WordSet s1 = new WordSet("DATA1.in");
		WordSet s2 = new WordSet("DATA2.in");

		System.out.println(s1.difference(s2));
		System.out.println(s2.difference(s1));
	}
}
