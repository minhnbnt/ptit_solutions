import java.util.Scanner;

class Point {

	private final double x, y;

	Point(double x, double y) {
		this.x = x;
		this.y = y;
	}

	public double distance(Point other) {

		double xDiff = this.x - other.x;
		double yDiff = this.y - other.y;

		return Math.sqrt(xDiff * xDiff + yDiff * yDiff);
	}
}

class Triangle {

	private final boolean isValid;
	private final double perimeter;

	public Triangle(Point[] points) {

		assert points.length == 3;

		double ab = points[0].distance(points[1]);
		double bc = points[1].distance(points[2]);
		double ac = points[2].distance(points[0]);

		isValid = ab + bc > ac && ab + ac > bc && ac + bc > ab;

		if (!isValid) {
			perimeter = 0;
			return;
		}

		perimeter = ab + bc + ac;
	}

	public String toString() {
		return isValid //
		    ? String.format("%.3f", perimeter)
		    : "INVALID";
	}
}

public class Main {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		for (int cases = stdin.nextInt(); cases > 0; cases--) {

			Point[] points = new Point[3];

			for (int i = 0; i < 3; i++) {

				double x = stdin.nextDouble();
				double y = stdin.nextDouble();

				points[i] = new Point(x, y);
			}

			System.out.println(new Triangle(points));
		}
	}
}
