// 610 two sum - difference equals to target
// 给定一个排序后的整数数组，找到两个数的 差 等于目标值
// input: nums = [2, 7, 15, 24], target = 5, output: [2, 7], (7 - 2 = 5)
vector<int> twoSumDiffEqualToTarget(vector<int> nums, int target) {
	int n = nums.size();
	for (int st = 0, ed = 0; st < n && ed < n; ) {
		if (st == ed) {
			++ed;
		}
		int cur_diff = nums[ed] - nums[st];
		if (cur_diff == target) {
			return {nums[st], nums[ed]};
		}
		else if (cur_diff > target) {
			++st;
		}
		else {
			++ed;
		}
	}
	return { -1, -1 };
}

// 609 two sum - less than or equal to target
// input: nums = [2, 7, 11, 15], target = 24. output: 5. 2 + 7 < 24, 2 + 11 < 24, 2 + 15 < 24, 7 + 11 < 24, 7 + 15 < 24
int twoSumLessThanOrEqualToTarget(vector<int> nums, int target) {
	int n = nums.size();
	int st = 0, ed = n - 1;
	int cnt = 0;
	while (st < ed) {
		int sum = nums[st] + nums[ed];
		if (sum <= target) {
			cnt += ed - st;
			++st;
		}
		else {
			--ed;
		}
	}
	return cnt;
}

// 587 two sum - unique pairs
// nums = [1,1,2,45,46,46], target = 47, output: 2, 1 + 46 = 47, 2 + 45 = 47
// 给一整数数组, 找到数组中有多少组 不同的元素对 有相同的和, 且和为给出的 target 值, 返回对数.
int twoSumUniquePair(vector<int> nums, int target) {
	sort(begin(nums), end(nums));
	int n = nums.size();
	int st = 0, ed = n - 1;
	int cnt = 0;
	while (st < ed) {
		int cur_sum = nums[st] + nums[ed];
		if (cur_sum == target) {
			++cnt; ++st; --ed;
			while (st < ed && nums[st] == nums[st - 1]) {
				++st;
			}
			while (st < ed && nums[ed] == nums[ed + 1]) {
				--ed;
			}
		}
		else if (cur_sum > target) {
			--ed;
		}
		else {
			++st;
		}
	}
	return cnt;
}

// 533 two sum - closest to target
// 给定整数数组num，从中找到两个数字使得他们和最接近target，返回两数和与 target 的差的 绝对值
// input: nums = [-1, 2, 1, -4], target = 4, output: 1, (4 - (2 + 1) = 1).
// input: nums = [-1, -1, -1, -4], target = 4, output: 6, (4 - (- 1 - 1) = 6).
int twoSumMinDiff(vector<int> nums, int target) {
	sort(begin(nums), end(nums));
	int n = nums.size();
	int st = 0, ed = n - 1;
	int diff = INT_MAX;
	while (st < ed) {
		int cur_sum = nums[st] + nums[ed];
		int cur_diff = abs(cur_sum - target);
		if (cur_diff == 0) {
			return 0;
		}
		else if (cur_sum > target) {
			--ed;
		}
		else {
			++st;
		}
		diff = min(diff, cur_diff);
	}
	return diff;
}

// 443 two sum - greater than target
// input: nums = [2, 7, 11, 15], target = 24, output: 1, 11 + 15
// input: nums = [1, 1, 1, 1], target = 1, output: 6
int twoSumGreaterThanTarget(vector<int> nums, int target) {
	sort(begin(nums), end(nums));
	int n = nums.size(), cnt = 0
	int st = 0, ed = n - 1;
	while (st < ed) {
		int cur_sum = nums[st] + nums[ed];
		if (cur_sum > target) {
			cnt += ed - st;
			--ed;
		}
		else {
			++st;
		}
	}
	return cnt;
}
