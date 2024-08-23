import java.util.Arrays;
import java.util.Scanner;

public class J01013 {

	static int[] genResults(int maxNumber) {

		int[] dp = new int[maxNumber + 1];
		Arrays.fill(dp, 0);

		for (int i = 2; i <= maxNumber; i++) {

			if (dp[i] != 0) {
				continue;
			}

			for (long gap = i; gap <= maxNumber; gap *= i) {
				for (long j = gap; j <= maxNumber; j += gap) {
					dp[(int)j] += i;
				}
			}
		}

		return dp;
	}

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int size = stdin.nextInt();
		int[] array = new int[size];

		for (int i = 0; i < size; i++) {
			array[i] = stdin.nextInt();
		}

		stdin.close();

		if (size == 0) {
			System.out.println(0);
			return;
		}

		int max = Arrays.stream(array).max().getAsInt();
		int[] results = genResults(max);

		long result = Arrays.stream(array)
		                  .mapToLong(n -> results[n])
		                  .reduce(0L, Long::sum);

		System.out.println(result);
	}
}
