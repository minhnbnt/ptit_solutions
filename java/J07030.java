import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class J07030 {

	@SuppressWarnings("unchecked")
	static List<Integer> getNumbers(String URI)
	    throws IOException, ClassNotFoundException {

		FileInputStream fileStream = new FileInputStream(URI);
		ObjectInputStream objectStream = new ObjectInputStream(fileStream);

		try {
			return (List<Integer>)objectStream.readObject();
		} finally {
			objectStream.close();
		}
	}

	public static void main(String[] args) throws Exception {

		List<Integer> list1 = getNumbers("DATA1.in");
		List<Integer> list2 = getNumbers("DATA2.in");

		Set<Integer> set = new HashSet<>(list2);
		list1.stream()
		    .distinct()
		    .filter(n -> {
			    int m = (int)1e6 - n;

			    if (n >= m || !set.contains(m)) {
				    return false;
			    }

			    return isPrime(n) && isPrime(m);
		    })
		    .sorted()
		    .forEach(n -> {
			    int m = (int)1e6 - n;
			    System.out.printf("%d %d%n", n, m);
		    });
	}

	static boolean isPrime(int n) {

		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0) return false;
		}

		return n > 1;
	}
}
