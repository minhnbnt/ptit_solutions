import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;

public class J07003 {
	public static void main(String[] args) throws FileNotFoundException {

		BigInteger number;
		try (Scanner scanner = new Scanner(new File("DATA.in"))) {
			number = scanner.nextBigInteger();
		}

		while (true) {

			String s = number.toString();
			int length = s.length();

			if (length == 1) {
				break;
			}

			int half = length >> 1;

			BigInteger left = new BigInteger(s.substring(0, half));
			BigInteger right = new BigInteger(s.substring(half));

			number = left.add(right);
			System.out.println(number);
		}
	}
}
