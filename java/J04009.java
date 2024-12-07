import java.util.Scanner;

class Point {

	private final double x;
	private final double y;

	Point(double x, double y) {
		this.x = x;
		this.y = y;
	}

	public static Point nextPoint(Scanner sc) {

		double x = sc.nextDouble();
		double y = sc.nextDouble();

		return new Point(x, y);
	}

	public double distanceTo(Point other) {

		double xDiff = this.x - other.x;
		double yDiff = this.y - other.y;

		return Math.sqrt((xDiff * xDiff) + (yDiff * yDiff));
	}
}

class Triangle {

	private final Point a, b, c;

	Triangle(Point a, Point b, Point c) {
		this.a = a;
		this.b = b;
		this.c = c;
	}

	public boolean isValid() {

		double ab = a.distanceTo(b);
		double ac = a.distanceTo(c);
		double bc = b.distanceTo(c);

		return ab + bc > ac && ab + ac > bc && ac + bc > ab;
	}

	public double getArea() {

		double ab = a.distanceTo(b);
		double ac = a.distanceTo(c);
		double bc = b.distanceTo(c);

		// clang-format off
		return Math.sqrt(
			  (ab + bc + ac)
			* (ab + bc - ac)
			* (ab - bc + ac)
			* (bc - ab + ac)
		) / 4;
		// clang-format on
	}
}

public class J04009 {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();

		while (t-- > 0) {

			Triangle a = new Triangle(Point.nextPoint(sc), //
			                          Point.nextPoint(sc), //
			                          Point.nextPoint(sc));

			if (a.isValid()) {
				System.out.printf("%.2f%n", a.getArea());
			} else {
				System.out.println("INVALID");
			}
		}
	}
}
