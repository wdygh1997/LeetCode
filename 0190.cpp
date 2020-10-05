#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t r = 0;
        int cnt = 0;
        while(n != 0) {
            r *= 2;
            r += n%2;
            n /= 2;
            cnt++;
        }
        while(cnt < 32) {
            r *= 2;
            cnt++;
        }
        return r;
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

        int ret = Solution().reverseBits(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}