import java.util.Scanner;

public class J03018 {
	public static void main(String[] args) {
		try (Scanner stdin = new Scanner(System.in)) {

			for (int cases = stdin.nextInt(); cases > 0; cases--) {

				String number = stdin.next();
				int len = number.length();

				String slice = number;
				if (len > 1) {
					slice = number.substring(len - 2);
				}

				int temp = Integer.parseInt(slice);
				System.out.println(temp % 4 == 0 ? 4 : 0);
			}
		}
	}
}
