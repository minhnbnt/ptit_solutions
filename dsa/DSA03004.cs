using System;
using System.Linq;
using System.Collections.Generic;

public class Program
{

	static long SmallestSum(List<int> digits)
	{

		int size = digits.Count;

		long result = 0;
		if (size % 2 == 0)
		{

			for (int i = 1; i < size; i += 2)
			{
				result *= 10;
				result += digits[i - 1] + digits[i];
			}

			return result;
		}

		result += digits[0];
		for (int i = 2; i < size; i += 2)
		{
			result *= 10;
			result += digits[i - 1] + digits[i];
		}

		return result;
	}

	static void Main(string[] args)
	{

		uint cases;
		uint.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0)
		{

			int size = int.Parse(Console.ReadLine());

			List<int> digits = Console.ReadLine()
								   .TrimEnd()
								   .Split()
								   .Select(int.Parse)
								   .OrderBy(x => x)
								   .ToList();

			Console.WriteLine(SmallestSum(digits));
		}
	}
}