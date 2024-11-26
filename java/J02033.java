import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int size = stdin.nextInt();
		int convertAttempt = stdin.nextInt();

		Queue<Long> queue = new PriorityQueue<>();
		while (queue.size() < size) {
			queue.add(stdin.nextLong());
		}

		for (int i = 0; i < convertAttempt; i++) {
			long smallest = queue.remove();
			queue.add(-smallest);
		}

		long result = queue.stream().reduce(0L, Long::sum);
		System.out.println(result);
	}
}
