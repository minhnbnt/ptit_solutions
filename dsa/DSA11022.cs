using System;
using System.Linq;
using System.Collections.Generic;

class TreeNode {

	private int Value;
	private TreeNode Left = null;
	private TreeNode Right = null;

	private TreeNode(int x) => Value = x;

	private bool IsMiddle() => Left != null || Right != null;

	private static void InsertNode(ref TreeNode root, int value) {

		if (root == null) {
			root = new TreeNode(value);
			return;
		}

		if (value < root.Value) {
			InsertNode(ref root.Left, value);
		} else {
			InsertNode(ref root.Right, value);
		}
	}

	public int CountMiddleNodes() {

		int result = this.IsMiddle() ? 1 : 0;

		result += Left?.CountMiddleNodes() ?? 0;
		result += Right?.CountMiddleNodes() ?? 0;

		return result;
	}

	public static TreeNode GetTreeByInorder(IEnumerable<int> query) {

		TreeNode root = null;

		foreach (int element in query) {
			InsertNode(ref root, element);
		}

		return root;
	}
}

internal class Program {
	static void Main() {

		var cases = int.Parse(Console.ReadLine());

		for (; cases > 0; cases--) {

			var _size = int.Parse(Console.ReadLine());

			var query = Console //
			                .ReadLine()
			                .TrimEnd()
			                .Split()
			                .Select(int.Parse);

			var root = TreeNode.GetTreeByInorder(query);

			Console.WriteLine(root.CountMiddleNodes());
		}
	}
}
