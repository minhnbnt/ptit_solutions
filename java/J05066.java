import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Staff implements Comparable<Staff> {

	private final String id, name;

	public Staff(String id, String name) {
		this.id = id;
		this.name = name;
	}

	public String getName() {
		return this.name;
	}

	public Integer getSalaryCoefficient() {
		return Integer.parseInt(id.substring(2, 4));
	}

	public Integer getPosition() {
		return Integer.parseInt(id.substring(4));
	}

	public boolean isWrong() {

		String role = this.id.substring(0, 2);
		int position = this.getPosition();

		if (role.equals("GD") && position > 1) {
			return true;
		}

		if (!role.equals("NV") && position > 3) {
			return true;
		}

		return false;
	}

	public String getRole() {
		return this.isWrong() ? "NV" : id.substring(0, 2);
	}

	@Override
	public String toString() {
		return String.format("%s %s %03d %02d", //
		                     name, getRole(), getPosition(),
		                     getSalaryCoefficient());
	}

	@Override
	public int compareTo(Staff other) {

		if (this.getSalaryCoefficient().equals(other.getSalaryCoefficient())) {
			return this.getPosition().compareTo(other.getPosition());
		}

		return other.getSalaryCoefficient().compareTo(
		    this.getSalaryCoefficient());
	}
}

public class J05066 {

	static Scanner stdin = new Scanner(System.in);

	public static void main(String[] args) {

		int size = stdin.nextInt();
		stdin.skip("\\s+");

		List<Staff> staffList = new ArrayList<>(size);

		while (staffList.size() < size) {

			String line = stdin.nextLine();

			String id = line.substring(0, 7);
			String name = line.substring(8);

			staffList.add(new Staff(id, name));
		}

		staffList.sort(Comparator.naturalOrder());

		int query = stdin.nextInt();
		stdin.skip("\\s+");

		for (; query > 0; query--) {

			String target = stdin.nextLine();
			String regex = String.format("(?i).*%s.*", target);

			Pattern pattern = Pattern.compile(regex);

			staffList.stream()
			    .filter(staff -> {
				    String name = staff.getName();
				    Matcher matcher = pattern.matcher(name);

				    return matcher.matches();
			    })
			    .forEach(System.out::println);

			System.out.printf("%n");
		}
	}
}
