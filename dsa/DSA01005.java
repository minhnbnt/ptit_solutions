import java.util.LinkedHashSet;
import java.util.Scanner;
import java.util.Set;

class Generator {

	static final Set<Integer> set = new LinkedHashSet<>();

	public static void allPermutation(int size) {

		if (set.size() == size) {

			for (int element : set) {
				System.out.print(element);
			}

			System.out.append(' ');
			return;
		}

		for (int i = 1; i <= size; i++) {

			if (set.contains(i)) {
				continue;
			}

			set.add(i);

			allPermutation(size);

			set.remove(i);
		}
	}
}

public class DSA01005 {

	static final Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {

		int cases = stdin.nextInt();

		while (cases-- > 0) {

			final int size = stdin.nextInt();

			Generator.allPermutation(size);
			System.out.append('\n');
		}
	}
}
