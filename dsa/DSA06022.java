import java.util.Arrays;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;
import java.util.stream.Collectors;

public class DSA06022 {

	static final Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {

		int cases = stdin.nextInt();

		while (cases-- > 0) {

			int _size = stdin.nextInt();
			stdin.skip("\\s+");

			Set<Integer> numbers = Arrays.stream(stdin.nextLine().split("\\s+"))
			                           .parallel()
			                           .mapToInt(Integer::parseInt)
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
