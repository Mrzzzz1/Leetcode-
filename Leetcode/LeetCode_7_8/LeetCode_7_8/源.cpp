#include<iostream>
#include<tuple>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    //25. K 个一组翻转链表
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return{ tail, head };
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            tie(head, tail) = myReverse(head, tail);
            pre->next = head;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
public:
    //26. 删除有序数组中的重复项
    int removeDuplicates(vector<int>& nums) {
        for (vector<int>::iterator i = nums.begin(); i<nums.end(); i++){
            for (vector<int>::iterator j = i + 1; j < nums.end();){
                if (*i == *j){
                    nums.erase(j);
                }
                else break;
            }

        }
        return nums.size();
    }
public:
    //27. 移除元素
    int removeElement(vector<int>& nums, int val) {
        for (vector<int>::iterator iter = nums.begin(); iter<nums.end();){
            if (*iter == val)nums.erase(iter);
            else iter++;
        }
        return nums.size();

    }

    //28.
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        vector<int>next(m + 1);
        next[0] = -1;
        int i = 0, j = -1;
        while (i<m - 1){
            if (j == -1 || needle[i] == needle[j ]){
                next[++i] = ++j;
            }
            else{
                j = next[j];
            }
        }
        i = 0, j = 0;
        while (i<n){
            if (j == -1 || haystack[i] == needle[j]){
                i++;
                j++;
            }
            else j = next[j];
            if (j == m)return i - m;

        }
        return -1;

    }


};
int main(){
    Solution s;
    vector<int> v = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
  //  s.removeDuplicates(v);
    string a = "mississippi";
    string b = "issipi";
    s.strStr(a, b);
}