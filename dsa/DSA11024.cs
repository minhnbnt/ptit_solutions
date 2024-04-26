using System;
using System.Linq;

internal class Program {

	static void Main() {

		int cases;
		int.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			int size;
			int.TryParse(Console.ReadLine(), out size);

			var elements = Console.ReadLine()
			                   .TrimEnd()
			                   .Split()
			                   .Select(int.Parse)
			                   .OrderBy(x => x)
			                   .ToArray();

			int rootIndex = (size - 1) / 2;
			Console.WriteLine(elements[rootIndex]);
		}
	}
}
