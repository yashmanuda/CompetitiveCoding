void bottomView(Node *root)
{
    queue<pair<Node*,int>> levelOrder;
    levelOrder.push(make_pair(root,0));
    pair<Node*,int> tempNode = levelOrder.front();
    map<int,int> TreeMap;
    while(tempNode.first != NULL){
        TreeMap[tempNode.second] = tempNode.first->data;
        if(tempNode.first->left != NULL){
            levelOrder.push(make_pair(tempNode.first->left,tempNode.second - 1));
        }
        if(tempNode.first->right != NULL){
            levelOrder.push(make_pair(tempNode.first->right,tempNode.second + 1));
        }

        levelOrder.pop();
        if(!levelOrder.empty()){
            tempNode = levelOrder.front();
        } else{
            tempNode.first = NULL;
        }
    }

    for(map<int,int>::iterator it = TreeMap.begin(); it != TreeMap.end(); ++it){
        cout << it->second <<" ";
    }
    return;
}
