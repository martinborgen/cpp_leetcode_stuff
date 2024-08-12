#include <vector>
#include <string>
#include <iostream>


class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> output;
        for (int i = 0; i < digits.length(); i++) {
            int d = digits[i] - '0';
            std::string current = this->letters_from_digit(d);
            output = this->perm(output, current);
        }
        return output;
    }

private:
    std::vector<std::string> perm(std::vector<std::string> avec, std::string b) {
        std::vector<std::string> output;
        if (avec.size() == 0) {
            for (int i = 0; i < b.size(); i++) {
                char c = b[i];
                std::string str;
                str.push_back(c);
                output.push_back(str);
            }
            return output;
        }

        for (int i = 0; i < avec.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                std::string tmp;
                tmp.append(avec[i]);
                tmp.push_back(b[j]);
                output.push_back(tmp);
            }
        }
        return output;
    }

    std::string letters_from_digit(int digit) {
        switch (digit)
        {
        case 2:
            return std::string("abc");
            break;

        case 3:
            return std::string("def");
            break;

        case 4:
            return std::string("ghi");
            break;

        case 5:
            return std::string("jkl");
            break;

        case 6:
            return std::string("mno");
            break;

        case 7:
            return std::string("pqrs");
            break;

        case 8:
            return std::string("tuv");
            break;

        case 9:
            return std::string("wxyz");
            break;
        
        default:
            return std::string("");
            break;
        }
    }
};

int main() {
    Solution s;
    std::vector<std::string> res = s.letterCombinations(std::string("2345"));
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << "\n";
    }
}