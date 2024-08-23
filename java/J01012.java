import java.util.Scanner;

public class J01012 {

	static int getResult(int n) {

		int result = 0;
		while (n % 2 == 0) {
			result++;
			n /= 2;
		}

		for (int i = 3; i <= Math.sqrt(n); i++) {

			int count = 0;

			while (n % i == 0) {
				count++;
				n /= i;
			}

			result *= count + 1;
		}

		if (n > 1) {
			result *= 2;
		}

		return result;
	}

	public static void main(String[] args) {
		try (Scanner stdin = new Scanner(System.in)) {

			int cases = stdin.nextInt();

			for (; cases > 0; cases--) {
				int n = stdin.nextInt();
				int result = getResult(n);
				System.out.println(result);
			}
		}
	}
}
