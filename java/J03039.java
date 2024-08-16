import java.math.BigInteger;
import java.util.Scanner;

public class J03039 {
	public static void main(String[] args) {
		try (Scanner stdin = new Scanner(System.in)) {

			for (int cases = stdin.nextInt(); cases > 0; cases--) {

				BigInteger a = stdin.nextBigInteger(),
				           b = stdin.nextBigInteger();

				boolean result = a.mod(b).equals(BigInteger.ZERO) ||
				                 b.mod(a).equals(BigInteger.ZERO);

				System.out.println(result ? "YES" : "NO");
			}
		}
	}
}
