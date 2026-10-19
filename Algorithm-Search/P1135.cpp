//题目：P1135 奇怪的电梯
//链接：https://www.luogu.com.cn/problem/P1135 
//算法：DFS+剪枝+记忆化 
//日期：2026-10-11 

#include<bits/stdc++.h>
using namespace std;
int n,a,b,k[210],ministep=2147483647;
bool s[210]={};
int pres[210]={};
void dfs(int current,int step){
    if(s[current]) return;
    if(step>=pres[current]) return;
    pres[current]=step;
    if(step>=ministep) return;
    if(current==b){
        ministep=step<ministep?step:ministep;
        return;
    }
    else{
        s[current]=1;
        if(current+k[current]<=n) dfs(current+k[current],step+1);
        if(current-k[current]>=0) dfs(current-k[current],step+1);
        s[current]=0;
    }
}
int main(){
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        pres[i]=2147483647;
    }
    dfs(a,0);
    if(ministep==2147483647) ministep=-1;
    cout<<ministep;
    return 0;
}