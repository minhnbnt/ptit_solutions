using System;
using System.Linq;
using System.Collections.Generic;

class Program {
	static int? HasTakeHalfSizeOf(List<int> array) {

		int halfSize = array.Count / 2;
		var counterMap = new Dictionary<int, uint>();

		foreach (int element in array) {

			try {
				counterMap[element]++;
			} catch (KeyNotFoundException) {
				counterMap.Add(element, 1);
			}
		}

		foreach (var item in counterMap) {
			if (item.Value > halfSize) {
				return item.Key;
			}
		}

		return null;
	}
	static void Main() {

		int cases;
		int.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			int size = Int32.Parse(Console.ReadLine());

			var array = Console.ReadLine().TrimEnd().Split().Select(int.Parse).ToList();

			if (HasTakeHalfSizeOf(array) is int result) {
				Console.WriteLine(result);
			} else {
				Console.WriteLine("NO");
			}
		}
	}
}
