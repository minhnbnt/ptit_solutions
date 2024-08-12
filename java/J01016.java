import java.util.Scanner;

public class J01016 {
	public static void main(String[] args) {

		try (Scanner stdin = new Scanner(System.in)) {

			String lines = stdin.nextLine();

			long count = lines //
			                 .codePoints()
			                 .filter(c -> c == '4' || c == '7')
			                 .count();

			boolean result = count == 4 || count == 7;
			System.out.println(result ? "YES" : "NO");
		}
	}
}
