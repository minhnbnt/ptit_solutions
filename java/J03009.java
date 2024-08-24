import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class J03009 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int cases = stdin.nextInt();
		stdin.skip("\\s+");

		for (int i = 0; i < cases; i++) {

			String[] tokens1 = stdin.nextLine().split("\\s+");
			String[] tokens2 = stdin.nextLine().split("\\s+");

			Set<String> tokensSet = new HashSet<>();
			Collections.addAll(tokensSet, tokens2);

			Arrays.stream(tokens1)
			    .filter(token -> !tokensSet.contains(token))
			    .distinct()
			    .sorted()
			    .forEach(token -> System.out.printf("%s ", token));

			System.out.println();
		}

		stdin.close();
	}
}
