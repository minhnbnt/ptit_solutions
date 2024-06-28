/*
Cho số nguyên N.
Nhiệm vụ của bạn cần tìm số nguyên X nhỏ nhất là bội của N, và X chỉ chứa hai
chữ số 0 và 9.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10000).
Mỗi bộ test chứa số nguyên N trên một dòng (1 ≤ N ≤ 500).

Output:
Với mỗi test in ra đáp án tìm được trên một dòng.

Ví dụ:
Input
3
2
5
11

Output
90
90
99
*/

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
