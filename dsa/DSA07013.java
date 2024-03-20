import static java.lang.Character.isDigit;

import java.util.Optional;
import java.util.Scanner;
import java.util.Stack;

public class DSA07013 {

	static Optional<Integer> calculate(int a, int b, char operation) {

		switch (operation) {
		case '+':
			return Optional.of(a + b);
		case '-':
			return Optional.of(a - b);
		case '*':
			return Optional.of(a * b);
		case '/':
			return Optional.of(a / b);
		default:
			return Optional.empty();
		}
	}

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int cases = stdin.nextInt();
		stdin.skip("\\s+");

		while (cases-- > 0) {

			String input = stdin.nextLine();

			Stack<Integer> pending = new Stack<>();

			for (char c : input.toCharArray()) {

				if (isDigit(c)) {
					pending.push(c - '0');
					continue;
				}

				final int a = pending.pop();
				final int b = pending.pop();

				calculate(b, a, c).ifPresent(pending::push);
			}

			System.out.println(pending.peek());
		}

		stdin.close();
	}
}
