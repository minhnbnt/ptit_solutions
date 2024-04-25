using System;
using System.Collections.Generic;

internal class Program {
	static void Main() {

		var cases = int.Parse(Console.ReadLine());

		for (; cases > 0; cases--) {

			var target = uint.Parse(Console.ReadLine());

			var queue = new Queue<ulong>(new ulong[] { 9 });

			while (true) {

				ulong current = queue.Dequeue();

				if (current % target == 0) {
					Console.WriteLine(current);
					break;
				}

				queue.Enqueue(current * 10);
				queue.Enqueue(current * 10 + 9);
			}
		}
	}
}
