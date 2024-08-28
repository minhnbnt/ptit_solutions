import java.io.File;
import java.io.IOException;
import java.util.Scanner;

class Utils {
	public static boolean isPrime(Number x) {

		long value = x.longValue();
		for (int i = 2; i <= Math.sqrt(value); i++) {
			if (value % i == 0) return false;
		}

		return value > 1;
	}
}

class Pair<T extends Number, U extends Number> {

	private final T first;
	private final U second;

	public Pair(T first, U second) {
		this.second = second;
		this.first = first;
	}

	public boolean isPrime() {
		return Utils.isPrime(first) && Utils.isPrime(second);
	}

	@Override
	public String toString() {
		return String.format("%d %d", first, second);
	}
}

public class J07017 {
	public static void main(String[] args) throws IOException {

		Scanner sc = new Scanner(new File("DATA.in"));
		int t = sc.nextInt();

		while (t-- > 0) {

			int n = sc.nextInt();
			boolean check = false;

			for (int i = 2; i <= 2 * Math.sqrt(n); i++) {

				Pair<Integer, Integer> p = new Pair<>(i, n - i);

				if (p.isPrime()) {
					System.out.println(p);
					check = true;
					break;
				}
			}

			if (!check) {
				System.out.println(-1);
			}
		}

		sc.close();
	}
}
