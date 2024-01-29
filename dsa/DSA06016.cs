using System;
using System.Linq;

class Solution {
	static void Main() {

		int cases;
		Int32.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			string[] tokens = Console.ReadLine().Split();

			int _size1 = int.Parse(tokens[0]);
			int _size2 = int.Parse(tokens[1]);

			long max1 = Console.ReadLine()
			                .TrimEnd()
			                .Split(' ')
			                .Select(long.Parse)
			                .Max();

			long min2 = Console.ReadLine()
			                .TrimEnd()
			                .Split(" ")
			                .Select(Int64.Parse)
			                .Min();

			Console.WriteLine(max1 * min2);
		}
	}
}
