import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class J01024 {
	public static void main(String[] args) {

		Pattern pattern = Pattern.compile("[0-2]+");

		try (Scanner stdin = new Scanner(System.in)) {
			for (int cases = stdin.nextInt(); cases > 0; cases--) {

				String number = stdin.next();

				Matcher matcher = pattern.matcher(number);
				System.out.println(matcher.matches() ? "YES" : "NO");
			}
		}
	}
}
