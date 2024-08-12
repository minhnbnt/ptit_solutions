import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import java.util.TreeSet;

public class J07007 {
	public static void main(String[] args) throws IOException {

		File stream = new File("VANBAN.in");

		try (Scanner scanner = new Scanner(stream)) {

			TreeSet<String> tokens = new TreeSet<>();

			while (scanner.hasNext()) {
				tokens.add(scanner.next().toLowerCase());
			}

			for (String token : tokens) {
				System.out.println(token);
			}
		}
	}
}
