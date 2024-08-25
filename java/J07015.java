import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class J07015 {

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws Exception {

		FileInputStream fileStream = new FileInputStream("SONGUYEN.in");
		ObjectInputStream objectStream = new ObjectInputStream(fileStream);

		List<Integer> array;
		try {
			array = (ArrayList<Integer>)objectStream.readObject();
		} finally {
			objectStream.close();
		}

		Map<Integer, Integer> counterMap = new TreeMap<>();
		array.forEach(number -> { //
			counterMap.merge(number, 1, Integer::sum);
		});

		counterMap.entrySet()
		    .stream()
		    .filter(entry -> Utils.isPrime(entry.getKey()))
		    .forEach((entry) -> {
			    int number = entry.getKey();
			    int count = entry.getValue();
			    System.out.printf("%d %d%n", number, count);
		    });
	}
}

class Utils {
	static boolean isPrime(int n) {

		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0) {
				return false;
			}
		}

		return n > 1;
	}
}
