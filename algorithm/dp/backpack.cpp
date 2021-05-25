// https://blog.csdn.net/wzy_1988/article/details/12260343
// backpack:
// 1. 0/1(select or not select), 92 I, 125 II, 563 V,
// 2. complete(unbounded amount), 440 III, 562 IV
// 3. multiple(limited amount by K), 798 VII, 799 VIII.



// LT 92 Backpack I
// Given n items with size n integer m denotes the size of a backpack. each item can pick once. How full you can fill this backpack?
// example: array = [3,4,8,5] backpack size = 10  
// output 9
// dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i]]

int backPack(int m, vector<int> &A) {
    // write your code here
    int n = A.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    for(int i = 0; i <= n; ++i){
        dp[i][0] = true;
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            dp[i][j] = dp[i-1][j] || (j >= A[i-1] ? dp[i-1][j-A[i-1]] : false);
            if(dp[i][j]){ ans = max(ans, j); }
        }
    }
    return ans;
}

int backPack(int m, vector<int> &A) {
  int n = A.size();
  bool dp[m+1] ={false};
  dp[0] = true;
  int ans = 0;
  for(int i = 1; i <= n; ++i){
      for(int j = m; j >= 1; --j){
          dp[j] = dp[j] || (j >= A[i-1] ? dp[j-A[i-1]] : false);
          if(dp[j]){ ans = max(ans, j); }
      }
  }
  return ans;
}

// LT 125 Backpack II
// There are n items and a backpack with size m. Given array A representing the size of each item and array V representing the value of each item.
// What's the maximum value can you put into the backpack?
// Eg: m = 10, A = [2, 3, 5, 7], V = [1, 5, 2, 4]
// output: 9
// dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i]]+V[i])

int backPackII(int m, vector<int> &A, vector<int> &V) {
    int n = A.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(j - A[i-1] >= 0){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i-1]] + V[i-1]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}

int backPackII(int m, vector<int> &A, vector<int> &V) {
    int n = A.size();
    vector<int> dp(m+1, 0);
    for(int i = 1; i <= n; ++i){
        for(int j = m; j >= 1; --j){
            if(j - A[i-1] >= 0){
                dp[j] = max(dp[j], dp[j-A[i-1]] + V[i-1]);
            }
        }
    }
    return dp[m];
}

// LT 440 Backpack III, complete 
// Given n kinds of items, and each kind of item has an infinite number available. The i-th item has size A[i] and value V[i].
// Also given a backpack with size m. What is the maximum value you can put into the backpack?
// Input: A = [2, 3, 5, 7], V = [1, 5, 2, 4], m = 10, Output: 15
// Explanation: Put three item 1 (A[1] = 3, V[1] = 5) into backpack.
// Input: A = [1, 2, 3], V = [1, 2, 3], m = 5, Output: 5
// Explanation: Strategy is not unique. For example, put five item 0 (A[0] = 1, V[0] = 1) into backpack.

// dp[i][j] = max(dp[i-1][j], dp[i-1][j-kA[i]]+kV[i]) where j-kA[i] >= 0 
// dp[i][j] = max(dp[i-1][j], dp[i][j-A[i]]+V[i])
// i index of A, j size, dp[i][j] denotes the max value by using 0 .. i item in A, and size is lte j
// dp[i][j]: either not use last one dp[i-1][j], 
// or use the last one dp[i][j-A[i]]+V[i], but i is the same, because, we may use i again,
// i.e. dp[i][j-2*A[i]]+2*V[i], ... dp[i][j-k*A[i]]+k*V[i]
// dp[i][j-A[i]]+V[i] will cover the above cases.


int backPackIII(vector<int> &A, vector<int> &V, int m) {
    int n = A.size();
    vector<int> dp(m+1, 0);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(j-A[i-1] >= 0){
                dp[j] = max(dp[j], dp[j-A[i-1]] + V[i-1]);
            }
        }
    }
    return dp[m];
}

int backPackIII(vector<int> &A, vector<int> &V, int m) {
    int n = A.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            dp[i][j] = dp[i-1][j];
            if(j-A[i-1] >= 0){
                dp[i][j] = max(dp[i][j], dp[i][j-A[i-1]] + V[i-1]);
            }
        }
    }
    return dp[n][m];
}

int backPackIII(vector<int> &A, vector<int> &V, int m) {
    int n = A.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            dp[i][j] = dp[i-1][j];
            for(int k = 1; j - k * A[i-1] >= 0; ++k){
                dp[i][j] = max(dp[i][j], dp[i-1][j-k*A[i-1]] + k*V[i-1]);
            }
        }
    }
    return dp[n][m];
}

// LT 562 Backpack IV, Complete
// Give n items and an array, num[i] indicate the size of ith item. An integer target denotes the size of backpack. Find the number of ways to fill the backpack.
// Each item may be chosen unlimited number of times
// Input: nums = [2,3,4,5] and target = 7, Output: 3
// Explanation: Solution sets are: [2, 5], [3, 4], [2, 2, 3]

// dp[i][j] = dp[i-1][j] + dp[i][j-nums[i]]
// i index of A, j size, dp[i][j] denotes the max value by using 0 .. i items in nums, and size is lte j
/* nums = [2,3,4,5] and target = 7
  0 1 2 3 4 5 6 7
0 1 0 0 0 0 0 0 0
1 1 0 1 0 1 0 1 0
2 1 0 1 1 1 1 2 1
3 1 0 1 1 2 1 3 2
4 1 0 1 1 2 2 3 3
*/

int backPackIV(vector<int> &nums, int target) {
    // write your code here
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(target+1));
    for(int i = 1; i <= n; ++i){
        dp[i][0] = 1;
        for(int j = 1; j <= target; ++j){
            dp[i][j] = dp[i-1][j];
            if(j >= nums[i-1]){ 
                dp[i][j] += dp[i][j-nums[i-1]];
            }
        }
    }
    return dp[n][target]
}

int backPackIV(vector<int> &nums, int target) {
    int n = nums.size();
    vector<int> dp(target+1);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= target; ++j){
            if(j >= nums[i-1]){ 
                dp[j] += dp[j-nums[i-1]];
            }
        }
    }
    return dp[target];
}


// LT 563 Backpack V, 0/1, count
// Given n items with size nums[i] which an integer array and all positive numbers. An integer target denotes the size of a backpack. 
// Find the number of possible fill the backpack.
// Each item may only be used once
/* Example
Given candidate items [1,2,3,3,7] and target 7,
A solution set is: [7], [1, 3, 3]
*/

int backPackV(vector<int> &nums, int target) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= target; ++j){
            dp[i][j] = dp[i-1][j] + (j-nums[i-1] >= 0 ? dp[i-1][j-nums[i-1]] : 0);
        }
    }
    return dp[n][target];
}
int backPackV(vector<int> &nums, int target) {
    int n = nums.size();
    vector<int> dp(target+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){    
        for(int j = target; j >= 1 ; --j){
            dp[j] = dp[j] + (j-nums[i-1] >= 0 ? dp[j-nums[i-1]] : 0);
        }
    }
    return dp[target];
}

/*
LT 564 Backpack VI, Combination Sum IV, duplicate solution
Given an integer array nums with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
Input: nums = [1, 2], and target = 4
Output: 5
Explanation:
The possible combination ways are:
[1, 1, 1, 1]
[1, 1, 2]
[1, 2, 1]
[2, 1, 1]
[2, 2]
*/


int backPackVI(vector<int> &nums, int target) {
    int n = nums.size();
    vector<int> dp(target+1);
    dp[0] = 1;
    for(int i = 1; i <= target; ++i){
        for(int j = 1; j <= n; ++j){
            if(i >= nums[j-1]){
                dp[i] += dp[i-nums[j-1]];
            }
        }
    }
    return dp[target];
}

/*
LT 798 Backpack VII, multiple, 
假设你身上有 n 元，超市里有多种大米可以选择，每种大米都是袋装的，必须整袋购买，给出每种大米的重量，价格以及数量，求最多能买多少公斤的大米
输入:  n = 8, prices = [3,2], weights = [300,160], amounts = [1,6] 输出:  640	 解释:  全买价格为2的米。
*/
int backPackVII(int n, vector<int> prices, vector<int> weight, vector<int> amounts) {
	int m = prices.size();
	vector<vector<int>> dp(m+1, vector<int>(n+1));
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 0; k <= amounts[i - 1]; ++k) {
				if (j >= k*prices[i-1]) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - k*prices[i-1]] + k*weight[i-1]);
				}
			}
		}
	}
	return dp[m][n];
}

int backPackVII(int n, vector<int> prices, vector<int> weight, vector<int> amounts) {
	int m = prices.size();
	vector<int> dp(n+1);
	for (int i = 1; i <= m; ++i) {
		for (int j = n; j >= 1; --j) {
			for (int k = 0; k <= amounts[i - 1]; ++k) {
				if (j >= k*prices[i-1]) {
					dp[j] = max(dp[j], dp[j - k*prices[i-1]] + k*weight[i-1]);
				}
			}
		}
	}
	return dp[n];
}


/* 
LT 799 Backpack VIII
给一些不同价值和数量的硬币。找出[1，n]范围内的总值有多少种形成方式？
输入: n = 5, value = [1,4], amount = [2,1], 输出:  4
解释: 可以组合出1，2，4，5
输入: n = 10, value = [1,2,4], amount = [2,1,1], 输出:  8
解释: 可以组合出1-8所有数字。
https://www.jiuzhang.com/problem/backpack-viii/
*/


/* 
LT 800 Backpack IX
You have a total of n thousand yuan, hoping to apply for a university abroad. The application is required to pay a certain fee. 
Give the cost of each university application and the probability of getting the University's offer, and the number of university is m. 
If the economy allows, you can apply for multiple universities. Find the highest probability of receiving at least one offer.
example: n = 10 prices = [4,5,6] probability = [0.1,0.2,0.3] Output:  0.370
Explanation: select the first and the third school.
*/

double backpackIX(int n, vector<int> &prices, vector<double> &probability) {
    int sz = probability.size();
    for(int i = 0; i < sz; ++i){
        probability[i] = 1 - probability[i];
    }

    vector<vector<double>> dp(sz+1, vector<double>(n+1,1));
    for(int i = 1; i <= sz; ++i){
        for(int j = 1; j <= n; ++j){
            dp[i][j] = min(dp[i][j], j>=prices[i-1] ? dp[i-1][j-prices[i-1]] * probability[i-1] : 1);
        }
    }
    return 1 - dp[sz][n];
}
double backpackIX(int n, vector<int> &prices, vector<double> &probability) {
    // write your code here
    int sz = probability.size();
    for(int i = 0; i < sz; ++i){
        probability[i] = 1 - probability[i];
    }

    vector<double> dp(n+1,1);
    for(int i = 1; i <= sz; ++i){
        for(int j = n; j >= 1; --j){
            dp[j] = min(dp[j], j>=prices[i-1] ? dp[j-prices[i-1]] * probability[i-1] : 1);
        }
    }
    return 1 - dp[n];
}


/*
LT 801 Backpack X
你总共有n元，商人总共有三种商品，它们的价格分别是150元,250元,350元，三种商品的数量可以认为是无限多的，购买完商品以后需要将剩下的钱给商人作为小费，求最少需要给商人多少小费
https://www.jiuzhang.com/problem/backpack-x/
*/
