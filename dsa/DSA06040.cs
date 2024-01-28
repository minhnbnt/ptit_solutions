using System;
using System.Linq;

class Program {

	static void Main() {

		int cases;
		int.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			string[] tokens = Console.ReadLine().Split();
			int size1 = Int32.Parse(tokens[0]);
			int size2 = Int32.Parse(tokens[1]);
			int size3 = Int32.Parse(tokens[2]);

			var array1 = Console.ReadLine()
			                 .TrimEnd()
			                 .Split()
			                 .Select(long.Parse)
			                 .ToList();

			var array2 = Console.ReadLine()
			                 .TrimEnd()
			                 .Split()
			                 .Select(Int64.Parse)
			                 .ToList();

			var array3 = Console.ReadLine()
			                 .TrimEnd()
			                 .Split()
			                 .Select(Int64.Parse)
			                 .ToList();

			bool isEmpty = true;
			int i = 0, j = 0, k = 0;
			while (i < size1 && j < size2 && k < size3) {

				if (array1[i] == array2[j] && array2[j] == array3[k]) {

					isEmpty = false;
					Console.Write(array1[i] + " ");

					i++;
					j++;
					k++;

					continue;
				}

				if (array1[i] < array2[j]) {
					i++;
					continue;
				}

				if (array2[j] < array3[k]) {
					j++;
					continue;
				}

				k++;
			}

			if (isEmpty) {
				Console.Write(-1);
			}

			Console.Write("\n");
		}
	}
}
