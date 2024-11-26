import java.io.IOException;
import java.util.Stack;

public class Main {
	public static void main(String[] args) throws IOException {

		Stack<Character> left = new Stack<>();
		Stack<Character> right = new Stack<>();

		while (true) {

			int c = System.in.read();
			if (c == -1 || c == '\n') {
				break;
			}

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
				left.push((char)c);
			}
		}

		while (!right.empty()) {
			left.push(right.pop());
		}

		left.forEach(System.out::append);
	}
}
