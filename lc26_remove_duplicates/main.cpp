#include <vector>
#include <iostream>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int len = nums.size();
        std::cout << len;
        return len;
    }
};

int main() {
    Solution s;
    std::vector<int> vec = {1,1,2};

    int res = s.removeDuplicates(vec);
    return 0;
}