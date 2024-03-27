using System;
using System.Collections.Generic;

internal class Program {
	static void Main(string[] args) {

		var cases = int.Parse(Console.ReadLine());

		while (cases-- > 0) {

			var mod = int.Parse(Console.ReadLine());

			var queue = new Queue<long>(new long[] { 1 });

			while (true) {

				var current = queue.Dequeue();

				if (current % mod == 0) {
					Console.WriteLine(current);
					break;
				}

				queue.Enqueue(current * 10);
				queue.Enqueue(current * 10 + 1);
			}
		}
	}
}
