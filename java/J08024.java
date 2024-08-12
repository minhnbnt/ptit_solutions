import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class J08024 {

	static final Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {
		for (int cases = stdin.nextInt(); cases > 0; cases--) {

			int target = stdin.nextInt();

			Queue<Integer> queue = new ArrayDeque<>();
			queue.add(9);

			while (true) {

				int top = queue.remove();
				if (top % target == 0) {
					System.out.println(top);
					break;
				}

				queue.add(top * 10);
				queue.add(top * 10 + 9);
			}
		}
	}
}
