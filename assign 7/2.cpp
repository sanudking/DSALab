#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <climits>
using namespace std;

class Solution {
    string clearGroups(string board) {
        while(true) {
            bool removed = false;

            for(int i = 0; i < board.length();) {
                int end = i + 1;

                while(end < board.size() &&
                      board[end] == board[i])
                    end++;

                if(end - i >= 3) {
                    board.erase(i, end - i);
                    removed = true;
                    break;
                }

                i = end;
            }

            if(!removed) return board;
        }
    }

    void appendNumber(string& text, int number) {
        if(number == 0) {
            text += '0';
            return;
        }

        string digits;

        while(number > 0) {
            digits += char('0' + number % 10);
            number /= 10;
        }

        for(int i = digits.length() - 1; i >= 0; i--) {
            text += digits[i];
        }
    }

    string makeKey(const string& board, const vector<int>& hand) {
        string key = board + '#';

        for(int i = 0; i < hand.size(); i++) {
            appendNumber(key, hand[i]);
            key += ',';
        }

        return key;
    }

    int findMinimum(string board, vector<int>& hand,
                    map<string, int>& memo) {
        board = clearGroups(board);

        if(board.empty()) return 0;

        string key = makeKey(board, hand);
        map<string, int>::iterator cached = memo.find(key);

        if(cached != memo.end()) return cached->second;

        int answer = INT_MAX;

        for(int i = 0; i < board.length();) {
            int end = i + 1;

            while(end < board.size() &&
                  board[end] == board[i])
                end++;

            int needed = 3 - (end - i);
            int color = board[i] - 'A';

            if(needed > 0 && hand[color] >= needed) {
                hand[color] -= needed;

                int remaining = findMinimum(
                    board.substr(0, i) + board.substr(end),
                    hand, memo
                );

                if(remaining != -1)
                    answer = min(answer, needed + remaining);

                hand[color] += needed;
            }

            i = end;
        }

        memo[key] = answer == INT_MAX ? -1 : answer;
        return memo[key];
    }

public:
    int boardGame(string board, string hand) {
        vector<int> inHand(26, 0);

        for(int i = 0; i < hand.length(); i++)
            inHand[hand[i] - 'A']++;

        map<string, int> memo;
        return findMinimum(board, inHand, memo);
    }
};

int main() {
    Solution s;
    cout<<" Minimum number of balls to insert for (\"WWRRBBWW\", \"WRBRW\") : ";

    cout << s.boardGame("WWRRBBWW", "WRBRW") << endl;
}