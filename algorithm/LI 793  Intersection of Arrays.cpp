
// without duplicate
class Solution {
public:
    /**
     * @param arrs: the arrays
     * @return: the number of the intersection of the arrays
     */
    int intersectionOfArrays(vector<vector<int>> &arrs) {
        // write your code here
        int m = arrs.size();
        if(0 == m) {return 0;};
        
        unordered_map<int,int> umap;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < arrs[i].size(); ++j)
            {
                umap[arrs[i][j]] ++;
            }
        }
        
        int ans = 0;
        for(auto p : umap)
        {
            ans += (p.second == m ? 1 : 0);
        }
        return ans;
    }
};


// with duplicate 
class SolutionII{
	vector<int> intersect2arrays(vector<int>& v1, vector<int>& v2) {
		vector<int> ans;
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		for (int i = 0, j = 0; i < v1.size() && j < v2.size();) {
			if (v1[i] == v2[j]) {
				ans.push_back(v1[i]);
				++i, ++j;
			}
			else if (v1[i] < v2[j]) {
				++i;
			}
			else {
				++j;
			}
		}
		return ans;
	}


	vector<int> merge(vector<vector<int>>& nums, int left, int right) {
		if (left == right) {
			return nums[left];
		}
		int mid = (left + right) / 2;
		auto v1 = merge(nums, left, mid);
		auto v2 = merge(nums, mid + 1, right);
		return intersect2arrays(v1, v2);
	}

	vector<int> intersect(vector<vector<int>>& nums) {
		// sort


		auto ans = merge(nums, 0, nums.size() - 1);
		return ans;
	}
}

