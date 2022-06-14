#include <iostream>
#include<map>
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
// 1.两数之和
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int a = target - nums[i];
            if (mp.count(a) > 0)return {mp[a], i};
            else mp[nums[i]] = i;
        }
        return {0, 0};
    }
// 2.两数相加
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int up=0,add1=0,add2=0;
        ListNode* ans=new ListNode(0);
        ListNode* p=ans;
        while(l1||l2||up){
            if(l1!=NULL){
                add1=l1->val;
                l1=l1->next;
            }
            else add1=0;
            if(l2!=NULL){
                add2=l2->val;
                l2=l2->next;
            }
            else add2=0;
            p->next=new ListNode((add1+add2+up)%10);
            p=p->next;
            up=(add1+add2+up)/10;
        }
        return ans->next;
    }
// 3.无重复字符的最长子串
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int start=0,end=0,ans=0;
        for(int i=0;i<s.size();i++){
            end++;
            map<char,int>::iterator now=mp.find(s[i]);
            if (now!=mp.end()&&now->second>=start){
                start=now->second+1;
                mp.erase(now);
            }
            mp[s[i]]=i;
            int ansnow=end-start;
            ans=ans>ansnow?ans:ansnow;
        }
        return ans;

    }
//4.寻找两个正序数组的中位数
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if (m>n) return findMedianSortedArrays(nums2,nums1);
        int allLeft=(m+n+1)/2;
        int left=0,right=m;
        while(left<right){
            int i=(left+right+1)/2;
            int j=allLeft-i;
            if(nums1[i-1]>nums2[j])right=i-1;
            else left=i;
        }
        int i=left,j=allLeft-i;
        int min1=i==0?-1000000:nums1[i-1];
        int min2=j==0?-1000000:nums2[j-1];
        int max1=i==m?1000000:nums1[i];
        int max2=j==n?1000000:nums2[j];
        if ((m+n)%2)return max(min1,min2);
        else return (max(min1,min2)+min(max1,max2))/2.0;

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution s;
    cout<<s.lengthOfLongestSubstring("aab");
    return 0;
}
