import java.util.Arrays;
import java.util.Scanner;

public class DSA04018 {

	static Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {

		int cases = stdin.nextInt();
		while (cases-- > 0) {

			int _size = stdin.nextInt();
			stdin.skip("\\s+");

			long result =
			    Arrays.stream(stdin.nextLine().split("\\s+"))
			        .filter((s) -> s.equals("0"))
			        .count();

			System.out.println(result);
		}
	}
}
