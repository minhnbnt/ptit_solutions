import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int rank = stdin.nextInt();

		for (int i = 1; i <= rank; i++) {
			for (int j = 1; j <= rank; j++) {

				int value = stdin.nextInt();

				if (i < j && value == 1) {
					System.out.printf("(%d,%d)%n", i, j);
				}
			}
		}
	}
}
