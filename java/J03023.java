import java.util.Scanner;

public class Main {

	static int convertRomanToInt(char c) {
		switch (c) {
		case 'I':
			return 1;

		case 'V':
			return 5;

		case 'X':
			return 10;

		case 'L':
			return 50;

		case 'C':
			return 100;

		case 'D':
			return 500;

		case 'M':
			return 1000;

		default:
			return 0;
		}
	}

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		for (int cases = stdin.nextInt(); cases > 0; cases--) {

			String input = stdin.next();
			int result = 0, prev = 0;

			for (char c : input.toCharArray()) {

				int current = convertRomanToInt(c);

				if (current > prev) {
					result += current - (prev * 2);
				} else {
					result += current;
				}

				prev = current;
			}

			System.out.println(result);
		}
	}
}
