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
