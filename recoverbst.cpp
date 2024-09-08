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
    void correctBSTUtil( Node * root,  Node ** first,
       Node ** middle,  Node ** last,
       Node ** prev) {
      if (root) {
        // Recur for the left subtree
        correctBSTUtil(root -> left, first, middle, last, prev);

        // If this node is smaller than the previous node, it's violating
        // the BST rule.
        if ( * prev && root -> data < ( * prev) -> data) {

          // If this is first violation, mark these two nodes as
          // 'first' and 'middle'
          if (! * first) {
            * first = * prev;
            * middle = root;
          }

          // If this is second violation, mark this node as last
          else
            *
            last = root;
        }

        // Mark this node as previous
        * prev = root;

        // Recur for the right subtree
        correctBSTUtil(root -> right, first, middle, last, prev);
      }
    }

  // A function to fix a given BST where two nodes are swapped.  This
  // function uses correctBSTUtil() to find out two nodes and swaps the
  // nodes to fix the BST
  struct Node * correctBST(struct Node * root) {
    // Initialize pointers needed for correctBSTUtil()
    struct Node * first, * middle, * last, * prev;
    first = middle = last = prev = NULL;

    // Set the poiters to find out two nodes
    correctBSTUtil(root, & first, & middle, & last, & prev);

    // Fix (or correct) the tree
    if (first && last)
      swap((first -> data), (last -> data));
    else if (first && middle) // Adjacent nodes swapped
      swap((first -> data), (middle -> data));

    // else nodes have not been swapped, passed tree is really BST.
    return root;
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