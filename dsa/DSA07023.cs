using System;
using System.Linq;

class Solution {
	static void Main() {

		int cases;
		Int32.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			string[] tokens = Console.ReadLine().TrimEnd().Split();

			foreach (string token in tokens.Reverse()) {
				Console.Write(token + " ");
			}

			Console.WriteLine();
		}
	}
}
