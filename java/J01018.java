import java.util.Scanner;

public class J01018 {

	static int sumOfDigits(long n) {

		int sum = 0;

		for (; n > 0; n /= 10) {
			sum += (int)(n % 10);
		}

		return sum;
	}

	static boolean isValid(long n) {

		long tmp = n;
		byte prev = (byte)(tmp % 10);

		while ((tmp /= 10) > 0) {

			byte next = (byte)(tmp % 10);

			if (Math.abs(prev - next) != 2) {
				return false;
			}

			prev = next;
		}

		return sumOfDigits(n) % 10 == 0;
	}

	public static void main(String[] args) {
		try (Scanner stdin = new Scanner(System.in)) {

			int cases = stdin.nextInt();

			for (; cases > 0; cases--) {
				long n = stdin.nextLong();
				System.out.println(isValid(n) ? "YES" : "NO");
			}
		}
	}
}
