import java.util.Scanner;

class Complex {

	private final int real, imaginary;

	Complex(int real, int image) {
		this.imaginary = image;
		this.real = real;
	}

	public Complex add(Complex other) {

		int imaginary = this.imaginary + other.imaginary;
		int real = this.real + other.real;

		return new Complex(real, imaginary);
	}

	public Complex multiple(Complex other) {

		int real = this.real * other.real;
		real -= this.imaginary * other.imaginary;

		int imaginary = this.real * other.imaginary;
		imaginary += this.imaginary * other.real;

		return new Complex(real, imaginary);
	}

	@Override
	public String toString() {
		return String.format("%d + %di", real, imaginary);
	}
}

public class J04018 {
	public static void main(String[] args) {
		try (Scanner stdin = new Scanner(System.in)) {

			int cases = stdin.nextInt();

			for (; cases > 0; cases--) {

				int real = stdin.nextInt();
				int imaginary = stdin.nextInt();

				Complex a = new Complex(real, imaginary);

				real = stdin.nextInt();
				imaginary = stdin.nextInt();

				Complex b = new Complex(real, imaginary);

				Complex sum = a.add(b);

				Complex c = sum.multiple(a);
				Complex d = sum.multiple(sum);

				System.out.printf("%s, %s%n", c, d);
			}
		}
	}
}
