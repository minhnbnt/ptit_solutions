using System;
using System.Linq;
using System.Collections.Generic;

class Program {

	static int? BalanceIndex(List<int> array) {

		int sumLeft = 0, sumRight = array.Sum();

		for (int i = 0; i < array.Count; i++) {
			if (sumLeft == sumRight - array[i]) {
				return i;
			}

			sumLeft += array[i];
			sumRight -= array[i];
		}

		return null;
	}

	static void Main() {

		int cases;
		int.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			int size = Int32.Parse(Console.ReadLine());

			List<int> array = Console.ReadLine().TrimEnd().Split().Select(int.Parse).ToList();

			if (BalanceIndex(array) is int result) {
				Console.WriteLine(result + 1);
			} else {
				Console.WriteLine(-1);
			}
		}
	}
}
