import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class J02022 {

	static void printValidNumbers(int numberLength) {

		Queue<String> queue = new LinkedList<>();
		for (int j = 1; j <= numberLength; j++) {
			queue.add(String.valueOf(j));
		}

		while (!queue.isEmpty()) {

			String current = queue.poll();

			int length = current.length();
			if (length == numberLength) {
				System.out.println(current);
				continue;
			}

			int lastDigit = current.codePointAt(length - 1);

			for (int j = 1; j <= numberLength; j++) {

				int digit = j + '0';

				if (Math.abs(digit - lastDigit) <= 1) {
					continue;
				}

				if (current.indexOf(digit) >= 0) {
					continue;
				}

				queue.add(current + j);
			}
		}

		System.out.println();
	}

	public static void main(String[] args) {
		try (Scanner stdin = new Scanner(System.in)) {

			int cases = stdin.nextInt();

			for (int i = 0; i < cases; i++) {
				int numberLength = stdin.nextInt();
				printValidNumbers(numberLength);
			}
		}
	}
}
