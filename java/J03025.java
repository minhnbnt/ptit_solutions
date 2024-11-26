import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

	static boolean isValid(String s) {

		char[] chars = s.toCharArray();
		int diff = 0, left = 0, right = chars.length - 1;

		while (left < right) {

			if (chars[left] != chars[right]) {
				diff++;
			}

			if (diff > 1) {
				return false;
			}

			right -= 1;
			left += 1;
		}

		return chars.length % 2 == 1 || diff == 1;
	}

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int cases = stdin.nextInt();
		stdin.skip("\\s+");

		for (; cases > 0; cases--) {

			String input = stdin.nextLine();
			System.out.println(isValid(input) ? "YES" : "NO");
		}
	}
}
