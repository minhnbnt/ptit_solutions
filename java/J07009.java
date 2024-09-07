import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.stream.Collectors;

class IntSet {

	private final TreeSet<Integer> set;

	public IntSet(TreeSet<Integer> set) {
		this.set = set;
	}

	public IntSet(int[] array) {

		this(new TreeSet<>());

		for (int elem : array) {
			this.set.add(elem);
		}
	}

	public IntSet intersection(IntSet other) {

		TreeSet<Integer> result = new TreeSet<>(set);
		result.retainAll(other.set);

		return new IntSet(result);
	}

	@Override
	public String toString() {
		return this.set.stream()
		    .map(String::valueOf)
		    .collect(Collectors.joining(" "));
	}
}

public class J07009 {
	public static void main(String[] args) throws IOException {

		Scanner sc = new Scanner(new File("DATA.in"));

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
		IntSet s3 = s1.intersection(s2);

		System.out.println(s3);
	}
}
