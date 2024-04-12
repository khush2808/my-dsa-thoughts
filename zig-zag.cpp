vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        bool ltr = true;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int size = q.size();
            vector<int> row(size);
            for(int i = 0;i<size;i++){
                TreeNode* x = q.front();q.pop();
                if(x->left)q.push(x->left);
                if(x->right)q.push(x->right);
                row[i]=x->val;
            }
            if(!ltr)reverse(row.begin(),row.end());
            ans.push_back(row);
            ltr=!ltr;

        }
        return ans;
    }