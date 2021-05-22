// LT 92 Backpack
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

// LT 440 Backpack III, unbounded 
// Given n kinds of items, and each kind of item has an infinite number available. The i-th item has size A[i] and value V[i].
// Also given a backpack with size m. What is the maximum value you can put into the backpack?
// Input: A = [2, 3, 5, 7], V = [1, 5, 2, 4], m = 10, Output: 15
// Explanation: Put three item 1 (A[1] = 3, V[1] = 5) into backpack.
// Input: A = [1, 2, 3], V = [1, 2, 3], m = 5, Output: 5
// Explanation: Strategy is not unique. For example, put five item 0 (A[0] = 1, V[0] = 1) into backpack.

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

// LT 562 Backpack IV 
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
