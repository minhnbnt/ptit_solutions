import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class J07016 {

	@SuppressWarnings("unchecked")
	static List<Integer> getNumbers(String URI)
	    throws IOException, ClassNotFoundException {

		FileInputStream fileStream = new FileInputStream(URI);
		ObjectInputStream objectStream = new ObjectInputStream(fileStream);

		List<Integer> result = (List<Integer>)objectStream.readObject();
		objectStream.close();

		return result;
	}

	public static void main(String[] args) throws Exception {

		List<Integer> numbers = getNumbers("DATA1.in");

		Map<Integer, Integer> counterMap1 = new TreeMap<>();
		numbers.forEach(number -> { //
			counterMap1.merge(number, 1, Integer::sum);
		});

		numbers = getNumbers("DATA2.in");

		Map<Integer, Integer> counterMap2 = new TreeMap<>();
		numbers.forEach(number -> { //
			counterMap2.merge(number, 1, Integer::sum);
		});

		counterMap1.keySet()
		    .stream()
		    .filter(counterMap2::containsKey)
		    .filter(Utils::isPrime)
		    .forEach(number -> {
			    int count1 = counterMap1.get(number);
			    int count2 = counterMap2.get(number);

			    System.out.printf("%d %d %d%n", //
			                      number, count1, count2);
		    });
	}
}

class Utils {
	public static boolean isPrime(int n) {

		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0) return false;
		}

		return n > 1;
	}
}
