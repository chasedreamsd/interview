
// 931. K 个有序数组的中位数
// 有 k 个有序数组 nums。找到这 k 个有序数组的中位数。

class Solution {
public:
    /**
     * @param nums: the given k sorted arrays
     * @return: the median of the given k sorted arrays
     */
    double findMedian(vector<vector<int>> &nums) {
        // write your code here
        if(0 == nums.size()) { return 0; }
        int left = INT_MAX, right = INT_MIN, n = 0;
        for(auto& num : nums){
            if(!num.empty()){
                left = min(left, num.front());
                right = max(right, num.back());
            }
            n += num.size();
        }
        if(0 == n) { return 0; }
        if(n%2){
            return findKth(nums, n/2 + 1, left, right);
        }
        else{
            return findKth(nums, n/2, left, right)/2.0 + findKth(nums, n/2 + 1, left, right)/2.0;
        }
    }
    
    int findKth(vector<vector<int>>& nums, int k, int left, int right){
        
        while(left + 1 < right){
            int mid = left + (right-left)/2;
            if(gte(nums, mid) >= k){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        return gte(nums, right) >= k ? right : left;
    }
    
    int gte(vector<vector<int>>& nums, int val){
        int cnt = 0;
        for(auto& num : nums){
            if(!num.empty()){
                auto it = lower_bound(num.begin(), num.end(), val);
                cnt += distance(it, num.end());
            }
        }
        return cnt;
    }
};
