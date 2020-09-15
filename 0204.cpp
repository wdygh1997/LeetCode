#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> isPrime(n, true);
        for(int i = 2; i < n; i++) {
            if(isPrime[i]) {
                cnt++;
                for(int j = 2*i; j < n; j+=i) {
                    isPrime[j] = false;
                }
            }
        }
        return cnt;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().countPrimes(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}