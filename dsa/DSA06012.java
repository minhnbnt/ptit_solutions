import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class DSA06012 {

	static final Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {

		int cases = stdin.nextInt();

		while (cases-- > 0) {

			int __size = stdin.nextInt();
			int take = stdin.nextInt();

			stdin.skip("\\s+");

			String[] tokens = stdin.nextLine().split("\\s+");

			List<Integer> array = Arrays.stream(tokens)
			                          .mapToInt(Integer::parseInt)
			                          .boxed()
			                          .collect(Collectors.toList());

			array.stream()
			    .sorted((a, b) -> b - a)
			    .limit(take)
			    .forEach((x) -> System.out.printf("%d ", x));

			System.out.append('\n');
		}
	}
}
