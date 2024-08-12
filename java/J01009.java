import java.util.Scanner;

public class J01009 {
	public static void main(String[] args) {

		try (Scanner stdin = new Scanner(System.in)) {
			int input = stdin.nextInt();

			long result = 0, primorial = 1;
			for (int i = 1; i <= input; i++) {
				primorial *= i;
				result += primorial;
			}

			System.out.println(result);
		}
	}
}
