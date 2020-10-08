#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int max_len1 = 0, mid = 0, max_mid = mid;
        while(mid < s.size()) {
            int len = 0;
            while(s[mid-len] == s[mid+len]) {
                len++;
                if(mid - len < 0 || mid + len >= s.size())
                    break;
            }
            if(len > max_len1) {
                max_len1 = len;
                max_mid = mid;
            }
            mid++;
        }
        string palindrome1(s, max_mid-max_len1+1, max_len1*2-1);
        int max_len2 = 0, left = 0, max_left = left;
        while(left < s.size()-1) {
            int len = 0;
            while(s[left-len] == s[left+1+len]) {
                len++;
                if(left - len < 0 || left + 1 + len >= s.size())
                    break;
            }
            if(len > max_len2) {
                max_len2 = len;
                max_left = left;
            }
            left++;
        }
        string palindrome2(s, max_left-max_len2+1, max_len2*2);
        if(max_len1*2-1 >= max_len2*2)
            return palindrome1;
        else
            return palindrome2;
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

        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
