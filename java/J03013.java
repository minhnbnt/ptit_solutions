import java.math.BigInteger;
import java.util.Scanner;

public class J03013 {
	public static void main(String[] args) {
		try (Scanner stdin = new Scanner(System.in)) {

			for (int cases = stdin.nextInt(); cases > 0; cases--) {

				BigInteger x = stdin.nextBigInteger();
				BigInteger y = stdin.nextBigInteger();
				BigInteger result = x.subtract(y).abs();

				StringBuilder strBuilder = new StringBuilder(result.toString());
				int maxLen = x.max(y).toString().length();

				if (maxLen > strBuilder.length()) {
					strBuilder.insert(0, '0');
				}

				System.out.println(strBuilder);
			}
		}
	}
}
