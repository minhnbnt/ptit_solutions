import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class J02028 {

	static boolean hasSubWithSum(int[] array, long targetSum) {

		Set<Long> sums = new HashSet<>();
		sums.add(0L);

		long accumulator = 0;
		for (int elem : array) {

			accumulator += elem;

			if (sums.contains(accumulator - targetSum)) {
				return true;
			}

			sums.add(accumulator);
		}

		return false;
	}

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int cases = stdin.nextInt();
		for (int i = 0; i < cases; i++) {

			int size = stdin.nextInt();
			long targetSum = stdin.nextLong();

			int[] array = new int[size];
			for (int j = 0; j < size; j++) {
				array[j] = stdin.nextInt();
			}

			boolean result = hasSubWithSum(array, targetSum);
			System.out.println(result ? "YES" : "NO");
		}
	}
}
