import java.util.Scanner;

class Pair<T extends Number, U extends Number> {

	private final T first;
	private final U second;

	Pair(T first, U second) {
		this.first = first;
		this.second = second;
	}

	public boolean isPrime() {
		return Utils.isPrime(first) && Utils.isPrime(second);
	}

	@Override
	public String toString() {
		return first + " " + second;
	}
}

public class J04020 {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
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

class Utils {
	public static boolean isPrime(Number n) {

		long value = n.longValue();
		for (int i = 2; i <= Math.sqrt(value); i++) {
			if (value % i == 0) return false;
		}

		return value > 1;
	}
}
