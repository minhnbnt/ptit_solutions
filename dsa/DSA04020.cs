/*
Cho dãy số A[] gồm có N phần tử đã được sắp xếp tăng dần và số K.

Nhiệm vụ của bạn là kiểm tra xem số K có xuất hiện trong dãy số hay không.
Nếu có hãy in ra vị trí trong dãy A[], nếu không in ra “NO”.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

Mỗi test bắt đầu bằng số nguyên N và K (N ≤ 100 000, 0 ≤ K ≤ 10^6).
Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 10^6), các phần tử là riêng
biệt.

Output:
Với mỗi test in ra trên một dòng đáp án tìm được.

Ví dụ:

Input:
2
5 3
1 2 3 4 5
6 5
0 1 2 3 9 10

Output:
3
NO
*/

using System;
using System.Linq;
using System.Collections.Generic;

class Program {

	static void Main() {

		int cases;
		int.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			string[] tokens = Console.ReadLine().Split();

			int _size, target;
			Int32.TryParse(tokens[0], out _size);
			Int32.TryParse(tokens[1], out target);

			List<int> array = Console.ReadLine()
			                      .TrimEnd()
			                      .Split(" ")
			                      .Select(int.Parse)
			                      .ToList();

			int index = array.BinarySearch(target);

			if (index < 0) {
				Console.WriteLine("NO");
			} else {
				Console.WriteLine(index + 1);
			}
		}
	}
}
