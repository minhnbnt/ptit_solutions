import java.util.Scanner;

public class J03031 {

	static boolean convertibleToFullStr(String s, int replaceStep) {

		if (s.length() < 26) return false;

		long charsInStr = s.codePoints().distinct().count();
		return charsInStr + replaceStep >= 26;
	}

	public static void main(String[] args) {
		try (Scanner stdin = new Scanner(System.in)) {

			for (int cases = stdin.nextInt(); cases > 0; cases--) {

				String string = stdin.next();
				int replaceSteps = stdin.nextInt();

				boolean result = convertibleToFullStr(string, replaceSteps);
				System.out.println(result ? "YES" : "NO");
			}
		}
	}
}
