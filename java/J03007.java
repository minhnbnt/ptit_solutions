import java.util.Scanner;

public class J03007 {

	static boolean isBeautiful(String number) {

		int sumOfDigits = number.codePoints()
		                      .map(digit -> digit - '0')
		                      .reduce(0, Integer::sum);

		if (sumOfDigits % 10 != 0) {
			return false;
		}

		int length = number.length();

		int firstChar = number.codePointAt(0);
		int lastChar = number.codePointAt(length - 1);

		return firstChar == '8' && lastChar == '8';
	}

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		for (int cases = stdin.nextInt(); cases > 0; cases--) {
			String number = stdin.next();
			System.out.println(isBeautiful(number) ? "YES" : "NO");
		}

		stdin.close();
	}
}
