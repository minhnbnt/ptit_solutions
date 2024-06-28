/*
Cho danh sách liên kết đơn lưu giữ các số nguyên được quản lý bởi con trỏ First.

Viết chương trình con lọc tất cả các phần tử có giá trị trùng nhau trong danh
sách liên kết đơn First, chỉ để lại 1 phần tử đại diện cho nhóm trùng.

Sau khi lọc xong, liệt kê các phần tử  trong danh sách liên kết đơn First.

Ví dụ: Ta có Input:

12                        // là số lượng phân tử trong danh sách
1 1 1 4  5 1 4  7 7 8 1 9 // là số phần tử

Output:
1 4 5 7 8 9
*/

import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class CTDL_006 {

	static final Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {

		int size = stdin.nextInt();

		List<Integer> linkedList = new LinkedList<>();
		for (int i = 0; i < size; i++) {
			linkedList.add(stdin.nextInt());
		}

		linkedList //
		    .stream()
		    .distinct()
		    .forEach(element -> System.out.printf("%d ", element));

		System.out.append('\n');
	}
}
