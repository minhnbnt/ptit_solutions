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

	public Ratio add(Ratio other) {

		long num = this.num * other.den + this.den * other.num;
		long den = this.den * other.den;

		return new Ratio(num, den);
	}
}

public class J04004 {
	public static void main(String[] args) {
		try (Scanner stdin = new Scanner(System.in)) {

			long num = stdin.nextLong();
			long den = stdin.nextLong();

			Ratio r1 = new Ratio(num, den);

			num = stdin.nextLong();
			den = stdin.nextLong();

			Ratio r2 = new Ratio(num, den);

			System.out.println(r1.add(r2));
		}
	}
}
