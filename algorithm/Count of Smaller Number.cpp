// LI
// 248 Count of Smaller Number
// 249 Count of Smaller Number before itself
// 1297 Count of Smaller Number after itself

// Leetcode
// 315. Count of Smaller Numbers After Self


// method 1 sorting
// nlogn, TLE
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if(0 == n) return {};
        vector<int> ans(n, 0);
        multiset<int> visited;
        for(int i = n-1; i >= 0; --i)
        {
            // visited = {1, 2, 6}
            auto it = lower_bound(visited.begin(), visited.end(), nums[i]);
            ans[i] =  distance(visited.begin(), it);
            // ans = {1, 1, 0}
            visited.insert(it, nums[i]);
            
        }
        return ans;
    }
};


// method 2 merge sort
class Solution {
protected:
	void merge_countSmaller(vector<int>& indices, int first, int last,
		vector<int>& results, vector<int>& nums) {
		int count = last - first;
		if (count > 1) {
			int step = count / 2;
			int mid = first + step;
			merge_countSmaller(indices, first, mid, results, nums);
			merge_countSmaller(indices, mid, last, results, nums);
			vector<int> tmp;
			tmp.reserve(count);
			int idx1 = first;
			int idx2 = mid;
			int semicount = 0;
			while ((idx1 < mid) || (idx2 < last)) {
				if ((idx2 == last) || ((idx1 < mid) &&
					(nums[indices[idx1]] <= nums[indices[idx2]]))) {
					tmp.push_back(indices[idx1]);
					results[indices[idx1]] += semicount;
					++idx1;
				}
				else {
					tmp.push_back(indices[idx2]);
					++semicount;
					++idx2;
				}
			}
			move(tmp.begin(), tmp.end(), indices.begin() + first);
		}
	}
public:
	vector<int> countSmaller(vector<int> nums) {
		int n = nums.size();
		vector<int> results(n, 0);
		vector<int> indices(n, 0);
		iota(indices.begin(), indices.end(), 0);
		merge_countSmaller(indices, 0, n, results, nums);
		return results;
	}
};


// Method 3 Binary Index Tree
class BIT{
public:
    BIT(int n): d_bit(n+1) {
    }
    
    void update(int idx, int diff){
        while(idx < d_bit.size()){
            d_bit[idx] += diff;
            idx += lowbit(idx);
        }
    }
    
    int get(int idx){
        int ans = 0;
        while(idx > 0){
            ans += d_bit[idx];
            idx -= lowbit(idx);
        }
        return ans;
    }
    
private:
    int lowbit(int x){ return x & (-x); }
    vector<int> d_bit;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if(0 == n) { return {}; }
        
        // number from 1 to max_val
        int min_val = * min_element(nums.begin(), nums.end());
        int max_val = min_val;
        for(auto& num : nums){
            num = num - min_val + 1;
            max_val = max(max_val, num);
        }
        
        BIT bit(max_val);
        vector<int> ans(n);
        for(int i = n-1; i >= 0; --i){
            bit.update(nums[i], 1);
            ans[i] = bit.get(nums[i]-1);
        }
        return ans;
    }
};
