import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Map<String, Integer> map = new LinkedHashMap<>();

		try (Scanner stdin = new Scanner(System.in)) {
			while (stdin.hasNext()) {
				map.merge(stdin.next(), 1, Integer::sum);
			}
		}

		int maxLength = map.keySet()
		                    .stream()
		                    .filter(Utils::isPalindrome)
		                    .mapToInt(String::length)
		                    .max()
		                    .orElse(Integer.MIN_VALUE);

		map.entrySet()
		    .stream()
		    .filter(entry -> Utils.isPalindrome(entry.getKey()))
		    .filter(entry -> entry.getKey().length() == maxLength)
		    .forEach(entry -> {
			    int count = entry.getValue();
			    String token = entry.getKey();

			    System.out.printf("%s %d%n", token, count);
		    });
	}
}

class Utils {
	static boolean isPalindrome(String s) {

		char[] chars = s.toCharArray();

		for (int i = 0; i <= chars.length / 2; i++) {
			if (chars[i] != chars[chars.length - i - 1]) {
				return false;
			}
		}

		return true;
	}
}
