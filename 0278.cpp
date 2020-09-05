#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int bad_version;

bool isBadVersion(int version) {
    if(version < bad_version)
        return false;
    else
        return true;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left < right-1) {
            int mid = left + (right - left) / 2;
            if(isBadVersion(mid))
                right = mid;
            else
                left = mid;
        }
        if(isBadVersion(left))
            return left;
        else
            return right;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int bad = stringToInteger(line);

        bad_version = bad;

        int ret = Solution().firstBadVersion(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}