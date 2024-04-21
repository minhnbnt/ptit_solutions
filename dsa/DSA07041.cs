using System;
using System.Collections.Generic;

internal class Program {
	public static void Main() {

		var cases = int.Parse(Console.ReadLine());

		for (; cases > 0; cases--) {

			var brackets = Console.ReadLine().Trim();

			uint result = 0;
			var stack = new Stack<char>();

			foreach (char bracket in brackets) {

				if (bracket == '(') {
					stack.Push(bracket);
					continue;
				}

				if (stack.Count > 0) {
					result += 2;
					stack.Pop();
				}
			}

			Console.WriteLine(result);
		}
	}
}
