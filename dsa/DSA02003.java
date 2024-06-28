/*
Cho một mê cung bao gồm các khối được biểu diễn như một ma trận nhị phân
A[N][N].

Một con chuột đi từ ô đầu tiên góc trái (A[0][0]) đến ô cuối cùng góc phải
(A[N-1][N-1]) theo nguyên tắc:

Down (D): Chuột được phép xuống dưới nếu ô dưới nó có giá trị 1.
Right (R): Chuột được phép sang phải dưới nếu ô bên phải nó có giá trị 1.

Hãy đưa ra một hành trình của con chuột trên mê cung. Đưa ra -1 nếu chuột không
thể đi đến đích.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.

Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần:
phần thứ nhất đưa vào số N là kích cỡ của mê cung;
dòng tiếp theo đưa vào ma trận nhị phân A[N][N].
T, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 2≤N≤10; 0≤A[i][j] ≤1.

Output:
Đưa ra tất cả đường đi của con chuột trong mê cung theo thứ tự từ điển.
Đưa ra -1 nếu chuột không đi được đến đích.

Input
2
4
1 0 0 0
1 1 0 1
0 1 0 0
1 1 1 1
5
1 0 0 0 0
1 1 1 1 1
1 1 0 0 1
0 1 1 1 1
0 0 0 1 1

Output
DRDDRR
DDRDRRDR DDRDRRRD DRDDRRDR DRDDRRRD DRRRRDDD
*/

import static java.lang.System.out;

import java.util.Scanner;
import java.util.Stack;

class Finder {

	private final int row, col;
	private final boolean[][] matrix;

	private boolean hasPath;
	private final Stack<Character> path;

	public Finder(boolean[][] matrix) {

		this.hasPath = false;

		this.matrix = matrix;

		this.row = matrix.length;
		this.col = matrix[0].length;

		this.path = new Stack<>();
	}

	public boolean hasPath() {
		return hasPath;
	}

	public void DFS(int x, int y) {

		if (x >= row || y >= col || !matrix[x][y]) {
			return;
		}

		if (x == row - 1 && y == col - 1) {

			path.forEach(out::append);
			out.append(' ');

			hasPath = true;
			return;
		}

		path.push('D');
		this.DFS(x + 1, y);
		path.pop();

		path.push('R');
		this.DFS(x, y + 1);
		path.pop();
	}
}

public class DSA02003 {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		for (int cases = stdin.nextInt(); cases > 0; cases--) {

			int i, rank = stdin.nextInt();

			boolean[][] matrix = new boolean[rank][rank];

			for (boolean[] row : matrix) {
				for (i = 0; i < rank; i++) {
					row[i] = stdin.nextInt() == 1;
				}
			}

			Finder f = new Finder(matrix);
			f.DFS(0, 0);

			if (!f.hasPath()) {
				out.print(-1);
			}

			out.println();
		}

		stdin.close();
	}
}
