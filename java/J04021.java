import java.util.Scanner;
import java.util.TreeSet;
import java.util.stream.Collectors;

class IntSet extends TreeSet<Integer> {

	public IntSet() {
		super();
	}

	public IntSet(int[] array) {

		this();

		for (int elem : array) {
			this.add(elem);
		}
	}

	public IntSet union(IntSet other) {

		IntSet result = new IntSet();

		result.addAll(this);
		result.addAll(other);

		return result;
	}

	@Override
	public String toString() {
		return this.stream()
		    .map(String::valueOf)
		    .collect(Collectors.joining(" "));
	}
}

public class J04021 {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}

		int[] b = new int[m];
		for (int i = 0; i < m; i++) {
			b[i] = sc.nextInt();
		}

		sc.close();

		IntSet s1 = new IntSet(a);
		IntSet s2 = new IntSet(b);
		IntSet s3 = s1.union(s2);

		System.out.println(s3);
	}
}
