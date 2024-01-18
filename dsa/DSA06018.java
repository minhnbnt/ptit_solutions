import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.stream.Collectors;

public class DSA01025 {

	static Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {

		int cases = stdin.nextInt();

		while (cases-- > 0) {

			int _size = stdin.nextInt();
			stdin.skip("\\s+");

			TreeSet<Integer> elements =
			    Arrays.stream(stdin.nextLine().split("\\s+"))
			        .mapToInt(Integer::parseInt)
			        .boxed()
			        .collect(Collectors.toCollection(TreeSet::new));

			int result = elements.last() - elements.first() -
			             elements.size() + 1;
			System.out.println(result);
		}
	}
}
