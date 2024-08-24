import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class J07040 {

	@SuppressWarnings("unchecked")
	static Set<String> getWordsInListObject()

	    throws IOException, ClassNotFoundException {

		FileInputStream fileStream = new FileInputStream("NHIPHAN.in");
		ObjectInputStream objectStream = new ObjectInputStream(fileStream);

		try {

			Object stringList = objectStream.readObject();

			return ((List<String>)stringList)
			    .stream()
			    .map(s -> s.toLowerCase().split("\\s+"))
			    .flatMap(Arrays::stream)
			    .collect(Collectors.toSet());

		} finally {
			objectStream.close();
		}
	}

	public static void main(String[] args) throws Exception {

		Set<String> wordInObject = getWordsInListObject();

		Path path = Paths.get("VANBAN.in");

		try (Stream<String> lines = Files.lines(path)) {
			lines.map(line -> line.toLowerCase().split("\\s+"))
			    .flatMap(Arrays::stream)
			    .filter(wordInObject::contains)
			    .distinct()
			    .forEach(System.out::println);
		}
	}
}
