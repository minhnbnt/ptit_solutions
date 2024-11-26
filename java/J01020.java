import java.util.HashSet;
import java.util.Optional;
import java.util.Scanner;
import java.util.Set;

public class Main {

	static Optional<Long> stepToConvert(long n) {

		if (n == 0) {
			return Optional.empty();
		}

		Set<Integer> digits = new HashSet<>();

		for (int i = 1;; i++) {

			long current = n * i;

			Long.toString(current) //
			    .codePoints()
			    .forEach(digits::add);

			if (digits.size() == 10) {
				return Optional.of(current);
			}
		}
	}

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int cases = stdin.nextInt();
		for (int i = 0; i < cases; i++) {

			long n = stdin.nextLong();

			String result = stepToConvert(n) //
			                    .map(Object::toString)
			                    .orElse("Impossible");

			System.out.println(result);
		}
	}
}
