import java.math.BigInteger;
import java.util.Scanner;

public class J03011 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int cases = stdin.nextInt();

		for (int i = 0; i < cases; i++) {

			BigInteger a = stdin.nextBigInteger();
			BigInteger b = stdin.nextBigInteger();

			System.out.println(a.gcd(b));
		}

		stdin.close();
	}
}
