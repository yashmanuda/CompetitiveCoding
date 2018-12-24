int countLeaves(Node* root){
  if(root == NULL){
      return 0;
  } else{
      if(root->left == NULL && root->right == NULL){
          return 1;
      } else{
          return countLeaves(root->left) + countLeaves(root->right);
      }
  }
}
