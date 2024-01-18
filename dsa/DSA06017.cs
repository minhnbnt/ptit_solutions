using System;
using System.Linq;
using System.Collections.Generic;

class Program {
	static void Main() {

		int cases;
		int.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			string[] tokens = Console.ReadLine().Split();
			int size1 = Int32.Parse(tokens[0]);
			int size2 = Int32.Parse(tokens[1]);

			var array = new List<long>();
			foreach (var token in Console.ReadLine().Trim().Split()) {
				array.Add(Int64.Parse(token));
			}

			foreach (var token in Console.ReadLine().Trim().Split()) {
				array.Add(Int64.Parse(token));
			}

			foreach (long element in array.OrderBy(x => x)) {
				Console.Write(element + " ");
			}
			Console.Write('\n');
		}
	}
}
