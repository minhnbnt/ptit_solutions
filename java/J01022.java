import java.util.Scanner;

public class J01022 {

	static char digitAt(int nth, long index) {

		if (nth == 1) {
			return '0';
		}

		if (nth == 2) {
			return '1';
		}

		long leftLength = fibonacci(nth - 2);
		if (index < leftLength) {
			return digitAt(nth - 2, index);
		}

		return digitAt(nth - 1, index - leftLength);
	}

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		for (int t = stdin.nextInt(); t > 0; t--) {

			int nth = stdin.nextInt();
			long index = stdin.nextLong();

			System.out.println(digitAt(nth, index - 1));
		}

		stdin.close();
	}

	static long fibonacci(int nth) {

		long fib1 = 0, fib2 = 1;

		for (int i = 0; i < nth; i++) {
			long tmp = fib1;
			fib1 = fib2;
			fib2 += tmp;
		}

		return fib1;
	}
}
