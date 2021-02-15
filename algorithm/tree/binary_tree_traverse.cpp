struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v),left(nullptr), right(nullptr) {}
};


// https://www.geeksforgeeks.org/iterative-preorder-traversal/
void preorder(TreeNode* root) {
    if(!root) { return; }
    
    stack<TreeNode*> stk;
    stk.push(root);
    while(!stk.empty()){
        auto cur = stk.top(); stk.pop();
        cout << cur->val << endl; // process node
        if(cur->right) stk.push(cur->right);
        if(cur->left) stk.push(cur->left);
    }
    return;
}

// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
void inorder(TreeNode* root){
    if(!root) { return; }
    stack<TreeNode*> stk;
    TreeNode* cur = root;
    while(!stk.empty() || cur){
        while(cur){
            stk.push(cur);
            cur = cur->left;
        }
        
        cur = stk.top(); stk.pop();
        cout << cur->val << endl;
        cur = cur->right;
    }
    return;
}

// https://www.geeksforgeeks.org/iterative-postorder-traversal/
// https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/
void postorder(){
    if (nullptr == root) 
        return; 
     
    stack<TreeNode*> stk; 
    do
    { 
        // Move to leftmost node 
        while (root) 
        { 
            // Push root's right child and then root to stack. 
            if (root->right){ 
                stk.push(root->right); 
            }
            stk.push(root); 
 
            // Set root as root's left child 
            root = root->left; 
        } 
 
        // Pop an item from stack and set it as root     
        root = stk.top(); stk.pop() 
 
        // If the popped item has a right child and the right child is not 
        // processed yet, then make sure right child is processed before root 
        if (root->right && stk.top() == root->right) 
        { 
            stk.pop(); // remove right child from stack 
            stk.push(root); // push root back to stack 
            root = root->right; // change root so that the right 
                                // child is processed next 
        } 
        else // Else print root's data and set root as NULL 
        { 
            printf("%d ", root->val); 
            root = NULL; 
        } 
    } while (!isEmpty(stack)); 
}












































