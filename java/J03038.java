import java.util.Scanner;

public class J03038 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		String input = stdin.nextLine();
		stdin.close();

		long result = input.codePoints().distinct().count();
		System.out.println(result);
	}
}
