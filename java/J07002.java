import java.io.File;
import java.io.FileNotFoundException;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {

		File inputFile = new File("DATA.in");

		try (Scanner scanner = new Scanner(inputFile)) {

			long sum = 0;

			while (scanner.hasNext()) {

				int number;

				try {
					String s = scanner.next();
					number = Integer.parseInt(s);
				} catch (NumberFormatException e) {
					continue;
				}

				sum += number;
			}

			System.out.println(sum);
		}
	}
}
