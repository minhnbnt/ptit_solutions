import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class J07022 {
	public static void main(String[] args) throws FileNotFoundException {

		File file = new File("DATA.in");

		List<String> invalidTokens = new ArrayList<>();

		try (Scanner scanner = new Scanner(file)) {

			while (scanner.hasNext()) {

				String token = scanner.next();

				try {
					Integer.parseInt(token);
				} catch (NumberFormatException e) {
					invalidTokens.add(token);
				}
			}
		}

		invalidTokens //
		    .stream()
		    .sorted()
		    .forEach(token -> System.out.printf("%s ", token));
	}
}
