import java.util.Scanner;
import java.util.Stack;

public class J08023 {

	static long maxRectangleArea(int[] heights) {

		Stack<Integer> stack = new Stack<>();
		Stack<Integer> indexes = new Stack<>();

		long maxArea = 0;

		for (int i = 0; i < heights.length; i++) {

			int currentIndex = i;

			while (!stack.empty()) {

				int height = stack.peek();
				if (height <= heights[i]) {
					break;
				}

				int index = indexes.pop();

				int width = i - index;
				long area = (long)width * height;

				maxArea = Math.max(area, maxArea);
				currentIndex = index;

				stack.pop();
			}

			indexes.push(currentIndex);
			stack.push(heights[i]);
		}

		while (!stack.empty()) {

			int width = heights.length - indexes.pop();
			long height = stack.pop();

			long area = height * width;

			maxArea = Math.max(maxArea, area);
		}

		return maxArea;
	}

	public static void main(String[] args) {

		try (Scanner stdin = new Scanner(System.in)) {

			int cases = stdin.nextInt();

			for (; cases > 0; cases--) {

				int size = stdin.nextInt();

				int[] heights = new int[size];
				for (int i = 0; i < size; i++) {
					heights[i] = stdin.nextInt();
				}

				System.out.println(maxRectangleArea(heights));
			}
		}
	}
}
