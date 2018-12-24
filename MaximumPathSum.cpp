int maxSumTree(Node *root){
    if(root == NULL){
        return 0;
    } else{
        return root->data + max(maxSumTree(root->left),maxSumTree(root->right));
    }
}

int maxPathSumUTIL(Node* root){
    if(root == NULL){
        return 0;
    } else{
        return max(max(maxPathSumUTIL(root->left),maxPathSumUTIL(root->right)) , root->data + maxSumTree(root->left) + maxSumTree(root->right));
    }
}

int maxPathSum(struct Node *root){
    return maxPathSumUTIL(root);
}
