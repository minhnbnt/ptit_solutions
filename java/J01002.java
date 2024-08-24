import java.util.Scanner;

public class J01002 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		for (int t = stdin.nextInt(); t > 0; t--) {

			int n = stdin.nextInt();

			long result = (long)n * (n + 1) / 2;
			System.out.println(result);
		}

		stdin.close();
	}
}
