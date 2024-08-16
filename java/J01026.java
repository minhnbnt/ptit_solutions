import java.util.Scanner;

public class J01026 {

	static boolean isSquareNumber(int n) {
		final double squared = Math.sqrt(n);
		return squared == (int)squared;
	}

	public static void main(String[] args) {
		try (Scanner stdin = new Scanner(System.in)) {
			for (int cases = stdin.nextInt(); cases > 0; cases--) {
				int n = stdin.nextInt();
				System.out.println(isSquareNumber(n) ? "YES" : "NO");
			}
		}
	}
}
