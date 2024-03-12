import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class DSA06047 {

	static boolean has3Pytago(List<Integer> edges) {

		final List<Long> squared = edges.stream()
		                               .map((edge) -> (long)edge * edge)
		                               .sorted(Comparator.naturalOrder())
		                               .collect(Collectors.toList());

		for (int i = 2; i < squared.size(); ++i) {

			int left = 0, right = i - 1;
			final long hypoSquared = squared.get(i);

			while (left < right) {

				final long sum = squared.get(left) + squared.get(right);

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
