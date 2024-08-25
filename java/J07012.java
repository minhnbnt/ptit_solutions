import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class J07012 {

	@SuppressWarnings("unchecked")
	public static void main(String[] args)
	    throws IOException, ClassNotFoundException {

		FileInputStream fileStream = new FileInputStream("DATA.in");
		ObjectInputStream objectStream = new ObjectInputStream(fileStream);

		Map<String, Integer> counterMap = new HashMap<>();

		try {

			Object stringList = objectStream.readObject();

			((List<String>)stringList)
			    .stream()
			    .parallel()
			    .map(s -> s.split("\\W+"))
			    .flatMap(Arrays::stream)
			    .filter(token -> !token.isEmpty())
			    .map(String::toLowerCase)
			    .forEachOrdered(token -> { //
				    counterMap.merge(token, 1, Integer::sum);
			    });

		} finally {
			objectStream.close();
		}

		counterMap.entrySet()
		    .stream()
		    .sorted((a, b) -> {
			    if (!a.getValue().equals(b.getValue())) {
				    return b.getValue().compareTo(a.getValue());
			    }

			    return a.getKey().compareTo(b.getKey());
		    })
		    .forEach((entry) -> {
			    String token = entry.getKey();
			    int count = entry.getValue();

			    System.out.printf("%s %d%n", token, count);
		    });
	}
}
