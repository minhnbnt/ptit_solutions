/*
Cho mảng A[] gồm n phần tử, hãy đưa ra số nhỏ nhất và số nhỏ thứ hai của mảng.
Nếu không có số nhỏ thứ hai, hãy đưa ra -1.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test.

Mỗi bộ test gồm hai dòng:
dòng thứ nhất đưa vào n là số phần tử của mảng A[];
dòng tiếp theo đưa vào n số A[i];
các số được viết cách nhau một vài khoảng trống.

T, n, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤N, A[i] ≤10^7.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
10
5 6 7 8 9 10 1 2 3 4
5
1 1 1 1 1

Output:
1 2
-1
*/

import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class DSA06022 {
	public static void main(String[] args) {

		try (Scanner stdin = new Scanner(System.in)) {

			int cases = stdin.nextInt();

			for (; cases > 0; cases--) {

				final int size = stdin.nextInt();

				List<Integer> numbers = IntStream.range(0, size)
				                            .map(i -> stdin.nextInt())
				                            .distinct()
				                            .boxed()
				                            .collect(Collectors.toList());

				if (numbers.size() < 2) {
					System.out.println(-1);
					continue;
				}

				numbers.stream()
				    .sorted(Comparator.naturalOrder())
				    .limit(2)
				    .forEach(x -> System.out.printf("%d ", x));

				System.out.append('\n');
			}
		}
	}
}
