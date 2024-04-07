using System;
using System.Linq;
using System.Collections.Generic;

class DiGraph {

	private Dictionary<int, SortedSet<int>> adjList;
	public DiGraph() => adjList = new Dictionary<int, SortedSet<int>>();

	public void AddEdge(int from, int to) {

		if (!adjList.ContainsKey(from)) {
			adjList[from] = new SortedSet<int>();
		}

		adjList[from].Add(to);
	}

	public IEnumerable<int> BFS(int start) {

		var queue = new Queue<int>();
		queue.Enqueue(start);

		var visited = new HashSet<int>();

		while (queue.Count > 0) {

			var current = queue.Dequeue();

			if (visited.Contains(current)) {
				continue;
			}

			yield return current;
			visited.Add(current);

			SortedSet<int> adjs;

			if (!adjList.TryGetValue(current, out adjs)) {
				continue;
			}

			foreach (int vertex in adjs) {
				queue.Enqueue(vertex);
			}
		}
	}
}

internal class Program {
	static void Main() {

		var cases = int.Parse(Console.ReadLine());

		for (; cases > 0; cases--) {

			string[] tokens = Console.ReadLine().Split();

			int rank = int.Parse(tokens[0]);
			int nEdges = int.Parse(tokens[1]);
			int start = int.Parse(tokens[2]);

			int[] edgesFlatted = Console.ReadLine()
			                         .TrimEnd()
			                         .Split()
			                         .Select(int.Parse)
			                         .ToArray();

			DiGraph graph = new DiGraph();

			for (int i = 0; i < nEdges; i++) {

				int a = edgesFlatted[i * 2];
				int b = edgesFlatted[i * 2 + 1];

				graph.AddEdge(a, b);
			}

			foreach (int vertex in graph.BFS(start)) {
				Console.Write("{0} ", vertex);
			}

			Console.WriteLine();
		}
	}
}
