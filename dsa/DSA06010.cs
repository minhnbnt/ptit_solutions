using System;
using System.Linq;
using System.Collections.Generic;

internal class Program {
	public static void Main() {

		var cases = int.Parse(Console.ReadLine());

		for (; cases > 0; cases--) {

			int size;
			int.TryParse(Console.ReadLine(), out size);

			Console.ReadLine()
			    .TrimEnd()
			    .Split()
			    .SelectMany(num => num)
			    .Distinct()
			    .OrderBy(digit => digit)
			    .ToList()
			    .ForEach(digit => Console.Write("{0} ", digit));

			Console.Write('\n');
		}
	}
}
