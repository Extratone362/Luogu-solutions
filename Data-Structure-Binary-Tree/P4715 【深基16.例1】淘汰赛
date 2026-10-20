//题目：P4715 【深基16.例1】淘汰赛
//链接：https://www.luogu.com.cn/problem/P4715
//算法：我不知道叫什么反正非常脏
//数据结构：结构体
//日期：2026-10-19
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int tag,content;
    
}t[512];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=int(pow(2,n));i++){
        t[i].tag=i;
        cin>>t[i].content;
    }
    while(n-->1){
        for(int i=1;i<=int(pow(2,n));i++){
            t[i]=t[i*2-1].content>t[i*2].content?t[i*2-1]:t[i*2];
            //cout<<t[i].content<<" ";
        }
        //cout<<endl;
    }
    if(t[1].content>t[2].content) cout<<t[2].tag;
    else cout<<t[1].tag;
    return 0;
}