#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> vec;
        vec.push_back(0);
        vec.push_back(1);
        vec.push_back(2);
        for(int i = 3; i <= n; i++) {
            vec.push_back(vec[i-1] + vec[i-2]);
        }
        return vec[n];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}