#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'I') {
                if (s[i+1] != 'V' && s[i+1] != 'X') {
                    num += 1;
                } else if (s[i+1] == 'V') {
                    num += 4;
                    i++;
                } else if (s[i+1] == 'X') {
                    num += 9;
                    i++;
                }
            } else if(s[i] == 'V') {
                num += 5;
            } else if(s[i] == 'X') {
                if (s[i+1] != 'L' && s[i+1] != 'C') {
                    num += 10;
                } else if (s[i+1] == 'L') {
                    num += 40;
                    i++;
                } else if (s[i+1] == 'C') {
                    num += 90;
                    i++;
                }
            } else if(s[i] == 'L') {
                num += 50;
            } else if(s[i] == 'C') {
                if (s[i+1] != 'D' && s[i+1] != 'M') {
                    num += 100;
                } else if (s[i+1] == 'D') {
                    num += 400;
                    i++;
                } else if (s[i+1] == 'M') {
                    num += 900;
                    i++;
                }
            } else if(s[i] == 'D') {
                num += 500;
            } else if(s[i] == 'M') {
                num += 1000;
            }
        }
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
        string s = stringToString(line);

        int ret = Solution().romanToInt(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}

