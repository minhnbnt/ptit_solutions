/*
Cho số nguyên dương N.
Nhiệm vụ của bạn là hãy liệt kê tất cả các hoán vị của 1, 2, .., N.
Ví dụ với N = 3 ta có kết quả: 123, 132, 213, 231, 312, 321.

Input:
Dòng đầu tiên đưa vào số lượng test T.

Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được
viết trên một dòng.

T, n thỏa mãn ràng buộc: 1≤T, N≤10.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input
2
2
3

Output
12 21
123 132 213 231 312 321
*/

import java.util.LinkedHashSet;
import java.util.Scanner;
import java.util.Set;

class Generator {

	final Set<Integer> set = new LinkedHashSet<>();

	public void allPermutation(int size) {

		if (set.size() == size) {

			for (int element : set) {
				System.out.print(element);
			}

			System.out.append(' ');
			return;
		}

		for (int i = 1; i <= size; i++) {

			if (set.contains(i)) {
				continue;
			}

			set.add(i);

			allPermutation(size);

			set.remove(i);
		}
	}
}

public class DSA01005 {

	static final Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {

		Generator gen = new Generator();

		int cases = stdin.nextInt();

		for (; cases > 0; cases--) {

			final int size = stdin.nextInt();

			gen.allPermutation(size);
			System.out.append('\n');
		}
	}
}
