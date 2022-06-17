#include <iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
//10.正则表达式匹配
    bool isMatch(string s, string p) {
        auto match = [&](int i,int j){
            if(i==0)return false;
            if (p[j-1]=='.')return true;
            if (s[i-1]==p[j-1])return true;
            return false;
        };
        int m = s.size();
        int n = p.size();
        bool dp[m+1][n+1];
        dp[0][0]=true;
        for(int i=1;i<=m;i++)dp[i][0]=false;
        for(int i=0;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(match(i,j))dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*'){
                    dp[i][j]=dp[i][j-1]||dp[i][j-2];
                    if(match(i,j-1))dp[i][j]|=dp[i-1][j];
                }else dp[i][j]=false;
                cout<<dp[i][j];
            }
        }
        return dp[m][n];
    }

//11.盛水最多的容器
    int maxArea(vector<int>& height) {
        int s=0,e=height.size()-1;
        int ans=0;
        while(s<e){
            ans=max(ans,min(height[s],height[e])*(e-s));
            if(height[s]>height[e])--e;
            else ++s;
        }
        return ans;
    }

//12.整数转罗马数字
    string intToRoman(int num) {
        int a[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string s[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int now=0;
        string ans="";
        while(num>=4){
            int n=num/a[now];
            num=num%a[now];
            for(int i=0;i<n;i++){
                ans+=s[now];
            }
            now++;
        }
        for(int i=0;i<num;i++)ans+="I";
        return ans;
    }

//13.罗马数字转整数
    int romanToInt(string s) {
        int a[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string str[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int num[]={1,2,1,2,1,2,1,2,1,2,1,2,1};
        int n=s.size();
        int sta=0;
        int now=0;
        int ans=0;
        while(sta<n){
            for(int i=now;;i++){
                if (s.substr(sta,num[i]).compare(str[i])==0){
                    ans+=a[i];
                    now=i;
                    sta+=num[i];
                    break;
                }
            }
        }
        return ans;
    }

//14.最长公共前缀
    string longestCommonPrefix(vector<string>& strs) {
        int ans=0;
        int n=strs.size();
        while(1){
            if (ans==strs[0].size())return strs[0].substr(0,ans);
            char c=strs[0][ans];
            for(int i=1;i<n;i++){
                if (ans==strs[i].size())return strs[0].substr(0,ans);
                if(strs[i][ans]!=c)return strs[0].substr(0,ans);
            }
            ans++;
        }
        return strs[0].substr(0,ans);
    }

//15.三数之和
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            while (i!=0&&nums[i]==nums[i-1]){
                i++;
                if(i==n-1)break;
            }
            if(i==n-1)break;
            int now=nums[i];
            int j=i+1,k=n-1;
            while(j<k){
                if(nums[j]+nums[k]>-now){
                    k--;
                }
                else if(nums[j]+nums[k]<-now){
                    j++;
                }
                else {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    while(nums[j]==nums[j-1]&&j<k)j++;
                }
            }
        }
        return ans;
    }
};
int main() {
    //std::cout << "Hello, World!" << std::endl;
    Solution s;
    cout<<' ';
    bool a=s.isMatch("abb","b*");
    cout<<' '<<a;
    //int nums = {-1,0,1,2,-1,-4}
    vector<int> nums = {0,0,0,0};
    vector<vector<int>> m=s.threeSum(nums);
    return 0;
}
