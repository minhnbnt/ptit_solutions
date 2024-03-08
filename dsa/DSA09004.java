import java.util.*;

class Finder {

	private HashMap<Integer, TreeSet<Integer>> adjList;

	public Finder() {
		adjList = new HashMap<>();
	}

	public void addEdges(int a, int b) {
		adjList.computeIfAbsent(a, k -> new TreeSet<>()).add(b);
		adjList.computeIfAbsent(b, k -> new TreeSet<>()).add(a);
	}

	public LinkedHashSet<Integer> BFS(int start) {

		LinkedHashSet<Integer> visited = new LinkedHashSet<>();

		Queue<Integer> queue = new ArrayDeque<>();
		queue.offer(start);

		while (!queue.isEmpty()) {

			int current = queue.poll();

			if (visited.contains(current)) {
				continue;
			}

			visited.add(current);

			for (int adj : adjList.getOrDefault(current, new TreeSet<>())) {
				queue.offer(adj);
			}
		}

		return visited;
	}
}

public class DSA09004 {

	static final Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {

		int cases = stdin.nextInt();

		while (cases-- > 0) {

			int __rank = stdin.nextInt(),        //
			    numberOfEdges = stdin.nextInt(), //
			    start = stdin.nextInt();

			Finder finder = new Finder();

			for (int i = 0; i < numberOfEdges; i++) {
				int a = stdin.nextInt(), b = stdin.nextInt();
				finder.addEdges(a, b);
			}

			for (int point : finder.BFS(start)) {
				System.out.printf("%d ", point);
			}

			System.out.append('\n');
		}
	}
}
