import java.util.Scanner;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class DSA06022 {

	static final Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {

		int cases = stdin.nextInt();

		while (cases-- > 0) {

			final int size = stdin.nextInt();

			Set<Integer> numbers = IntStream.range(0, size)
			                           .map(i -> stdin.nextInt())
			                           .boxed()
			                           .collect(Collectors.toSet());

			if (numbers.size() == 1) {
				System.out.println(-1);
				continue;
			}

			numbers.stream()
			    .sorted(Integer::compare)
			    .limit(2)
			    .forEach(element -> System.out.print(element + " "));

			System.out.append('\n');
		}
	}
}
