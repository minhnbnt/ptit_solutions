using System;
using System.Collections.Generic;

class Program {

	static void Main() {

		int cases;
		int.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			int _size;
			Int32.TryParse(Console.ReadLine(), out _size);

			var charSet = new SortedSet<char>();
			var tokens = Console.ReadLine().Split(' ');

			foreach (string token in tokens) {
				foreach (char c in token) {
					charSet.Add(c);
				}
			}

			foreach (char c in charSet) {
				Console.Write(c + " ");
			}
			Console.Write('\n');
		}
	}
}
