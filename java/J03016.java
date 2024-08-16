import java.math.BigInteger;
import java.util.Scanner;

public class J03016 {
	public static void main(String[] args) {
		try (Scanner stdin = new Scanner(System.in)) {

			for (int cases = stdin.nextInt(); cases > 0; cases--) {

				BigInteger number = stdin.nextBigInteger();

				boolean result = number //
				                     .mod(BigInteger.valueOf(11))
				                     .equals(BigInteger.ZERO);

				System.out.println(result ? 1 : 0);
			}
		}
	}
}
