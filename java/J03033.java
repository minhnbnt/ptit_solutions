import java.math.BigInteger;
import java.util.Scanner;

public class J03033 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int cases = stdin.nextInt();

		for (int i = 0; i < cases; i++) {

			BigInteger a = stdin.nextBigInteger();
			BigInteger b = stdin.nextBigInteger();

			BigInteger gcd = a.gcd(b);
			BigInteger lcm = a.multiply(b).divide(gcd);

			System.out.println(lcm);
		}

		stdin.close();
	}
}
