//题目：P4913 【深基16.例3】二叉树深度
//链接：https://www.luogu.com.cn/problem/P4913
//算法：DFS
//数据结构：二叉树
//日期：2026-10-19
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    int l,r;
    int size;
}t[1000005];
int maxi=0;
void dfs(int tag,int step){
    if(tag==0) maxi=maxi>(step-1)?maxi:(step-1);
    else{
        dfs(t[tag].l,step+1);
        dfs(t[tag].r,step+1);
    }
}
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i].l>>t[i].r;
    }
    dfs(1,1);
    cout<<maxi;
    return 0;
}