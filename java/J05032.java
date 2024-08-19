import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

class Person {

	public final String name;
	public final Date birth;

	public Person(String name, Date birth) {
		this.name = name;
		this.birth = birth;
	}

	public String getName() {
		return this.name;
	}

	public Date getBirth() {
		return this.birth;
	}
}

public class J05032 {
	public static void main(String[] args) throws ParseException {

		SimpleDateFormat format = new SimpleDateFormat("dd/MM/yyyy");

		Scanner stdin = new Scanner(System.in);

		int size = stdin.nextInt();
		List<Person> people = new ArrayList<>(size);

		while (people.size() < size) {

			String name = stdin.next();
			Date birth = format.parse(stdin.next());

			people.add(new Person(name, birth));
		}

		stdin.close();

		if (people.isEmpty()) return;

		Person youngest = people //
		                      .stream()
		                      .max(Comparator.comparing(Person::getBirth))
		                      .get();

		System.out.println(youngest.getName());

		Person oldest = people //
		                    .stream()
		                    .min(Comparator.comparing(Person::getBirth))
		                    .get();

		System.out.println(oldest.getName());
	}
}
