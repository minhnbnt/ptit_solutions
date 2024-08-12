import java.util.Scanner;

public class J01007 {

	public static boolean isFibonacci(long n) {

		long fib1 = 0, fib2 = 1;

		while (fib1 < n) {
			long tmp = fib1;
			fib1 = fib2;
			fib2 += tmp;
		}

		return fib1 == n;
	}

	public static void main(String[] args) {

		try (Scanner stdin = new Scanner(System.in);) {

			for (int cases = stdin.nextInt(); cases > 0; cases--) {
				long n = stdin.nextLong();
				System.out.println(isFibonacci(n) ? "YES" : "NO");
			}
		}
	}
}
