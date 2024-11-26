import java.util.Scanner;

class Utils {

	static boolean isPrimeDigit(int c) {
		switch (c) {

		case '2':
		case '3':
		case '5':
		case '7':
			return true;

		default:
			return false;
		}
	}

	static boolean isPalindrome(String s) {

		char[] chars = s.toCharArray();
		int length = chars.length;

		for (int i = 0; i < length / 2; i++) {
			if (chars[i] != chars[length - i - 1]) {
				return false;
			}
		}

		return true;
	}
}

public class Main {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int cases = stdin.nextInt();

		for (int i = 0; i < cases; i++) {

			String number = stdin.next();

			boolean allIsPrimeDigits = number //
			                               .codePoints()
			                               .allMatch(Utils::isPrimeDigit);

			boolean result = Utils.isPalindrome(number) && allIsPrimeDigits;

			System.out.println(result ? "YES" : "NO");
		}
	}
}
