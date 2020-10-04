#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int t = 0;
        while(n != 0) {
            if(n%2 == 1)
                t++;
            n /= 2;
        }
        return t;
    }
};

int stringToInteger(string input) {
    uint32_t n = 0;
    for(int i = 0; i < input.size(); i++) {
        n *= 2;
        n += (input[i] - '0');
    }
    return n;
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().hammingWeight(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}