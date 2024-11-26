import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int cases = stdin.nextInt();

		for (int i = 0; i < cases; i++) {

			int size = stdin.nextInt();

			int[] array = new int[size];
			for (int j = 0; j < size; j++) {
				array[j] = stdin.nextInt();
			}

			Stack<Integer> stack = new Stack<>();

			for (int j = size - 1; j >= 0; j--) {

				int current = array[j];

				while (!stack.empty()) {

					if (stack.peek() > current) {
						break;
					}

					stack.pop();
				}

				array[j] = stack.isEmpty() ? -1 : stack.peek();
				stack.push(current);
			}

			for (int result : array) {
				System.out.printf("%d ", result);
			}

			System.out.printf("%n");
		}
	}
}
