import java.util.Scanner;

public class J01001 {
	public static void main(String[] args) {

		try (Scanner stdin = new Scanner(System.in)) {

			int width = stdin.nextInt();
			int height = stdin.nextInt();

			if (width <= 0 || height <= 0) {
				System.out.println(0);
			}

			else {
				long perimeter = 2L * (width + height);
				long area = (long)width * height;

				System.out.printf("%d %d\n", perimeter, area);
			}
		}
	}
}
