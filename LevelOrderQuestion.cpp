void levelOrder(Node* node){
    queue<pair<Node*, int>> level;
    level.push(make_pair(node,0));
    pair<Node*, int> tempNode = level.front();

    while(tempNode.first != NULL){
        cout << tempNode.first->data << " ";

        if(tempNode.first->left != NULL){
            level.push(make_pair(tempNode.first->left,tempNode.second + 1));
        }

        if(tempNode.first->right != NULL){
            level.push(make_pair(tempNode.first->right,tempNode.second + 1));
        }

        level.pop();

        if(!level.empty()){
            tempNode = level.front();
        } else{
            tempNode.first = NULL;
        }
    }
}
