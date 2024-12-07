import java.util.Scanner;

class Vector3D {

	private final int x, y, z;

	public Vector3D(int x, int y, int z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}

	Vector3D(Point3D a, Point3D b) {
		this.x = a.getX() - b.getX();
		this.y = a.getY() - b.getY();
		this.z = a.getZ() - b.getZ();
	}

	public Vector3D crossProduct(Vector3D other) {

		return new Vector3D(this.y * other.z - this.z * other.y,
		                    this.z * other.x - this.x * other.z,
		                    this.x * other.y - this.y * other.x);
	}

	public int dotProduct(Vector3D other) {
		return this.x * other.x //
		    + this.y * other.y  //
		    + this.z * other.z;
	}
}

class Point3D {

	private final short x, y, z;

	Point3D(int x, int y, int z) {
		this.x = (short)x;
		this.y = (short)y;
		this.z = (short)z;
	}

	public static boolean check(                       //
	    Point3D p1, Point3D p2, Point3D p3, Point3D p4 //
	) {

		Vector3D v1 = new Vector3D(p2, p1);
		Vector3D v2 = new Vector3D(p3, p1);

		v1 = v1.crossProduct(v2);
		v2 = new Vector3D(p4, p1);

		return v1.dotProduct(v2) == 0;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	public int getZ() {
		return z;
	}
}

public class J04011 {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();

		while (t-- > 0) {

			Point3D p1 = new Point3D(sc.nextInt(), sc.nextInt(), sc.nextInt());
			Point3D p2 = new Point3D(sc.nextInt(), sc.nextInt(), sc.nextInt());
			Point3D p3 = new Point3D(sc.nextInt(), sc.nextInt(), sc.nextInt());
			Point3D p4 = new Point3D(sc.nextInt(), sc.nextInt(), sc.nextInt());

			if (Point3D.check(p1, p2, p3, p4)) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
		}

		sc.close();
	}
}
