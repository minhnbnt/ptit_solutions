using System;
using System.Linq;
using System.Collections.Generic;

class Program {

	static void Main() {

		int cases;
		int.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			int size = Int32.Parse(Console.ReadLine());

			var array = Console.ReadLine()
			                .Trim()
			                .Split()
			                .Select(Int32.Parse)
			                .OrderBy(x => x)
			                .ToList();

			int minimum_diff = Int32.MaxValue;
			for (int i = 1; i < size; i++) {
				int diff = array[i] - array[i - 1];
				minimum_diff = Math.Min(minimum_diff, diff);
			}

			Console.WriteLine(minimum_diff);
		}
	}
}
