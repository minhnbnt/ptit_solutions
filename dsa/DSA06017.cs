using System;
using System.Linq;

class Program {

	static void Main() {

		int cases;
		int.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			string[] tokens = Console.ReadLine().Split();
			int _size1 = Int32.Parse(tokens[0]);
			int _size2 = Int32.Parse(tokens[1]);

			var array1 = Console.ReadLine()
			                 .TrimEnd()
			                 .Split(' ')
			                 .Select(long.Parse)
			                 .ToList();

			var array2 = Console.ReadLine()
			                 .TrimEnd()
			                 .Split(' ')
			                 .Select(Int64.Parse)
			                 .ToList();

			array1 //
			    .Concat(array2)
			    .OrderBy(x => x)
			    .ToList()
			    .ForEach(x => Console.Write(x + " "));

			Console.Write('\n');
		}
	}
}
