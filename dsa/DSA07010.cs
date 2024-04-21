using System;
using System.Linq;
using System.Collections.Generic;

internal class Program {
	public static void Main() {

		var cases = int.Parse(Console.ReadLine());

		for (; cases > 0; cases--) {
			var expression = Console.ReadLine().Trim();

			var stack = new Stack<string>();

			foreach (char c in expression.Reverse()) {

				if (char.IsLetter(c)) {
					stack.Push(c.ToString());
					continue;
				}

				string left = stack.Pop();
				string right = stack.Pop();

				stack.Push(left + right + c);
			}

			Console.WriteLine(stack.Peek());
		}
	}
}
