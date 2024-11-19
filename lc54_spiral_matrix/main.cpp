/* 
return a spiral path through a matrix such as:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */

#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        std::vector<int> output;
        output.reserve(m * n);

        int imax = m - 1;
        int jmax = n - 1;
        int imin = 0;
        int jmin = 0;
        int i = imin;
        int j = jmin;
        
        int right[] = {0, 1};
        int down[] = {1, 0};
        int left[] = {0, -1};
        int up[] = {-1, 0};

        int* dir = right;

        while (output.size() < m * n) {
            while (i <= imax && 
                   i >= imin && 
                   j <= jmax && 
                   j >= jmin) {
                output.push_back(matrix[i][j]);
                i += dir[0];
                j += dir[1];
            }
            i -= dir[0];
            j -= dir[1];

    
            if (dir == right) {
                dir = down;
                imin++;
            } else if (dir == down) {
                dir = left;
                jmax--;
            } else if (dir == left) {
                dir = up;
                imax--;
            } else if (dir == up) {
                dir = right;
                jmin++;
            }

            i += dir[0];
            j += dir[1];
        }

        return output;
    }
};

void print_vect(std::vector<int>& vect) {
    for (int i = 0; i < vect.size(); i++) {
        std::cout << vect[i];
    }
    std::cout << "\n";
}

int main() {
    Solution s;
    
    std::vector<std::vector<int>> test0 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<int> res0 = s.spiralOrder(test0);
    print_vect(res0);

    std::vector<std::vector<int>> test1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {8, 9, 11, 12}};
    std::vector<int> res1 = s.spiralOrder(test1);
    print_vect(res1);
}