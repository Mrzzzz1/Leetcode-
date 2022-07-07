#include<iostream>
#include<vector>
using namespace std;
class Solution {
    //22. 括号生成
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        getAns(ans, n, n, s);
        return ans;
    }

    void getAns(vector<string> &ans, int left, int right, string &s){
        if (right == 0){
            ans.push_back(s);
            return;
        }
        if (left>0){
            s.push_back('(');
            getAns(ans, left - 1, right, s);
            s.pop_back();
        }
        if (right>left){
            s.push_back(')');
            getAns(ans, left, right - 1, s);
            s.pop_back();
        }
    }
    //23.合并k个升序链表
     struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if (l1 == NULL || l2 == NULL)return l1 ? l1 : l2;
        ListNode head;
        ListNode* tail = &head;
        while (l1&&l2){
            if (l1->val<l2->val){
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;
            }
        }
        tail->next = l1 ? l1 : l2;
        return head.next;

    }
    ListNode* merge(vector<ListNode*>& lists, int left, int right){
        if (left == right)return lists[left];
        if (left>right)return NULL;
        int mid = (left + right) / 2;
        return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);

    }
    //24.两两交换链表中的结点
    ListNode* swapPairs(ListNode* head) {
        ListNode newh;
        newh.next = head;
        ListNode* newHead = &newh;
        while (newHead->next&&newHead->next->next){
            swap(newHead);
            newHead = newHead->next->next;
        }
        return newh.next;
    }
    void swap(ListNode* head){
        ListNode* p = head->next;
        head->next = p->next;
        p->next = head->next->next;
        head->next->next = p;
        return;
    }

};
int main(){
    Solution s;
    
}