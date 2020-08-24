#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int flag = 0;
        long long t = x, r = 0;
        if(t < 0) {
            flag = 1;
            t = -t;
        }
        while(t != 0) {
            if((0x7fffffff -  t%10) / 10 < r)
                return 0;
            r = r*10 + t%10;
            t = t/10;
        }
        if(flag == 1)
            r = -r;
        return (int)r;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}