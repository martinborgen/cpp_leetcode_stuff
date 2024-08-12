#include <vector>
#include <iostream>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }
        int cnt = 1;
        int left = 0;
        int right = cnt;
        while (left < nums.size() && right < nums.size() && cnt <= nums.size()) {
            while (right < nums.size() - 1 && nums[left] == nums[right]) {
                right++;
            }
            
            if (nums[left] != nums[right]) {
                nums[cnt] = nums[right];
                left = cnt;
                cnt++;
            } else {
                break;
            }
        }
        return cnt;
    }
};

int main() {
    Solution s;
    std::vector<int> vec1 = {1,1,2};

    int res1 = s.removeDuplicates(vec1);
    printf("%d\n", res1);

    std::vector<int> vec2 = {0,0,1,1,1,2,2,3,3,4};
    int res2 = s.removeDuplicates(vec2);
    printf("%d\n", res2);

    std::vector<int> vec3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int res3 = s.removeDuplicates(vec3);
    printf("%d\n", res3);

    std::vector<int> vec4 = {0, 0, 0, 0, 0, 0, 0};
    int res4 = s.removeDuplicates(vec4);
    printf("%d\n", res4);

    std::cout << "\n";
    return 0;
}