import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Traveler {

	private final int arrive, duration;

	Traveler(int arrive, int duration) {
		this.duration = duration;
		this.arrive = arrive;
	}

	public int getArrive() {
		return arrive;
	}

	public int getDuration() {
		return duration;
	}
}

public class Main {
	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int size = stdin.nextInt();
		Traveler[] travelers = new Traveler[size];

		for (int i = 0; i < size; i++) {

			int arrive = stdin.nextInt();
			int duration = stdin.nextInt();

			travelers[i] = new Traveler(arrive, duration);
		}

		Arrays.sort(travelers, Comparator.comparing(Traveler::getArrive));

		int result = 0;
		for (Traveler t : travelers) {
			result = Math.max(result, t.getArrive());
			result += t.getDuration();
		}

		System.out.println(result);
	}
}
