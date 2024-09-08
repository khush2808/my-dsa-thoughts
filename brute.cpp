#include <bits/stdc++.h>

using namespace std;

struct Node {
  int data;
  Node * left, * right;
  Node(int val) {
    data = val;
    left = right = NULL;
  }
};
class Solution {

  public:

    // This function does inorder traversal to find out the two swapped nodes.
    // It sets three pointers, first, middle and last.  If the swapped nodes are
    // adjacent to each other, then first and middle contain the resultant nodes
    // Else, first and last contain the resultant nodes
    

  // A function to fix a given BST where two nodes are swapped.  This
  // function uses correctBSTUtil() to find out two nodes and swaps the
  // nodes to fix the BST
   Node * correctBST( Node * root) {
    // Initialize pointers needed for correctBSTUtil()
		vector<int> traversal;
		inorder(root,traversal);
		buildtree(root,traversal)
     
  }
};

bool sorted(vector < int > arr) {
  for (int i = 0; i < arr.size() - 1; i++) {
    if (arr[i] > arr[i + 1]) return false;
  }
  return true;
}

void inorder(Node * root, vector < int > & traversal) {
  // Check if the current node
  // is null (base case for recursion)
  if (root == nullptr) {
    // If null, return and
    // terminate the function
    return;
  }

  // Recursively call inorder
  // for the left subtree
  inorder(root -> left, traversal);

  // Print the value of the current node
  traversal.push_back(root -> data);
  // Recursively call inorder
  // for the right subtree
  inorder(root -> right, traversal);
}

int main() {

  // Creating a BST
  Node * root = new Node(3);
  root -> left = new Node(1);
  root -> right = new Node(4);
  root -> right -> left = new Node(2);

  Solution solution;

  int target = 8;
  Node * ans = solution.correctBST(root);
  vector < int > traversal;
  inorder(ans, traversal);
  if (sorted(traversal)) {
    cout << "You sucessfully swapped the nodes";
  } else {
    cout << "Error. Wrong answer.";
  }

  return 0;
}