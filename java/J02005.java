import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class J02005 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int size1 = stdin.nextInt();
		int size2 = stdin.nextInt();

		Set<Integer> set1 = new TreeSet<>();
		for (int i = 0; i < size1; i++) {
			set1.add(stdin.nextInt());
		}

		Set<Integer> set2 = new HashSet<>();
		for (int i = 0; i < size2; i++) {
			set2.add(stdin.nextInt());
		}

		stdin.close();

		set1.stream()
		    .filter(set2::contains)
		    .forEach(element -> System.out.printf("%d ", element));
	}
}
