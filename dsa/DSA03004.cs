/*
Cho mảng A[] gồm các số từ 0 đến 9.
Nhiệm vụ của bạn là tìm tổng nhỏ nhất của hai số được tạo bởi các số trong mảng
A[].
Chú ý, tất cả các số trong mảng A[] đều được sử dụng để tạo nên hai số.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.

Những dòng kế tiếp đưa vào các bộ test.

Mỗi bộ test gồm 2 dòng:
dòng thứ nhất đưa vào số phần tử của mảng N;
dòng tiếp theo đưa vào N số A[i] tương ứng với các phần tử của mảng A[];
các số được viết cách nhau một vài khoảng trống.

T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤20; 0≤A[i]≤9.

Output:

Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:
Input
2
6
6 8 4 5 2 3
5
5 3 0 7 4

Output
604
82
*/

using System;
using System.Linq;
using System.Collections.Generic;

public class Program {

	static long SmallestSum(List<int> digits) {

		int size = digits.Count;

		long result = 0;
		if (size % 2 == 0) {

			for (int i = 1; i < size; i += 2) {
				result *= 10;
				result += digits[i - 1] + digits[i];
			}

			return result;
		}

		result += digits[0];
		for (int i = 2; i < size; i += 2) {
			result *= 10;
			result += digits[i - 1] + digits[i];
		}

		return result;
	}

	static void Main(string[] args) {

		uint cases;
		uint.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			int size = int.Parse(Console.ReadLine());

			List<int> digits = Console.ReadLine()
			                       .TrimEnd()
			                       .Split()
			                       .Select(int.Parse)
			                       .OrderBy(x => x)
			                       .ToList();

			Console.WriteLine(SmallestSum(digits));
		}
	}
}
