import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;

public class J07021 {
	public static void main(String[] args) throws IOException {

		File file = new File("DATA.in");

		try (Scanner scanner = new Scanner(file)) {
			while (true) {

				String line = scanner.nextLine();
				if (line.equals("END")) {
					break;
				}

				String titled = Utils.titleString(line);
				System.out.println(titled);
			}
		}
	}
}

class Utils {
	static String titleString(String s) {

		String[] tokens = s.trim().split("\\s+");

		if (tokens.length > 1) {
			return Arrays.stream(tokens)
			    .map(Utils::titleString)
			    .collect(Collectors.joining(" "));
		}

		char[] chars = tokens[0].toCharArray();
		for (int i = 0; i < chars.length; i++) {
			chars[i] = Character.toLowerCase(chars[i]);
		}

		chars[0] = Character.toUpperCase(chars[0]);
		return new String(chars);
	}
}
