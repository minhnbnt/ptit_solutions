import java.util.*;

public class Main {
	public static void main(String[] args) {

		Map<Integer, List<Integer>> adjSet = new HashMap<>();

		Scanner stdin = new Scanner(System.in);

		int vertices = stdin.nextInt();

		for (int i = 1; i < vertices; i++) {

			int a = stdin.nextInt();
			int b = stdin.nextInt();

			adjSet.computeIfAbsent(a, k -> new ArrayList<>()).add(b);
			adjSet.computeIfAbsent(b, k -> new ArrayList<>()).add(a);
		}

		boolean isStar =
		    adjSet.values()
		        .stream()
		        .mapToInt(List::size)
		        .allMatch(size -> size == 1 || size == vertices - 1);

		System.out.println(isStar ? "Yes" : "No");
	}
}
