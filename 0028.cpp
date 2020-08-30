#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if(n == 0)
            return 0;
        vector<int> next(n);
        next[0] = -1;
        int j = -1;
        for(int i = 1; i < n; i++) {
            while(j != -1 && needle[i-1] != needle[j])
                j = next[j];
            j++;
            next[i] = j;
        }
        j = 0;
        for(int i = 0; i < m; i++)
        {
            while(j != -1 && haystack[i] != needle[j])
                j = next[j];
            j++;
            if(j == n)
                return i-n+1;
        }
        return -1;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string haystack = stringToString(line);
        getline(cin, line);
        string needle = stringToString(line);

        int ret = Solution().strStr(haystack, needle);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}