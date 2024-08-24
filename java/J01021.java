import java.util.Scanner;

public class J01021 {

	static int MOD = (int)1e9 + 7;

	static long binPow(long base, long exponent) {

		if (exponent == 0) {
			return 1;
		}

		if (exponent % 2 == 0) {
			long squareRooted = binPow(base, exponent / 2);
			return squareRooted * squareRooted % MOD;
		}

		return base * binPow(base, exponent - 1) % MOD;
	}

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		long base, exponent;
		while (true) {

			base = stdin.nextLong();
			exponent = stdin.nextLong();

			if (base == 0 && exponent == 0) {
				break;
			}

			System.out.println(binPow(base, exponent));
		}

		stdin.close();
	}
}
