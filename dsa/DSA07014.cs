using System;
using System.Linq;
using System.Collections.Generic;

internal class Program {

	static int? Calculate(int a, int b, char sign) {

		switch (sign) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		default:
			return null;
		}
	}

	public static void Main() {

		var cases = int.Parse(Console.ReadLine());

		for (; cases > 0; cases--) {

			var expression = Console.ReadLine().Trim();

			var stack = new Stack<int>();

			foreach (char c in expression.Reverse()) {

				if (char.IsDigit(c)) {
					stack.Push(c - '0');
					continue;
				}

				int left = stack.Pop();
				int right = stack.Pop();

				stack.Push(Calculate(left, right, c) ?? 0);
			}

			Console.WriteLine(stack.Peek());
		}
	}
}
