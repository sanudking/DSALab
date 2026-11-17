#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int parenthesesCount(string s) {
        int n = s.size();
        int cnt = 0;
        int len = 0;
        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                cnt++;
            } else {
                cnt--;
            }

            len++;

            if(cnt < 0) {
                cnt = 0;
                len = 0;
            }

            if(cnt == 0) {
                maxLen = max(len, maxLen);
            }
        }

        cnt = 0;
        len = 0;

        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == ')') {
                cnt++;
            } else {
                cnt--;
            }

            len++;

            if(cnt < 0) {
                cnt = 0;
                len = 0;
            }

            if(cnt == 0) {
                maxLen = max(len, maxLen);
            }
        }

        return maxLen;
    }
};

int main() {
    Solution s;
    string input;

    cout << "Enter a string containing '(' and ')': ";
    cin >> input;

    int result = s.parenthesesCount(input);

    cout << "Input string: " << input << endl;
    cout << "Longest valid parentheses substring length: "
         << result << endl;

    return 0;
}