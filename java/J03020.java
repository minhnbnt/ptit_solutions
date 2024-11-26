import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

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

	public static void main(String[] args) {

		Map<String, Integer> wordMap = new LinkedHashMap<>();

		int maxLength = 0;

		try (Scanner stdin = new Scanner(System.in)) {
			while (stdin.hasNext()) {

				String word = stdin.next();

				if (!isPalindrome(word)) {
					continue;
				}

				if (word.length() == maxLength) {
					wordMap.merge(word, 1, Integer::sum);
				} else if (word.length() > maxLength) {

					maxLength = word.length();

					wordMap.clear();
					wordMap.put(word, 1);
				}
			}
		}

		wordMap.forEach((word, count) -> { //
			System.out.printf("%s %d%n", word, count);
		});
	}
}
