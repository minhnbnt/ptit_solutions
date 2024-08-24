import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

public class J02007 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int cases = stdin.nextInt();

		for (int i = 1; i <= cases; i++) {

			System.out.printf("Test %d:%n", i);

			int size = stdin.nextInt();

			Map<Integer, Integer> counterMap = new LinkedHashMap<>();
			for (int j = 0; j < size; j++) {
				int input = stdin.nextInt();
				counterMap.merge(input, 1, Integer::sum);
			}

			counterMap.forEach((number, count) -> {
				System.out.printf("%d xuat hien %d lan%n", number, count);
			});
		}

		stdin.close();
	}
}
