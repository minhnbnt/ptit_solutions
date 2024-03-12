import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class CTDL_006 {

	static final Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {

		int size = stdin.nextInt();

		List<Integer> linkedList = new LinkedList<>();
		for (int i = 0; i < size; i++) {
			linkedList.add(stdin.nextInt());
		}

		new LinkedHashSet<>(linkedList)
		    .forEach(element -> System.out.printf("%d ", element));

		System.out.append('\n');
	}
}
