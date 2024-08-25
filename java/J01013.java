import java.util.Arrays;
import java.util.Scanner;

class Generator {

	private final int[] results;

	public Generator(int maxNumber) {

		int[] dp = new int[maxNumber + 1];
		Arrays.fill(dp, 0);
		this.results = dp;

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
	}

	public int getResult(int n) {
		return results[n];
	}
}

public class J01013 {
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
		Generator generator = new Generator(max);

		long result = Arrays.stream(array)
		                  .mapToLong(generator::getResult)
		                  .reduce(0L, Long::sum);

		System.out.println(result);
	}
}
