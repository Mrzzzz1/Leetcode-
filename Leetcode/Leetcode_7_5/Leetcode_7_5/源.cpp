#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    //20. 有效的括号
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for (int i = 0; i<n; i++){
            if (st.empty()){
                st.push(s[i]);
                continue;
            }
            if (s[i] == ')'&&st.top() == '(')st.pop();
            else if (s[i] == ']'&&st.top() == '[')st.pop();
            else if (s[i] == '}'&&st.top() == '{')st.pop();
            else st.push(s[i]);
        }
        return st.empty();
    }
    //21. 合并两个有序链表
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(-1);
        ListNode* p = ans;
        while (list1 != NULL&&list2 != NULL){
            if (list1->val<list2->val){
                p->next = list1;
                list1 = list1->next;
            }
            else {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        if (list1 == NULL)p->next = list2;
        else p->next = list1;
        return ans->next;
    }
};
int main(){
    Solution s;
    s.isValid("()[]{}");
}