using System;
using System.Linq;

class Solution {

	static void Main(string[] args) {

		uint cases;
		uint.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			string[] tokens = Console.ReadLine().Split();

			int size = int.Parse(tokens[0]);
			int sizeLeft = int.Parse(tokens[1]);

			int[] elements = Console.ReadLine()
			                     .Trim()
			                     .Split()
			                     .Select(int.Parse)
			                     .OrderBy(x => x)
			                     .ToArray();

			if (sizeLeft > size / 2) {
				sizeLeft = size - sizeLeft;
			}

			int sumLeft = 0, sumRight = 0;
			for (int i = 0; i < sizeLeft; i++) {
				sumLeft += elements[i];
			}
			for (int i = sizeLeft; i < size; i++) {
				sumRight += elements[i];
			}

			Console.WriteLine(sumRight - sumLeft);
		}
	}
}
