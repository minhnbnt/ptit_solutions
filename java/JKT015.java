import java.util.Scanner;
import java.util.Stack;

public class JKT015 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		String input = stdin.nextLine();
		stdin.close();

		Stack<Integer> left = new Stack<>();
		Stack<Integer> right = new Stack<>();

		input.codePoints().forEach(c -> {
			switch (c) {
			case '<':
				if (!left.empty()) {
					right.push(left.pop());
				}
				break;

			case '>':
				if (!right.empty()) {
					left.push(right.pop());
				}
				break;

			case '-':
				if (!left.empty()) {
					left.pop();
				}
				break;

			default:
				left.push(c);
			}
		});

		while (!right.empty()) {
			left.push(right.pop());
		}

		left.forEach(c -> System.out.printf("%c", c));
	}
}
