import java.util.Scanner;

public class J01017 {

	static boolean isValid(long n) {

		byte prev = (byte)(n % 10);

		while ((n /= 10) > 0) {

			byte current = (byte)(n % 10);

			if (Math.abs(prev - current) != 1) {
				return false;
			}

			prev = current;
		}

		return true;
	}

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		for (int t = stdin.nextInt(); t > 0; t--) {
			long n = stdin.nextLong();
			System.out.println(isValid(n) ? "YES" : "NO");
		}

		stdin.close();
	}
}
