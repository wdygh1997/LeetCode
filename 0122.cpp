#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p = 0, i = 0, j;
        while(i < prices.size()-1) {
            while(prices[i] >= prices[i+1]) {
                if(i == prices.size()-2) {
                    if(prices[i] < prices[i+1])
                        return p + prices[i+1] - prices[i];
                    else
                        return p;
                }
                i++;
            }
            j = i+1;
            if(j == prices.size()-1) {
                if(prices[j] > prices[i]) {
                    p += prices[j] - prices[i];
                }
                break;
            }
            while(j < prices.size()-1 && prices[j] < prices[j+1]) {
                j++;
            }
            if(prices[j] <= prices[i]) {
                i++;
            }
            else {
                p += prices[j] - prices[i];
                i = j+1;
            }
        }
        return p;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> prices = stringToIntegerVector(line);

        int ret = Solution().maxProfit(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
