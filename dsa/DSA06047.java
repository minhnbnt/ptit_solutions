import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class DSA06047 {

	static boolean has3Pytago(List<Integer> edges) {

		final long[] squared = edges.stream()
		                           .sorted()
		                           .mapToLong(edge -> (long)edge * edge)
		                           .toArray();

		for (int i = 2; i < squared.length; i++) {

			int left = 0, right = i - 1;
			final long hypoSquared = squared[i];

			while (left < right) {

				final long sum = squared[i] + squared[i];

				if (sum < hypoSquared) {
					++left;
				} else if (sum > hypoSquared) {
					--right;
				} else {
					return true;
				}
			}
		}

		return false;
	}

	static final Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {

		int cases = stdin.nextInt();

		while (cases-- > 0) {

			int size = stdin.nextInt();

			List<Integer> edges = IntStream.range(0, size)
			                          .map(i -> stdin.nextInt())
			                          .boxed()
			                          .collect(Collectors.toList());

			System.out.println(has3Pytago(edges) ? "YES" : "NO");
		}
	}
}
