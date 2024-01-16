using System;
using System.Linq;
using System.Collections.Generic;

class Program {
	static void Main() {

		int cases;
		int.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			int size, window_size;
			string[] token = Console.ReadLine().Split();

			Int32.TryParse(token[0], out size);
			Int32.TryParse(token[1], out window_size);

			int[] array = Console.ReadLine().Trim().Split().Select(int.Parse).ToArray();

			var list = new LinkedList<int>();
			for (int i = 0; i < size; i++) {

				while (list.Count != 0 && array[list.Last.Value] < array[i]) {
					list.RemoveLast();
				}

				list.AddLast(i);

				if (list.First.Value == i - window_size) {
					list.RemoveFirst();
				}

				if (i > window_size - 2) {
					Console.Write(array[list.First.Value] + " ");
				}
			}

			Console.WriteLine();
		}
	}
}
