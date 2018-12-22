Node* LCAUtil(Node *root, int n1, int n2){
    if(root == NULL){
        return NULL;
    } else{
        if(n1 < root->data && n2 < root->data){
            return LCAUtil(root->left,n1,n2);
        }
        else if(n1 >= root->data && n2 >= root->data){
            if(n1 == root->data || n2 == root->data){
                return root;
            } else{
                return LCAUtil(root->right,n1,n2);
            }
        }
        else {
            return root;
        }
    }
}

Node* LCA(Node *root, int n1, int n2){
    return LCAUtil(root,n1,n2);
}
