import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class J08015 {

	static long countTwoSum(long[] array, long targetSum) {

		long result = 0;
		Map<Long, Integer> map = new HashMap<>();

		for (long element : array) {
			result += map.getOrDefault(targetSum - element, 0);
			map.merge(element, 1, Integer::sum);
		}

		return result;
	}

	public static void main(String[] args) {
		try (Scanner stdin = new Scanner(System.in)) {

			for (int cases = stdin.nextInt(); cases > 0; cases--) {

				int size = stdin.nextInt();
				long targetSum = stdin.nextLong();

				long[] array = new long[size];
				for (int i = 0; i < size; i++) {
					array[i] = stdin.nextLong();
				}

				System.out.println(countTwoSum(array, targetSum));
			}
		}
	}
}
