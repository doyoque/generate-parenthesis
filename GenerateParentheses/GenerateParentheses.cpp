// GenerateParentheses.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        backtrace(res, "", 0, 0, n);
        return res;
    };

private:
    void backtrace(std::vector<std::string>& res, std::string str, int start, int end, int max) {
        if (str.length() == max * 2) {
            res.push_back(str);
            return;
        }

        // open parenthesis num is less than max
        if (start < max) {
            backtrace(res, str + "(", start + 1, end, max);
        }

        // close parenthesis num is less than open num
        if (end < start) {
            backtrace(res, str + ")", start, end + 1, max);
        }
    }
};

int main()
{
    Solution testCase;
    
    testCase.generateParenthesis(3);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
