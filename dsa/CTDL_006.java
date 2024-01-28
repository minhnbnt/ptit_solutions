import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class CTDL_006 {

	static final Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {

		int size = stdin.nextInt();

		List<Integer> linkedList = new LinkedList<>();
		for (int i = 0; i < size; i++) {
			linkedList.add(stdin.nextInt());
		}

		Set<Integer> set = new LinkedHashSet<>();
		linkedList.forEach(x -> set.add(x));

		set.forEach(element -> System.out.printf("%d ", element));
		System.out.append('\n');
	}
}
