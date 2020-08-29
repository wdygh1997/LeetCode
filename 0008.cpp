#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int num = 0, k = 0, t = 0;
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == ' ') {
                if(t == 1)
                    break;
                continue;
            }
            if(str[i] == '-') {
                if(t == 1)
                    break;
                k = 1;
                t = 1;
                continue;
            }
            if(str[i] == '+') {
                if(t == 1)
                    break;
                t = 1;
                continue;
            }
            if(str[i] != ' ' && str[i] != '+' && str[i] != '-' && !(str[i] >= '0' && str[i] <= '9')) {
                break;
            }
            if(str[i] >= '0' && str[i] <= '9') {
                t = 1;
                if(num > 0 && k == 1)
                    num = -num;
                if(num > 0 && (INT_MAX-(str[i]-'0'))/10 < num)
                    return INT_MAX;
                else if (num < 0 && (INT_MIN+(str[i]-'0'))/10 > num)
                    return INT_MIN;
                else if(num >= 0)
                    num = num*10 + (str[i]-'0');
                else
                    num = num*10 - (str[i]-'0');
            }
        }
        if(num > 0 && k == 1)
            num = -num;
        return num;
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
        string str = stringToString(line);

        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}