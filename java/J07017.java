import java.io.File;
import java.io.IOException;
import java.util.Scanner;

class Pair<T, U> {

	public static boolean isPrime(int x) {

		for (int i = 2; i <= Math.sqrt(x); i++) {
			if (x % i == 0) return false;
		}

		return x > 1;
	}

	private final T first;
	private final U second;

	public Pair(T first, U second) {
		this.first = first;
		this.second = second;
	}

	public boolean isPrime() {
		return isPrime((Integer)first) && isPrime((Integer)second);
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
			if (!check) System.out.println(-1);
		}
	}
	public static void main5635292(String[] args) throws IOException {
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
			if (!check) System.out.println(-1);
		}
	}
}
