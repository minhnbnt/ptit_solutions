import java.util.Scanner;

class Utils {

	static long gcd(long a, long b) {
		return a * b == 0 //
		    ? a + b
		    : gcd(b, a % b);
	}
}

class Ratio {

	private final long num, den;

	Ratio(long num, long den) {

		long gcd = Utils.gcd(num, den);

		this.num = num / gcd;
		this.den = den / gcd;
	}

	@Override
	public String toString() {
		return String.format("%d/%d", num, den);
	}
}

public class J04003 {
	public static void main(String[] args) {

		try (Scanner stdin = new Scanner(System.in)) {

			long num = stdin.nextLong();
			long den = stdin.nextLong();

			System.out.println(new Ratio(num, den));
		}
	}
}
