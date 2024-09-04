import java.util.Scanner;
import java.util.Stack;

public class J03027 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		String input = stdin.nextLine();
		stdin.close();

		Stack<Character> stack = new Stack<>();
		for (char c : input.toCharArray()) {

			if (stack.empty()) {
				stack.push(c);
				continue;
			}

			if (stack.peek() == c) {
				stack.pop();
				continue;
			}

			stack.push(c);
		}

		if (stack.empty()) {
			System.out.print("Empty String");
			return;
		}

		stack.forEach(System.out::print);
	}
}
