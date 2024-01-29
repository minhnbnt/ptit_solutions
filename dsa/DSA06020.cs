using System;
using System.Linq;

class Solution {
	static void Main() {

		int cases;
		Int32.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			string[] tokens = Console.ReadLine().Split();

			int _size = int.Parse(tokens[0]);
			int target = int.Parse(tokens[1]);

			int[] array = Console.ReadLine()
			                  .TrimEnd()
			                  .Split()
			                  .Select(int.Parse)
			                  .ToArray();

			int index = Array.BinarySearch(array, target);
			Console.WriteLine(index < 0 ? -1 : 1);
		}
	}
}
