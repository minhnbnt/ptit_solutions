import java.util.ArrayDeque;
import java.util.Scanner;

public class DSA06048 {

	static final Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {

		int cases = stdin.nextInt();

		while (cases-- > 0) {

			int size = stdin.nextInt();

			ArrayDeque<Long> deque = new ArrayDeque<>(size);
			for (int i = 0; i < size; i++) {
				deque.add(stdin.nextLong());
			}

			int counter = 0;
			while (deque.getFirst() > deque.getLast()) {
				long value = deque.removeFirst();
				deque.addLast(value);
				++counter;
			}

			System.out.println(counter);
		}
	}
}
