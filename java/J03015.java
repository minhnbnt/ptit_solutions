import java.math.BigInteger;
import java.util.Scanner;

public class J03015 {
	public static void main(String[] args) {
		try (Scanner stdin = new Scanner(System.in)) {

			BigInteger x = stdin.nextBigInteger();
			BigInteger y = stdin.nextBigInteger();

			System.out.println(x.subtract(y));
		}
	}
}
