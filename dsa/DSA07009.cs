using System;
using System.Linq;
using System.Collections.Generic;

internal class Program {
	static void Main() {

		var cases = int.Parse(Console.ReadLine());

		for (; cases > 0; cases--) {

			string input = Console.ReadLine();

			var stack = new Stack<string>();

			foreach (char c in input.Trim().Reverse()) {

				if (char.IsLetter(c)) {
					stack.Push(char.ToString(c));
					continue;
				}

				string left = stack.Pop();
				string right = stack.Pop();

				var expresstion = string.Format("({0}{1}{2})", left, c, right);
				stack.Push(expresstion);
			}

			Console.WriteLine(stack.First());
		}
	}
}
