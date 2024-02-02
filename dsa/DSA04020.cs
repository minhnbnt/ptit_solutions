using System;
using System.Linq;
using System.Collections.Generic;

class Program {

	static void Main() {

		int cases;
		int.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			string[] tokens = Console.ReadLine().Split();

			int _size, target;
			Int32.TryParse(tokens[0], out _size);
			Int32.TryParse(tokens[1], out target);

			List<int> array = Console.ReadLine()
			                      .TrimEnd()
			                      .Split(" ")
			                      .Select(int.Parse)
			                      .ToList();

			int index = array.BinarySearch(target);

			if (index < 0) {
				Console.WriteLine("NO");
			} else {
				Console.WriteLine(index + 1);
			}
		}
	}
}
