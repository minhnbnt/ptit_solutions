using System;
using System.Linq;

class Program {
	static void Main(string[] args) {

		int size = int.Parse(Console.ReadLine());

		int[] array = Console.ReadLine()
		                  .TrimEnd()
		                  .Split()
		                  .Select(int.Parse)
		                  .OrderBy(x => x)
		                  .ToArray();

		int[] possibleCases = {

			array[0] * array[1],
			array[0] * array[1] * array[size - 1],

			array[size - 1] * array[size - 2],
			array[size - 1] * array[size - 2] * array[size - 3],
		};

		Console.WriteLine(possibleCases.Max());
	}
}
