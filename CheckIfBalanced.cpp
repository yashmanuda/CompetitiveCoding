int height(Node* root){
    if(root == NULL){
        return 0;
    } else{
        return 1 + max(height(root->left), height(root->right));
    }
}

bool isBalanced(Node *root){
    if(root == NULL){
        return true;
    } else{
        if( abs(height(root->left) - height(root->right)) > 1){
            return false;
        }
        if(!isBalanced(root->left) || !isBalanced(root->right)){
            return false;
        }
    }
    return true;
}
