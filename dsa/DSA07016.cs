using System;
using System.Collections.Generic;

internal class Program {
	public static void Main() {

		var cases = int.Parse(Console.ReadLine());

		for (; cases > 0; cases--) {

			string input = Console.ReadLine().Trim();

			var stack = new Stack<int>(new int[] { 1 });

			int currentNum = 1;

			foreach (char c in input) {
				currentNum += 1;

				if (c == 'D') {
					stack.Push(currentNum);
					continue;
				}

				while (stack.Count > 0) {
					Console.Write(stack.Pop());
				}

				stack.Push(currentNum);
			}

			while (stack.Count > 0) {
				Console.Write(stack.Pop());
			}

			Console.Write('\n');
		}
	}
}
