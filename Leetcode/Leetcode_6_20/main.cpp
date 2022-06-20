#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
//16.最近的三数之和
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=0xefffffff;
        sort(nums.begin(),nums.end());
        auto updateAns=[&](int now){
            if(abs(now-target)<abs(ans-target))ans=now;
        };
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int now=nums[i]+nums[j]+nums[k];
                if(now==target)return target;
                updateAns(now);
                if (now>target)--k;
                else ++j;
            }

        }
        return ans;
    }
//17.电话号码里的字母组合
    int dfs(int now,int n,string& str,vector<string>& ans,string digits){
        string s[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        if (now==n){
            ans.push_back(str);
            return 0;
        }
        int num=s[digits[now]-'0'].size();
        for(int i=0;i<num;i++){
            str.push_back(s[digits[now]-'0'][i]);
            dfs(now+1,n,str,ans,digits);
            str.erase(str.end() - 1);
        }
        return 0;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n=digits.size();
        if(n==0)return ans;
        string s[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        string str="";
        dfs(0,n,str,ans,digits);
        return ans;
    }
//18.四数之和
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            while(i!=0&&nums[i]==nums[i-1]&&i<n)i++;
            if(i>=n-3)break;
            if((long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target)break;
            while((long)nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target&&i<n-4)i++;
            for(int j=i+1;j<n-2;j++){
                while(j!=i+1&&nums[j]==nums[j-1]&&j<n)j++;
                if(j>=n-2)break;
                if((long)nums[i]+nums[j+1]+nums[j+2]+nums[j]>target)break;
                while((long)nums[i]+nums[j]+nums[n-2]+nums[n-1]<target&&j<n-3)j++;
                int ij=nums[i]+nums[j];
                int k=j+1,l=n-1;
                while(k<l){
                    long now=(long)ij+nums[k]+nums[l];
                    if (now==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        while(k<l&&nums[k]==nums[k-1])k++;
                    }
                    else if (now<target){
                        k++;
                        while(k<l&&nums[k]==nums[k-1])k++;
                    } else {
                        l--;
                        while(l>k&&nums[l]==nums[l+1])l--;
                    }
                }
            }
        }
        return ans;
    }
//删除链表倒数第N个结点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p=head;
        int num=0;
        while(p!=NULL){
            ++num;
            p=p->next;
        }
        p=head;
        int m=num-n-1;
        if(m==-1){
            head=head->next;
            return head;
        }
        for(int i=0;i<m;i++) {
            p=p->next;
        }
        ListNode* q=p->next;
        p->next=q->next;
        return head;

    }
};

int main() {
    Solution s;
    vector<int>a={0,1,2};
    cout << s.threeSumClosest(a,0);
    s.letterCombinations("23");
    vector<int> b={0,0,0,0};
    vector<vector<int>> foursum=s.fourSum(b,1);
    ;
    return 0;
}
