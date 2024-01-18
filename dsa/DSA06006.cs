using System;

class Program {

	static void Main() {

		int cases;
		int.TryParse(Console.ReadLine(), out cases);

		while (cases-- > 0) {

			int size;
			Int32.TryParse(Console.ReadLine(), out size);

			var array = Array.ConvertAll(
			    Console.ReadLine().Trim().Split(' '), int.Parse);
			Array.Sort(array);

			foreach (int element in array) {
				Console.Write(element + " ");
			}
			Console.Write('\n');
		}
	}
}
