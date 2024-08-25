import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.*;

public class J07032 {

	static boolean isValid(int n) {

		String s = Integer.toString(n);

		if (s.length() == 1 || s.length() % 2 == 0) {
			return false;
		}

		StringBuilder builder = new StringBuilder(s);
		String reversed = builder.reverse().toString();
		if (!reversed.equals(s)) {
			return false;
		}

		return s.codePoints()
		    .map(digit -> digit - '0')
		    .allMatch(digit -> digit % 2 != 0);
	}

	@SuppressWarnings("unchecked")
	static List<Integer> getNumbersInBinaryFile(String fileName)
	    throws IOException, ClassNotFoundException {

		FileInputStream fileStream = new FileInputStream(fileName);
		ObjectInputStream objectStream = new ObjectInputStream(fileStream);

		try {
			return (ArrayList<Integer>)objectStream.readObject();
		} finally {
			objectStream.close();
		}
	}

	public static void main(String[] args) throws Exception {

		Map<Integer, Integer> counterMap1 = new TreeMap<>();
		List<Integer> array = getNumbersInBinaryFile("DATA1.in");
		array.forEach(number -> { //
			counterMap1.merge(number, 1, Integer::sum);
		});

		Map<Integer, Integer> counterMap2 = new HashMap<>();
		array = getNumbersInBinaryFile("DATA2.in");
		array.forEach(number -> { //
			counterMap2.merge(number, 1, Integer::sum);
		});

		counterMap1.entrySet()
		    .stream()
		    .filter(entry -> {
			    int number = entry.getKey();

			    if (!isValid(number)) {
				    return false;
			    }

			    return counterMap2.containsKey(number);
		    })
		    .limit(10)
		    .forEach(entry -> {
			    int number = entry.getKey();

			    int count = entry.getValue();
			    count += counterMap2.get(number);

			    System.out.printf("%d %d%n", number, count);
		    });
	}
}
