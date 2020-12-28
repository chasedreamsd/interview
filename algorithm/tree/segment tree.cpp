
struct MyTreeNode
{
public:
	int sum;
	MyTreeNode* left;
	MyTreeNode* right;
	int st;
	int ed;
	MyTreeNode(int s, int start, int end, MyTreeNode* lp, MyTreeNode* rp)
		: sum(s), st(start), ed(end), left(lp), right(rp)
	{}
};


class NumArray {
public:
    NumArray(vector<int>& nums) {
        root = build(nums, 0, nums.size() - 1);
    }
    
    void update(int i, int val) {
        update(root, i, val);
    }
    
    int sumRange(int i, int j) {
        return range_query(root, i, j);
    }
private:
    MyTreeNode* root;
    MyTreeNode* build(const vector<int>& num, int st, int ed)
	{
        if(num.empty()) { return nullptr; }
		if (st == ed) { return new MyTreeNode(num[st], st, ed, nullptr, nullptr); }

		int mid = (st + ed) / 2;
		auto lp = build(num, st, mid);
		auto rp = build(num, mid + 1, ed);
		return new MyTreeNode(lp->sum + rp->sum, st, ed, lp, rp);
	}

	void update(MyTreeNode* root, int index, int val)
	{
		if (nullptr == root) { return;  }
		if(root->st == root->ed)
		{
			if (root->st == index) { root->sum = val; } 
			return; 
		}

		int mid = (root->st + root->ed) / 2;
		if (index <= mid) { update(root->left, index, val);  }
		else { update(root->right, index, val); }
		root->sum = root->left->sum + root->right->sum;
	}

	int range_query(MyTreeNode* root, int st, int ed)
	{
		if (nullptr == root) { return 0; }
		if(root->st == st && root->ed == ed)
		{
			return root->sum;
		}

		int mid = (root->st + root->ed) / 2;
		if (ed <= mid) { return range_query(root->left, st, ed); }
		else if (st > mid) { return range_query(root->right, st, ed); }
		else { return range_query(root->left, st, mid) + range_query(root->right, mid + 1, ed); }
	}
};
