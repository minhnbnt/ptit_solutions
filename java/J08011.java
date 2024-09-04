import java.util.Comparator;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

public class J08011 {

	public static void main(String[] args) {

		Map<Integer, Integer> counterMap = new LinkedHashMap<>();

		try (Scanner stdin = new Scanner(System.in);) {
			while (stdin.hasNext()) {

				int number = stdin.nextInt();
				if (!nonDecreasingNumber(number)) {
					continue;
				}

				counterMap.merge(number, 1, Integer::sum);
			}
		}

		counterMap.entrySet()
		    .stream()
		    .sorted(Comparator //
		                .comparingInt(Map.Entry<Integer, Integer>::getValue)
		                .reversed())
		    .forEach((entry) -> {
			    int number = entry.getKey();
			    int counter = entry.getValue();

			    System.out.printf("%d %d%n", number, counter);
		    });
	}

	static boolean nonDecreasingNumber(int n) {

		byte prev = (byte)(n % 10);
		while ((n /= 10) > 0) {

			byte next = (byte)(n % 10);

			if (next > prev) {
				return false;
			}

			prev = next;
		}

		return true;
	}
}
