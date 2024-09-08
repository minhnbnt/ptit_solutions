import java.util.Arrays;
import java.util.Scanner;
import java.util.function.IntFunction;

public class J02027 {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int cases = stdin.nextInt();
		for (int t = 0; t < cases; t++) {

			int size = stdin.nextInt();
			int diff = stdin.nextInt();

			int[] array = new int[size];
			for (int i = 0; i < size; i++) {
				array[i] = stdin.nextInt();
			}

			Arrays.sort(array);

			long result = 0;
			for (int i = 0; i < size; i++) {

				int elem = array[i];
				int index = search(i, (j) -> { //
					return array[j] > elem - diff;
				});

				result += i - index;
			}

			System.out.println(result);
		}

		stdin.close();
	}

	static int search(int length, IntFunction<Boolean> func) {

		/*
		 * I love golang <3
		 * https://pkg.go.dev/sort#Search
		 */

		int left = 0, right = length;
		while (left < right) {

			int mid = (left + right) / 2;
			if (!func.apply(mid)) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}

		return left;
	}
}
