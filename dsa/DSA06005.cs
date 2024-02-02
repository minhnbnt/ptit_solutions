using System;
using System.Linq;

class Program {

	static void Main() {

		int cases;
		int.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			string[] token = Console.ReadLine().Split();
			int _size1 = Int32.Parse(token[0]);
			int _size2 = Int32.Parse(token[1]);

			var query =
			    from str in Console.ReadLine().Trim().Split()
			        select Int32.Parse(str);

			var set1 = query.ToHashSet();

			var set2 = Console.ReadLine()
			               .Trim()
			               .Split()
			               .Select(Int32.Parse)
			               .ToHashSet();

			set1 //
			    .Union(set2)
			    .OrderBy(x => x)
			    .ToList()
			    .ForEach(x => Console.Write(x + " "));
			Console.Write('\n');

			set1 //
			    .Intersect(set2)
			    .OrderBy(x => x)
			    .ToList()
			    .ForEach(x => Console.Write(x + " "));
			Console.WriteLine();
		}
	}
}
