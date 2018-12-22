void printSpiral(Node *root)
{
     queue<pair<Node*, int>> levelOrder;
     levelOrder.push(make_pair(root,0));

     map<int, vector<int>> levelNodeMap;
     pair<Node*, int> tempNode = levelOrder.front();

     while(tempNode.first != NULL){
         levelNodeMap[tempNode.second].push_back(tempNode.first->data);

         if(tempNode.first->left != NULL){
             levelOrder.push(make_pair(tempNode.first->left, tempNode.second + 1));
         }

         if(tempNode.first->right != NULL){
             levelOrder.push(make_pair(tempNode.first->right, tempNode.second + 1));
         }

         levelOrder.pop();

         if(!levelOrder.empty()){
             tempNode = levelOrder.front();
         } else{
             tempNode.first = NULL;
         }
     }
     bool isLeft = true;
     for(auto it = levelNodeMap.begin(); it != levelNodeMap.end(); ++it){
         if(isLeft){
             for(auto itr = it->second.rbegin(); itr != it->second.rend(); ++itr ){
                 cout << (*itr) << " ";
             }
         } else{
             for(auto itrf = it->second.begin(); itrf != it->second.end(); ++itrf ){
                 cout << (*itrf) << " ";
             }
         }
         isLeft = !isLeft;
     }

     return;
}
