import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

enum ScholarShipType { XUATSAC, GIOI, KHA, KHONG }

class Student {

	private final String name;
	private final double GPA;
	private final int trainingPoint;

	private ScholarShipType scholarShip = ScholarShipType.KHONG;

	public Student(String name, double gpa, int trainingPoint) {
		this.name = name;
		GPA = gpa;
		this.trainingPoint = trainingPoint;
	}

	public void setScholarShip(ScholarShipType scholarShip) {
		this.scholarShip = scholarShip;
	}

	public int getTrainingPoint() {
		return trainingPoint;
	}

	public double getGPA() {
		return GPA;
	}

	@Override
	public String toString() {
		return String.format("%s: %s", name, scholarShip);
	}
}

public class Main {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int size = stdin.nextInt();
		int entries = stdin.nextInt();

		Student[] students = new Student[size];
		for (int i = 0; i < size; i++) {

			stdin.skip("\\s+");

			String name = stdin.nextLine();
			double GPA = stdin.nextDouble();
			int trainingPoint = stdin.nextInt();

			students[i] = new Student(name, GPA, trainingPoint);
		}

		double lowestGPA = Arrays.stream(students)
		                       .sorted(Comparator.comparing(Student::getGPA))
		                       .limit(entries)
		                       .reduce((a, b) -> b)
		                       .map(Student::getGPA)
		                       .orElse(Double.MIN_VALUE);

		for (Student s : students) {

			if (s.getGPA() < lowestGPA) {
				continue;
			}

			if (s.getGPA() >= 3.6 && s.getTrainingPoint() >= 90) {
				s.setScholarShip(ScholarShipType.XUATSAC);
			} else if (s.getGPA() >= 3.2 && s.getTrainingPoint() >= 80) {
				s.setScholarShip(ScholarShipType.GIOI);
			} else if (s.getGPA() >= 2.5 && s.getTrainingPoint() >= 70) {
				s.setScholarShip(ScholarShipType.KHA);
			}
		}

		for (Student s : students) {
			System.out.println(s);
		}
	}
}
