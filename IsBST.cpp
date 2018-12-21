/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node {
    int data;
    Node* left, * right;
}; */
/* Should return true if tree represented by root is BST.
   For example, return  value should be 1 for following tree.
         20
     /      \
   10       30
  and return value should be 0 for following tree.
         10
     /      \
   20       30 */

bool isBSTUtil(Node* root, Node *&prev){
    if(root == NULL){
        return true;
    } else{
        if(!isBSTUtil(root->left, prev)){
            return false;
        }

        if( prev != NULL && root->data <= prev->data){
            return false;
        }

        prev = root;

        if (!isBSTUtil(root->right, prev)){
            return false;
        }

        return true;
    }
}

bool isBST(Node* root) {
    Node* prev = NULL;
    isBSTUtil(root, prev);
}
