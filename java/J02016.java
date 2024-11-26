import java.util.Arrays;
import java.util.Scanner;

public class Main {

	static boolean containsTriplePytago(long[] array) {

		Arrays.sort(array);
		for (int i = 0; i < array.length; i++) {
			array[i] *= array[i];
		}

		for (int i = 2; i < array.length; i++) {

			int left = 0, right = i - 1;

			while (left < right) {

				long sum = array[left] + array[right];

				switch (Long.signum(sum - array[i])) {

				case -1:
					left++;
					continue;

				case 1:
					right--;
					continue;

				default:
					return true;
				}
			}
		}

		return false;
	}

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int cases = stdin.nextInt();

		for (int i = 0; i < cases; i++) {

			int size = stdin.nextInt();

			long[] array = new long[size];
			for (int j = 0; j < size; j++) {
				array[j] = stdin.nextLong();
			}

			boolean result = containsTriplePytago(array);
			System.out.println(result ? "YES" : "NO");
		}
	}
}
