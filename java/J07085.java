import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.util.List;

public class J07085 {

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws Exception {

		FileInputStream fileStream = new FileInputStream("DATA.in");
		ObjectInputStream objectStream = new ObjectInputStream(fileStream);

		Object stringList = objectStream.readObject();
		objectStream.close();

		((List<String>)stringList)
		    .stream()
		    .map(Utils::getNumber)
		    .forEach(number -> {
			    int sumOfDigit = number //
			                         .codePoints()
			                         .map(digit -> digit - '0')
			                         .sum();

			    System.out.printf("%s %d%n", number, sumOfDigit);
		    });
	}
}

class Utils {
	public static String getNumber(String s) {

		StringBuilder builder = new StringBuilder();
		s.codePoints()
		    .filter(Character::isDigit)
		    .forEachOrdered(builder::appendCodePoint);

		/* yes, when number is zero it return empty string
		 * "0" will cause WA :0 */
		while (builder.charAt(0) == '0') {
			builder.deleteCharAt(0);
		}

		return builder.toString();
	}
}
