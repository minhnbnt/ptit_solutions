import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Main {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int size1 = stdin.nextInt();
		int size2 = stdin.nextInt();

		Set<Integer> set = new TreeSet<>();
		for (int i = 0; i < size1 + size2; i++) {
			set.add(stdin.nextInt());
		}

		set.forEach(element -> System.out.printf("%d ", element));
	}
}
