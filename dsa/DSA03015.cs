using System;

class Solution {

	static void Main(string[] args) {

		uint cases;
		uint.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			string[] tokens = Console.ReadLine().Split();

			int foodPerDay = int.Parse(tokens[0]);
			int dayRemaining = int.Parse(tokens[1]);
			int foodRequiredPerDay = int.Parse(tokens[2]);

			int foodRequired = dayRemaining * foodRequiredPerDay;

			int dayCanBuy = dayRemaining - (dayRemaining / 7);
			int foodCanBuy = dayCanBuy * foodPerDay;

			if (foodRequired > foodCanBuy) {
				Console.WriteLine(-1);
				continue;
			}

			int maximumDayIgnore = (foodCanBuy - foodRequired) / foodPerDay;
			int minimumDayBuy = dayCanBuy - maximumDayIgnore;

			Console.WriteLine(minimumDayBuy);
		}
	}
}
