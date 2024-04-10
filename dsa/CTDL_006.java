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
