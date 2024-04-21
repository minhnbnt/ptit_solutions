using System;
using System.Linq;
using System.Collections.Generic;

internal class Program {

	static HashSet<char> signs = new char[] { '+', '-', '*', '/' } //
	                                 .ToHashSet();

	static bool HasRedundantBracket(string expression) {

		var stack = new Stack<char>();

		foreach (char c in expression) {

			if (signs.Contains(c) || c == '(') {
				stack.Push(c);
				continue;
			}

			if (c != ')') {
				continue;
			}

			bool hasSign = false;

			while (stack.Peek() != '(') {
				hasSign = true;
				stack.Pop();
			}

			if (!hasSign) {
				return true;
			}

			stack.Pop();
		}

		return false;
	}

	static void Main() {

		var cases = int.Parse(Console.ReadLine());

		for (; cases > 0; cases--) {

			var expression = Console.ReadLine().Trim();

			bool result = HasRedundantBracket(expression);
			Console.WriteLine(result ? "Yes" : "No");
		}
	}
}
