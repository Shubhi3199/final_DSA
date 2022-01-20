// https://www.programiz.com/dsa/quick-sort
#include<bits/stdc++.h>
using namespace std;

int get_partition(vector<int> &nums, int start, int end) {
	int pivot_ele = nums[end];
	int max_ele_idx = start; // we are trying to swap ele grater than pivot ele to the right and eles smaller than picot to the left of it
	for (int min_ele_idx = start; min_ele_idx <= end - 1; min_ele_idx++) { // for loop only till end-1 as nums[end] is pivot ele
		if (nums[min_ele_idx] <= pivot_ele) {
			// swap the min_ele_idx and max_ele_idx
			swap(nums[min_ele_idx], nums[max_ele_idx]);
			max_ele_idx++;
		}
	}
	// now the last step is to get the pivot ele at its coorect sorted position
	swap(nums[end], nums[max_ele_idx]);
	return max_ele_idx;
}

void quick_sort(vector<int> &nums, int start, int end) {
	if (start >= end) return;
	int partition_idx = get_partition(nums, start, end);
	// applying divide and conquer on the left and right subarrays created
	quick_sort(nums, start, partition_idx - 1);
	quick_sort(nums, partition_idx + 1, end);
}

int main() {
	int size;
	cin >> size;
	vector<int> nums(size);
	for (int i = 0; i < size; i++) {
		cin >> nums[i];
	}
	quick_sort(nums, 0, nums.size() - 1);
	for (int ele : nums) cout << ele << " ";
	return 0;
}
