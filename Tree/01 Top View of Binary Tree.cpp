/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void find(Node* root, int pos, int& left, int& right)
    {
        if(!root) return ;
        left= min(left, pos);
        right=max(right, pos);
        find(root->left, pos-1,left,right);
        find(root->right, pos+1, left, right);
    }
    vector<int> topView(Node *root) {
        
        // code here
        int left=0;
        int right=0;
        find(root,0,left,right);
        vector<int>result(right-left+1);
        vector<bool>filled(right-left+1, false);
        if(!root) return result;
        queue<pair<Node *,int>>q;
        q.push({root , -1*left});
        
        while(!q.empty())
        {
            pair<Node* ,int> p=q.front();
            // auto [node,idx]=q.top();
            q.pop();
            
            if(!filled[p.second])
            {
                result[p.second]=p.first->data;
                filled[p.second]=true;
            }
            
            if(p.first->left) q.push({p.first->left ,p.second-1 });
            if(p.first->right) q.push({p.first->right ,p.second+1 });
            
        }
        
        
        return result;
        
    }
};
