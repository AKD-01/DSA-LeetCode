class Solution {
public:
    using info=pair<TreeNode*, TreeNode*>;
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return root;
        constexpr int N=501;
        info q[N];
        TreeNode* x2T[N];// x -> TreeNode*
        int par[N]; // x -> parent->val
        int front=0, back=0;
        q[back++]={root, NULL};
        int d=0;
        int L=-1, R=-1;// leftmost, rightmost val in the same level
        for( ; front!=back; d++){
            int qz=back-front;
            for(int i=0; i<qz; i++){// all nodes in the level d
                auto [node, parent]=q[front++];
                int x=node->val;
                int y=(!parent)?-1:parent->val;
                par[x]=y;
                x2T[x]=node;
                if (i==0) L=x;// leftmost
                if (i==qz-1) R=x;// rightmost
                
                if (node->left) q[back++]={node->left, node};
                if (node->right) q[back++]={node->right, node};
            } 
        }
        if (L==R) return x2T[L];
        int s=L, t=R;
        while(s!=t){
            s=par[s];
            t=par[t];
        }
        return x2T[s];
    }
};