#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> st;
        while(headA != nullptr) {
            st.insert(headA);
            headA = headA->next;
        }
        while(st.find(headB) == st.end() && headB != nullptr) {
            headB = headB->next;
        }
        return headB;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int intersectVal = stringToInteger(line);
        getline(cin, line);
        ListNode* listA = stringToListNode(line);
        getline(cin, line);
        ListNode* listB = stringToListNode(line);
        getline(cin, line);
        int skipA = stringToInteger(line);
        getline(cin, line);
        int skipB = stringToInteger(line);

        if(intersectVal != 0) {
            ListNode *t1 = listA, *t2 = listB;
            for(int i = 0; i < skipA; i++)
                t1 = t1->next;
            for(int i = 1; i < skipB; i++)
                t2 = t2->next;
            t2->next = t1;
        }

        ListNode* ret = Solution().getIntersectionNode(listA, listB);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}