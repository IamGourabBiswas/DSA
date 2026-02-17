class Solution {
public:
    int findPivot(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            // Check if mid is pivot
            if (mid < e && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            if (mid > s && arr[mid] < arr[mid - 1]) {
                return mid - 1;
            }

            // Decide which side to go
            if (arr[s] >= arr[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return s; // Pivot is s
    }

    int binarySearch(vector<int>& arr, int s, int e, int target) {
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == target) {
                return mid;
            }
            if (arr[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1; // Handle empty array

        int pivotIndex = findPivot(nums);

        // Check which side to search
        if (target >= nums[0] && target <= nums[pivotIndex]) {
            return binarySearch(nums, 0, pivotIndex, target);
        } else {
            return binarySearch(nums, pivotIndex + 1, nums.size() - 1, target);
        }
    }
};