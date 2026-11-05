//题目：P1111 修复公路
//链接：https://www.luogu.com.cn/problem/P1111
//数据结构：并查集
//日期：2026-11-05
#include<bits/stdc++.h>
using namespace std;
int n,m;
struct info{
    int x,y,t;
}s[100005];
int fa[1005];
bool cmp(info a,info b){
    return a.t<=b.t;
}
bool check(){
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=fa[i]==i;
    return cnt==1;
}
int find_fa(int x){
    if(fa[x]==x) return x;
    return fa[x]=find_fa(fa[x]);
}
int main(){
    
    cin>>n>>m;
    for(int i=0;i<m;i++) cin>>s[i].x>>s[i].y>>s[i].t;
    sort(s,s+m,cmp);
    //for(int i=0;i<n;i++) cout<<s[i].x<<" "<<s[i].y<<" "<<s[i].t<<endl;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=0;i<m;i++){
        if(find_fa(s[i].x)!=find_fa(s[i].y)) fa[find_fa(s[i].x)]=find_fa(s[i].y);
        if(check()) {cout<<s[i].t;return 0;}
    }
    cout<<-1;
}
