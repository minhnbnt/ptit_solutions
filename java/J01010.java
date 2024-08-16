import java.util.Scanner;
import java.util.concurrent.atomic.AtomicLong;

public class J01010 {

	static int splitDigit(int digit) {
		switch (digit) {
		case 0:
		case 8:
		case 9:
			return 0;

		case 1:
			return 1;

		default:
			throw new RuntimeException();
		}
	}

	static long splitNumber(Long number) {

		AtomicLong result = new AtomicLong();

		number.toString().chars().forEach(c -> {
			result.updateAndGet(v -> v * 10);
			result.addAndGet(splitDigit(c - '0'));
		});

		if (result.get() == 0) {
			throw new RuntimeException();
		}

		return result.get();
	}

	public static void main(String[] args) {
		try (Scanner stdin = new Scanner(System.in)) {
			for (int cases = stdin.nextInt(); cases > 0; cases--) {

				long number = stdin.nextLong();

				try {
					System.out.println(splitNumber(number));
				} catch (RuntimeException e) {
					System.out.println("INVALID");
				}
			}
		}
	}
}
