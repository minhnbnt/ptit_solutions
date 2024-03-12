import java.util.Scanner;
import java.util.TreeSet;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class DSA06018 {

	static Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {

		int cases = stdin.nextInt();

		while (cases-- > 0) {

			final int size = stdin.nextInt();

			TreeSet<Integer> set =
			    IntStream.range(0, size)
			        .map(i -> stdin.nextInt())
			        .boxed()
			        .collect(Collectors.toCollection(TreeSet::new));

			final int result = set.last() - set.first() - set.size() + 1;
			System.out.println(result);
		}
	}
}
