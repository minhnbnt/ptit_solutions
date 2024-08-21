import java.io.IOException;
import java.util.Arrays;

class TimePoint implements Comparable<TimePoint> {

	private final int hour, minute, second;

	public TimePoint(int hour, int minute, int second) {
		this.hour = hour;
		this.minute = minute;
		this.second = second;
	}

	public int totalSeconds() {
		return hour * 3600 + minute * 60 + second;
	}

	@Override
	public int compareTo(TimePoint other) {
		return this.totalSeconds() - other.totalSeconds();
	}

	@Override
	public String toString() {
		return String.format("%d %d %d", hour, minute, second);
	}
}

public class J05033 {
	public static void main(String[] args) {

		int size = Utils.nextInt();

		TimePoint[] timePoints = new TimePoint[size];
		for (int i = 0; i < size; i++) {

			int hour = Utils.nextInt();
			int minute = Utils.nextInt();
			int second = Utils.nextInt();

			timePoints[i] = new TimePoint(hour, minute, second);
		}

		Arrays.stream(timePoints).sorted().forEach(System.out::println);
	}
}

class Utils {
	public static int nextInt() {

		int result = 0;

		while (true) {

			int c;
			try {
				c = System.in.read();
			} catch (IOException e) {
				return 0;
			}

			if (!Character.isDigit(c)) {
				break;
			}

			result = result * 10 + c - '0';
		}

		return result;
	}
}
