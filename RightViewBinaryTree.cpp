void rightView(Node *root)
{
   queue<pair<Node*, int>> levelOrder;
   levelOrder.push(make_pair(root,0));
   pair<Node*, int> tempNode = levelOrder.front();
   // level , data
   map<int,int> TreeMap;

   while(tempNode.first != NULL){
       if(TreeMap.find(tempNode.second) == TreeMap.end()){
           TreeMap[tempNode.second] = tempNode.first->data;
       }

       if(tempNode.first->right != NULL){
           levelOrder.push(make_pair(tempNode.first->right,tempNode.second + 1));
       }
       if(tempNode.first->left != NULL){
           levelOrder.push(make_pair(tempNode.first->left,tempNode.second + 1));
       }

       levelOrder.pop();

       if(!levelOrder.empty()){
           tempNode = levelOrder.front();
       } else{
           tempNode.first = NULL;
       }
   }

   for(auto x : TreeMap){
       cout << x.second << " ";
   }
   return;
}
