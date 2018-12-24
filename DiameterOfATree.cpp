int height(Node* node){
   if(node == NULL){
       return 0;
   } else{
       return 1 + max(height(node->left) , height(node->right));
   }
}

int diameterUTIL(Node* node){
    if(node == NULL){
        return 0;
    } else{
        return max(max(diameterUTIL(node->left), diameterUTIL(node->right)), 1 + height(node->left) + height(node->right));
    }
}

int diameter(Node* node){
    return diameterUTIL(node);
}
