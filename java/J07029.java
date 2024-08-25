import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.TreeMap;

public class J07029 {

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws Exception {

		FileInputStream fileStream = new FileInputStream("DATA.in");
		ObjectInputStream objectStream = new ObjectInputStream(fileStream);

		List<Integer> array;
		try {
			array = (ArrayList<Integer>)objectStream.readObject();
		} finally {
			objectStream.close();
		}

		TreeMap<Integer, Integer> counterMap = new TreeMap<>();
		array.forEach(number -> { //
			counterMap.merge(number, 1, Integer::sum);
		});

		counterMap.descendingMap()
		    .entrySet()
		    .stream()
		    .filter(entry -> isPrime(entry.getKey()))
		    .limit(10)
		    .forEach(entry -> {
			    int number = entry.getKey();
			    int count = entry.getValue();

			    System.out.printf("%d %d%n", number, count);
		    });
	}

	static boolean isPrime(int n) {

		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0) {
				return false;
			}
		}

		return n > 1;
	}
}
