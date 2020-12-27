// LI 41 Maximum Subarray
// 给定一个整数数组，找到一个具有最小和的连续子数组。返回其最小和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) { return 0; }
        int ans = nums.front(), prev_sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            prev_sum = max(prev_sum, 0) + nums[i];
            ans = max(ans, prev_sum);
        }
        return ans;
    }
};

// LI 42 Maximum Subarray II
// 给定一个整数数组，找出两个 不重叠 子数组使得它们的和最大。 每个子数组的数字在数组中的位置应该是连续的。返回最大的和
// 输入: [1, 3, -1, 2, -1, 2], 输出: 7
// 解释: 最大的子数组为 [1, 3] 和 [2, -1, 2] 或者 [1, 3, -1, 2] 和 [2].
class Solution {
public:
    int maxTwoSubArrays(vector<int> &nums) {
        // write your code here
        if(nums.empty()) { return 0; }
        
        int n = nums.size();
        vector<int> left(n, 0);
        int ans = nums.front(), prev_sum = 0;
        for(int i = 0; i < n; ++i){
            prev_sum = max(prev_sum, 0) + nums[i];
            ans = max(ans, prev_sum);
            left[i] = ans;
        }
        
        vector<int> right(n, 0);
        ans = nums.back(), prev_sum = 0;    
        for(int i = n-1; i >= 0; --i){
            prev_sum = max(prev_sum, 0) + nums[i];
            ans = max(ans, prev_sum);
            right[i] = ans;
        }
        
        ans = INT_MIN;
        for(int i = 0; i < n-1; ++i){
            ans = max(ans, left[i] + right[i+1]);
        }
        return ans;
    }
    
};

// LI44 minimux subarray
// 给定一个整数数组，找到一个具有最小和的连续子数组。返回其最小和。
// 输入：[1, -1, -2, 1], 输出：-3
class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: A integer indicate the sum of minimum subarray
     */
    int minSubArray(vector<int> &nums) {
        if(nums.empty()) { return 0; }
        int prev_sum = 0, ans = nums.front();
        for(auto& n : nums){
            prev_sum = min(0, prev_sum) + n;
            ans = min(ans, prev_sum);
        }
        return ans;
    }
};

// LI 43 Maximum Subarray III
// 输入: List = [-1,4,-2,3,-2,3], k = 2
// 输出: 8, 说明: 4 + (3 + -2 + 3) = 8
// local[i][j]表示整数数组nums的前i个元素被分成j个不重叠子数组时的最大值（必须选取元素nums[i]）。
// global[i][j]表示整数数组nums的前i个元素被分成j个不重叠子数组时的最大值（不一定选取元素nums[i]）
int maxSubarray3(const vector<int>& nums, int k) {
	if (nums.size() < k) {
		return 0;
	}

	int n = nums.size();
	vector<vector<int>> local(k+1, vector<int>(n+1, INT_MIN)), global(k+1, vector<int>(n+1, INT_MIN));

	int prev_sum = 0;
	local[1][0] = 0;
	for (int i = 1; i <= n; ++i) {
		local[1][i] = local[1][i-1] + nums[i-1];
		prev_sum = max(prev_sum, 0) + nums[i-1];
		global[1][i] = max(global[1][i-1], prev_sum);
	}

	for (int i = 2; i <= k; ++i) {
		for (int j = i; j <= n; ++j) {
			if (j == i) {
				local[i][j] = local[1][j];
				global[i][j] = local[1][j];
			}
			else {
        // local[i-1][j]表示nums[i]加入上一个子数组成为一部分
        // global[i-1][j-1]表示nums[i]重新开始一个新的子数组
        // 第 i 个元素贪心地选择自己加入第 j-1 组还是自己成为独立第 j 组
				local[i][j] = max(local[i][j - 1], global[i - 1][j - 1]) + nums[j - 1];
        // 全局贪心的选择包括第 i 个元素的还是不包括第 i 个元素的情况
				global[i][j] = max(global[i][j - 1], local[i][j]);
			}
		}
	}
	return global[k][n];
}



// LI 620 Maximum Subarray IV
// 给定一个整数数组，找到长度大于或等于 k 的连续子序列使它们的和最大，返回这个最大的和，如果数组中少于k个元素则返回 0
// 输入: [-2,2,-3,4,-1,2,1,-5,3] 5, 输出: 5
// 解释: [2,-3,4,-1,2,1], sum=5

int maxSubarray4(const vector<int>& nums, int k) {	
	int n = nums.size();
  if (n < k) { return 0; }
	
  int cur_sum = 0;
  for (int i = 0; i < k && i < n; ++i) {
		cur_sum += nums[i];
	}

  // pre_k_sum: sum of nums[0] ... nums[i-k], min_k_sum, min of pre_k_sum
	int min_k_sum = INT_MAX, pre_k_sum = 0, ans = INT_MIN;
	for (int i = k; i < n; ++i) {
		pre_k_sum += nums[i - k];
		min_k_sum = min(min_k_sum, pre_k_sum);
		cur_sum += nums[i];
		ans = max(ans, cur_sum - min_k_sum);
	}
	return ans;
}

// LI45 Maximum subarray difference.
// 给定一个整数数组，找出两个不重叠的子数组A和B，使两个子数组和的差的绝对值|SUM(A) - SUM(B)|最大。返回这个最大的差值。
// 输入:[1, 2, -3, 1] 输出:6, 解释: 子数组是 [1,2] 和[-3].所以答案是 6.
class Solution {
public:
    int maxDiffSubArrays(vector<int> &nums) {
        int n = nums.size();
        
        vector<int> left_min(n), left_max(n);
        int pre_sum_min = 0, pre_sum_max = 0, cur_min = INT_MAX, cur_max = INT_MIN;
        for(int i = 0; i < n; ++i){
            pre_sum_min = min(0, pre_sum_min) + nums[i];
            cur_min = min(cur_min, pre_sum_min);
            left_min[i] = cur_min;
            
            pre_sum_max = max(0, pre_sum_max) + nums[i];
            cur_max = max(cur_max, pre_sum_max);
            left_max[i] = cur_max;
        }
        
        vector<int> right_max(n), right_min(n);
        pre_sum_min = 0, pre_sum_max = 0, cur_min = INT_MAX, cur_max = INT_MIN;
        for(int i = n-1; i >= 0; --i){
            pre_sum_min = min(0, pre_sum_min) + nums[i];
            cur_min = min(cur_min, pre_sum_min);
            right_min[i] = cur_min;
            
            pre_sum_max = max(0, pre_sum_max) + nums[i];
            cur_max = max(cur_max, pre_sum_max);
            right_max[i] = cur_max;
        }
        
        int ans = INT_MIN;
        for(int i = 0; i < n-1; ++i){
            ans = max(ans, abs(right_max[i+1] - left_min[i]));
            ans = max(ans, abs(left_max[i] - right_min[i+1]));
        }
        return ans;
    }
};

// LE 309 Best Time to Buy and Sell Stock with Cooldown

// LE 714 Best Time to Buy and Sell Stock with Transaction Fee
