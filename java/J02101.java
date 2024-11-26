import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {

	static void reverse(int[] array) {

		int left = 0, right = array.length - 1;

		while (left < right) {

			int tmp = array[left];
			array[left] = array[right];
			array[right] = tmp;

			left++;
			right--;
		}
	}

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int cases = stdin.nextInt();
		for (; cases > 0; cases--) {

			int rank = stdin.nextInt();

			for (int i = 0; i < rank; i++) {

				int[] array = IntStream.range(0, rank)
				                  .map(j -> stdin.nextInt())
				                  .toArray();

				if (i % 2 == 1) {
					reverse(array);
				}

				for (int element : array) {
					System.out.printf("%d ", element);
				}
			}

			System.out.println();
		}
	}
}
