import java.util.Scanner;

public class J03024 {

	static boolean isValid(String s) {

		if (s.startsWith("0")) {
			return false;
		}

		return s.codePoints().allMatch(Character::isDigit);
	}

	static boolean isAdvantageNumber(String s) {

		int length = s.length();

		int evenDigitCount = (int)s //
		                         .codePoints()
		                         .filter(digit -> digit % 2 == 0)
		                         .count();

		int oddDigitCount = length - evenDigitCount;

		if (length % 2 == 0) {
			return evenDigitCount > oddDigitCount;
		} else {
			return evenDigitCount < oddDigitCount;
		}
	}

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int cases = stdin.nextInt();
		for (int t = 0; t < cases; t++) {

			String input = stdin.next();
			if (!isValid(input)) {
				System.out.println("INVALID");
				continue;
			}

			boolean result = isAdvantageNumber(input);
			System.out.println(result ? "YES" : "NO");
		}

		stdin.close();
	}
}
