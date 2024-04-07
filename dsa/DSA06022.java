import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class DSA06022 {
	public static void main(String[] args) {

		try (Scanner stdin = new Scanner(System.in)) {

			int cases = stdin.nextInt();

			for (; cases > 0; cases--) {

				final int size = stdin.nextInt();

				List<?> numbers = IntStream.range(0, size)
				                      .map(i -> stdin.nextInt())
				                      .distinct()
				                      .sorted()
				                      .limit(2)
				                      .boxed()
				                      .collect(Collectors.toList());

				if (numbers.size() < 2) {
					System.out.println(-1);
					continue;
				}

				numbers.forEach(x -> System.out.printf("%d ", x));
				System.out.append('\n');
			}
		}
	}
}
