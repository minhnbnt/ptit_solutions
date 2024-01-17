import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class DSA06047 {

	static final Scanner stdin = new Scanner(System.in);

	static boolean has3Pytago(List<Long> edges) {

		List<Long> transformed = edges.stream()
		                             .map((edge) -> edge * edge)
		                             .sorted((a, b) -> b.compareTo(a))
		                             .collect(Collectors.toList());

		for (int i = 0; i < transformed.size(); ++i) {

			final long hypo_edge = transformed.get(i);
			int left = i + 1, right = transformed.size() - 1;

			while (left < right) {

				final long sum = transformed.get(left) + transformed.get(right);

				if (sum > hypo_edge) {
					++left;
				} else if (sum < hypo_edge) {
					--right;
				} else {
					return true;
				}
			}
		}

		return false;
	}

	public static void main(String[] args) {

		int cases = stdin.nextInt();

		while (cases-- > 0) {

			int size = stdin.nextInt();
			List<Long> edges = new ArrayList<>(size);

			for (int i = 0; i < size; ++i) {
				edges.add(stdin.nextLong());
			}

			System.out.println(has3Pytago(edges) ? "YES" : "NO");
		}
	}
}
