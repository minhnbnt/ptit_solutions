import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		for (int cases = stdin.nextInt(); cases > 0; cases--) {

			int size = stdin.nextInt();

			Stack<Integer> stack = new Stack<>();
			Map<Integer, Integer> indexMap = new HashMap<>();

			for (int i = 0; i < size; i++) {

				int value = stdin.nextInt();

				while (!stack.empty() && stack.peek() <= value) {
					int popped = stack.pop();
					indexMap.remove(popped);
				}

				int result = i + 1;
				if (!stack.empty()) {
					result = i - indexMap.get(stack.peek());
				}

				System.out.printf("%d ", result);

				indexMap.put(value, i);
				stack.add(value);
			}

			System.out.printf("%n");
		}

		stdin.close();
	}
}
