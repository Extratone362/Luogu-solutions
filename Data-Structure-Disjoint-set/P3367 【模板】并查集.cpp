//题目：P3367 【模板】并查集
//链接：https://www.luogu.com.cn/problem/P3367
//数据结构：并查集
//日期：2026-11-04

#include<bits/stdc++.h>
using namespace std;
int fa[200005]={};
int n,m;
int find_root(int t){
    if(fa[t]==t) return t;
    else return fa[t]=find_root(fa[t]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    while(m--){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1) fa[find_root(x)]=find_root(y);
        else{
            cout<<((find_root(x)==find_root(y))?'Y':'N')<<endl;
        }
    }
    return 0;
}
