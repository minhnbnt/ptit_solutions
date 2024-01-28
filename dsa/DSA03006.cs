using System;
using System.Linq;
using System.Collections.Generic;

class Solution {

	static bool CanGreedySorting(List<int> array) {

		List<int> sorted = array.OrderBy(x => x).ToList();

		int left = 0, right = array.Count - 1;
		while (left < right) {

			bool condition1 =
			    array[left] == sorted[left] && array[right] == sorted[right];

			bool condition2 =
			    array[left] == sorted[right] && array[right] == sorted[left];

			if (!(condition1 || condition2)) {
				return false;
			}

			left++;
			right--;
		}

		return true;
	}

	static void Main(string[] args) {

		uint cases;
		uint.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			int size = int.Parse(Console.ReadLine());

			List<int> array = Console.ReadLine()
			                      .Split()
			                      .Take(size)
			                      .Select(int.Parse)
			                      .ToList();

			bool result = CanGreedySorting(array);

			Console.WriteLine(result ? "Yes" : "No");
		}
	}
}
