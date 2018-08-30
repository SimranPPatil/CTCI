package Trees_Graphs;

public class BinarySearchTree {

	public static void main(String[] args) {
		int[] arr = { 3, 5, 7, 9, 11 };
		search(arr);
		
	}

	// array passed in would be sorted and will have unique elements
	public static Node search(int[] arr) {
		return binarySearchTree(arr, 0, arr.length - 1);
	}

	public static Node binarySearchTree(int[] arr, int left, int right) {

		// base case -- if right index is smaller than left index, return null
		if (right < left)
			return null;
		// find the middle index
		int mid_idx = (left + right) / 2;
		Node root = new Node(arr[mid_idx]);
		System.out.println("root: " +root.data);
		
		root.leftchild = binarySearchTree(arr, left, mid_idx - 1);
		if(root.leftchild != null)
			System.out.println("left children: " + root.leftchild.data);
		root.rightchild = binarySearchTree(arr, mid_idx + 1, right);
		if(root.leftchild != null)
			System.out.println("right children: " +root.rightchild.data);
		//System.out.println(root.data);
		return root;
	}

	public static class Node {
		int data;
		Node leftchild;
		Node rightchild;

		public Node(int i) {
			this.data = i;

		}
	}

}
