#include <vector>
#include <iostream>


// Given a sorted array of distinct integers and a target value, 
// return the index if the target is found. 
// If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int mid = (nums.size() - 1) / 2;
        int a = 0;
        int b = nums.size()  - 1;

        if (nums[b] < target) {
            return b + 1;
        } else if (nums[a] > target) {
            return a;
        } else if (nums[a] == target) {
            return a; // to catch the 1-length case
        }

        while (a < b - 1) {
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                b = mid;
            } else {
                a = mid;
            }
            mid = (a + b) / 2;
        }

        return a + 1;
    }
};

int main() {
    Solution s;

    std::vector<int> nums1 = {1,3,5,6};
    int res1 = s.searchInsert(nums1, 5);
    std::cout << res1 << "vs" << 2 <<"\n";

    int res2 = s.searchInsert(nums1, 2);
    std::cout << res2 << "vs" << 1 << "\n";

    int res3 = s.searchInsert(nums1, 4);
    std::cout << res3 << "vs" << 2 << "\n";

    std::vector<int> nums2 = {3,4,5,6,7,9,12,14,16,17,18,100,101};
    int res4 = s.searchInsert(nums2, 1);
    std::cout << res4 << "vs" << 0 << "\n";

    int res5 = s.searchInsert(nums2, 20);
    std::cout << res5 << "vs" << 11 << "\n";

    std::vector<int> nums3 = {1};
    int res6 = s.searchInsert(nums3, 1);
    std::cout << res6 << "vs" << 0 << "\n";

}