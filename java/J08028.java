import java.util.Scanner;
import java.util.Stack;

public class J08028 {

	static long maxRectangleArea(int[] heights) {

		Stack<Integer> stack = new Stack<>();
		Stack<Integer> indexes = new Stack<>();

		long maxArea = 0;
		for (int i = 0; i < heights.length; i++) {

			int currentIndex = i;
			while (!indexes.empty()) {

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

			int height = stdin.nextInt();
			int size = stdin.nextInt();

			if (size == 0) return;

			int[] heights = new int[size];
			for (int i = 0; i < size; i++) {
				heights[i] = stdin.nextInt();
			}

			long result = maxRectangleArea(heights);

			for (int i = 0; i < size; i++) {
				heights[i] = height - heights[i];
			}

			result = Math.max(result, maxRectangleArea(heights));
			System.out.println(result);
		}
	}
}
