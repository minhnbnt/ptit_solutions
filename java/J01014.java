import java.util.Scanner;

public class J01014 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		for (int t = stdin.nextInt(); t > 0; t--) {

			long n = stdin.nextLong();

			long result = 0;

			for (int i = 2; (long)i * i < n; i++)
				while (n % i == 0) {
					result = i;
					n /= i;
				}

			if (n > 1) {
				result = n;
			}

			System.out.println(result);
		}

		stdin.close();
	}
}
