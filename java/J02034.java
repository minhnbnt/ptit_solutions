import java.util.Scanner;
import java.util.TreeSet;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.stream.IntStream;

public class J02034 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int size = stdin.nextInt();

		TreeSet<Integer> set = new TreeSet<>();
		for (int i = 0; i < size; i++) {
			set.add(stdin.nextInt());
		}

		int max = set.last();
		AtomicBoolean isFull = new AtomicBoolean(true);

		IntStream //
		    .range(1, max)
		    .filter(n -> !set.contains(n))
		    .forEach(n -> {
			    isFull.set(false);
			    System.out.println(n);
		    });

		if (isFull.get()) {
			System.out.println("Excellent!");
		}

		stdin.close();
	}
}
