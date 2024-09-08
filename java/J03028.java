import java.nio.CharBuffer;
import java.util.Scanner;

public class J03028 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int cases = stdin.nextInt();
		for (int t = 0; t < cases; t++) {

			String input = stdin.next();
			String result = Solution.encodedString(input);

			System.out.println(result);
		}

		stdin.close();
	}
}

class Solution {

	private static int getCharIndex(int c) {
		return c - 'A';
	}

	private static char getCharByIndex(int index) {
		return (char)('A' + (index % 26));
	}

	private static int getRotateValue(char[] chars) {
		return CharBuffer.wrap(chars).chars().map(Solution::getCharIndex).sum();
	}

	private static void rotateChars(char[] chars) {

		int rotateValue = getRotateValue(chars);
		for (int i = 0; i < chars.length; i++) {
			int index = getCharIndex(chars[i]);
			chars[i] = getCharByIndex(index + rotateValue);
		}
	}

	private static String merge(char[] left, char[] right) {

		for (int i = 0; i < left.length; i++) {

			int index = getCharIndex(left[i]);
			int rotateValue = getCharIndex(right[i]);

			left[i] = getCharByIndex(index + rotateValue);
		}

		return new String(left);
	}

	public static String encodedString(String s) {

		assert s.length() % 2 == 0;

		int half = s.length() / 2;

		char[] left = s.substring(0, half).toCharArray();
		char[] right = s.substring(half).toCharArray();

		rotateChars(left);
		rotateChars(right);

		return merge(left, right);
	}
}
