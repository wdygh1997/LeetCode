#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int i;
        for(i = 0; i < s.size(); i++) {
            int j;
            for(j = 0; j < s.size(); j++) {
                if(j == i)
                    continue;
                if(s[i] == s[j])
                    break;
            }
            if(j == s.size())
                break;
        }
        if(i == s.size())
            return -1;
        else
            return i;
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
        string s = stringToString(line);

        int ret = Solution().firstUniqChar(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}