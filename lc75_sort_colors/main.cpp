/* Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]

 

Constraints:

    n == nums.length
    1 <= n <= 300
    nums[i] is either 0, 1, or 2.
 */


// This is just a normal sort then? But only three numbers... /Martin


#include <vector>
#include <iostream>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int zeros = 0;
        int ones = 0;
        int twos = 0;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            switch (num)
            {
            case 0:
                zeros++;
                break;
            case 1:
                ones++;
                break;
            case 2:
                twos++;
            default:
                break;
            }
        }

        int i = 0;
        while (i < zeros) {
            nums[i] = 0;
            i++;
        }
        while (i < zeros + ones) {
            nums[i] = 1;
            i++;
        }
        while (i < zeros + ones + twos) {
            nums[i] = 2;
            i++;
        }
    }
};

void myprint_vec(std::vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i];
    }
}

int main()
{
    Solution s;
    std::vector<int> test0 = {2, 0, 2, 1, 1, 0}; 
    std::vector<int> expect0 = {0, 0, 1, 1, 2, 2};
    s.sortColors(test0);
    // assert(test0 == expect0);

    myprint_vec(test0);

    return 0;
}
