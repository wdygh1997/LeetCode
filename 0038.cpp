#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string str1 = "11", str2 = "";
        for(int i = 2; i < n; i++) {
            int j = 0, k;
            while(j < str1.size()) {
                k = j+1;
                while(str1[k] == str1[j]) {
                    if(k == str1.size())
                        break;
                    k++;
                }
                int t = k - j;
                string str;
                stringstream ss;
                ss << t;
                ss >> str;
                str2 += str;
                str2 += str1[j];
                j = k;
            }
            str1 = str2;
            str2 = "";
        }
        if(n == 1)
            return "1";
        else
            return str1;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}