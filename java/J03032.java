import java.util.Scanner;

public class J03032 {
	public static void main(String[] args) {

		try (Scanner stdin = new Scanner(System.in)) {

			int cases = stdin.nextInt();
			stdin.skip("\\s+");

			for (; cases > 0; cases--) {

				String line = stdin.nextLine();

				for (String token : line.split("\\s+")) {

					StringBuilder builder = new StringBuilder(token);
					builder.reverse();

					System.out.printf("%s ", builder);
				}

				System.out.append("\n");
			}
		}
	}
}
