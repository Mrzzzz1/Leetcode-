#include <iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
//5.最长回文子串
    string longestPalindrome(string s) {
        int n=s.size();
        bool dp[1001][1001];
        int ans=1;
        int sta=0;
        for(int j=0;j<n;j++){
            for(int i=0;i<=j;i++){
                if(s[i]==s[j]&&(j-i<3||dp[i+1][j-1])){
                    dp[i][j]=true;
                    if (j-i+1>ans){
                        ans=j-i+1;
                        sta=i;
                    }
                } else dp[i][j]=false;

            }
        }
        return s.substr(sta,ans);
    }
public:
//6.字形变换
    string convert(string s, int numRows) {
        if (numRows==1)return s;
        vector<vector<char>> v(numRows);
        int n=s.size();
        int now=0;
        bool flag=true;//表示向下
        for(int i=0;i<n;i++){
            if(flag)v[now++].push_back(s[i]);
            else v[now--].push_back(s[i]);
            if (now==0)flag=true;
            else if (now==numRows-1)flag=false;
        }
        string ans="";
        vector<char>::iterator iter;
        for (int i=0;i<numRows;i++){
            for (iter=v[i].begin();iter!=v[i].end();iter++){
                ans+=*iter;
            }
        }
        return ans;
    }
// 7. 整数反转
    int reverse(int x) {
        vector<int> v;
        int flag = 0;
        if (x < 0) {
            if (x <= -pow(2, 31))return 0;
            x = -x;
            flag = 1;
        }
        while (x) {
            v.push_back(x % 10);
            x /= 10;
        }
        long ans = 0;
        vector<int>::iterator it;
        int n = v.size() - 1;
        for (it = v.begin(); it != v.end(); it++) {
            ans += *it * pow(10, n--);
        }
        if (flag == 1)ans = -ans;
        if (ans >= pow(2, 31) - 1 || ans <= -pow(2, 31)) {
            return 0;
        }
        return int(ans);
    }

//8.字符串转换整数
    int myAtoi(string s) {
        long ans=0;
        vector<int>v;
        int n=s.size();
        int i=0;
        int flag=1;
        while (s[i]==' ')i++;
        if (s[i]=='-'||s[i]=='+'){
            if(s[i]=='-')flag=-flag;
            i++;
        }

        while(i<n&&s[i]>='0'&&s[i]<='9'){
            v.push_back(s[i++]-'0');
        }
        int num=v.size(),j=0;
        for(int i=num-1;i>=0;i--){
            if (v[i]!=0&&j>=12){
                ans=pow(2,31);
                break;
            }
            ans+=v[i]*pow(10,j++);
            if (ans>=pow(2,31)){
                ans=pow(2,31);
                break;
            }
        }
        if (flag==-1)ans=-ans;
        if (ans>=pow(2,31))ans=pow(2,31)-1;
        else if(ans<=-pow(2,31))ans=-pow(2,31);
        return int(ans);
    }
//9.回文数
    bool isPalindrome(int x) {
        if (x<0)return false;
        vector<int> v;
        while(x!=0){
            v.push_back(x%10);
            x/=10;
        }
        int n=v.size();
        for(int i=0;i<(n+1)/2;i++){
            if (v[i]!=v[n-1-i])return false;
        }
        return true;

    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution s;
    s.convert("AB",1);
    s.myAtoi("20000000000000000000");
    s.isPalindrome(121);
    return 0;
}
