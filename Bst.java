import java.util.ArrayList;
import java.util.List;

class Node {
    int data;
    Node left;
    Node right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}

class Solution {

    private Node first = null;
    private Node middle = null;
    private Node last = null;
    private Node prev = null;

    // This function does inorder traversal to find out the two swapped nodes.
    // It sets three pointers, first, middle and last. 
    // If the swapped nodes are adjacent to each other, then first and middle contain the resultant nodes
    // Else, first and last contain the resultant nodes
    private void correctBSTUtil(Node root) {
        if (root != null) {
            // Recur for the left subtree
            correctBSTUtil(root.left);

            // If this node is smaller than the previous node, it's violating
            // the BST rule.
            if (prev != null && root.data < prev.data) {

                // If this is first violation, mark these two nodes as
                // 'first' and 'middle'
                if (first == null) {
                    first = prev;
                    middle = root;
                }

                // If this is second violation, mark this node as last
                else
                    last = root;
            }

            // Mark this node as previous
            prev = root;

            // Recur for the right subtree
            correctBSTUtil(root.right);
        }
    }

    // A function to fix a given BST where two nodes are swapped. This
    // function uses correctBSTUtil() to find out two nodes and swaps the
    // nodes to fix the BST
    public Node correctBST(Node root) {
        // Initialize pointers needed for correctBSTUtil()
        correctBSTUtil(root);

        // Fix (or correct) the tree
        if (first != null && last != null) {
            int temp = first.data;
            first.data = last.data;
            last.data = temp;
        } else if (first != null && middle != null) { // Adjacent nodes swapped
            int temp = first.data;
            first.data = middle.data;
            middle.data = temp;
        }

        // else nodes have not been swapped, passed tree is really BST.
        return root;
    }
}

class BinarySearchTree {

    public static boolean sorted(List<Integer> arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr.get(i) > arr.get(i + 1)) return false;
        }
        return true;
    }

    public static void inorder(Node root, List<Integer> traversal) {
        // Check if the current node
        // is null (base case for recursion)
        if (root == null) {
            // If null, return and
            // terminate the function
            return;
        }

        // Recursively call inorder
        // for the left subtree
        inorder(root.left, traversal);

        // Print the value of the current node
        traversal.add(root.data);

        // Recursively call inorder
        // for the right subtree
        inorder(root.right, traversal);
    }

    public static void main(String[] args) {

        // Creating a BST
        Node root = new Node(3);
        root.left = new Node(1);
        root.right = new Node(4);
        root.right.left = new Node(2);

        Solution solution = new Solution();

        List<Integer> traversal = new ArrayList<>();
        solution.correctBST(root);
        inorder(root, traversal);
        if (sorted(traversal)) {
            System.out.println("You sucessfully swapped the nodes");
        } else {
            System.out.println("Error. Wrong answer.");
        }
    }
}
