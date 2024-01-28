using System;
using System.Linq;

class Program {

	static void Main() {

		int cases;
		int.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			int size;
			Int32.TryParse(Console.ReadLine(), out size);

			var array = Console.ReadLine()
			                .TrimEnd()
			                .Split()
			                .Select(int.Parse)
			                .OrderBy(x => x)
			                .ToArray();

			foreach (int element in array) {
				Console.Write(element + " ");
			}

			Console.Write('\n');
		}
	}
}
