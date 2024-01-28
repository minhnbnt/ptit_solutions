import java.util.LinkedHashSet;
import java.util.Scanner;
import java.util.Set;

class Generator {

	static final Set<Integer> set = new LinkedHashSet<>();

	public static void all_primutation(int size) {

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

			all_primutation(size);

			set.remove(i);
		}
	}
}

public class Solution {

	static final java.util.Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {

		int cases = stdin.nextInt();
		while (cases-- > 0) {

			int size = stdin.nextInt();

			Generator.all_primutation(size);
			System.out.append('\n');
		}
	}
}
