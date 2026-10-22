//题目：P1305 新二叉树
//链接：https://www.luogu.com.cn/problem/P1305
//数据结构：二叉树
//日期：2026-10-22
#include<bits/stdc++.h>
using namespace std;
struct Node{
    char c;
    int r,l,size;
}t[27];
void dfs(int pre){
    if(t[pre].size==0) return;
    if(t[pre].size==1){
        cout<<char(pre+'a'-1);
        return;
    }
    
    cout<<char(pre+'a'-1);
    dfs(t[pre].l);
    dfs(t[pre].r);
}

int root=0,idx=1;
int main(){
    int n;
    cin>>n;
    char x,xl,xr;
    cin>>x>>xl>>xr;
    //t[x-'a'].size=1;
    int root=x-'a'+1;
    if(xl!='*'){
        t[x-'a'+1].l=xl-'a'+1;
        t[t[x-'a'+1].l].size=1;
    }
    if(xr!='*'){
        t[x-'a'+1].r=xr-'a'+1;
        t[t[x-'a'+1].r].size=1;
    }
    int n1=n;
    n--;
    while(n--){
        cin>>x>>xl>>xr;
        if(xl!='*'){
            t[x-'a'+1].l=xl-'a'+1;
            t[t[x-'a'+1].l].size=1;
        }
        if(xr!='*'){
            t[x-'a'+1].r=xr-'a'+1;
            t[t[x-'a'+1].r].size=1;
        }
    }
    /*for(int i=0;i<26;i++){
        if(t[i].size) cout<<i<<" "<<t[i].size<<" "<<t[i].l<<" "<<t[i].r<<endl;
    }*/
    //cout<<endl;
    bool flag=1;
    //cout<<n1<<endl;
    //cout<<root<<endl;
    t[root].size=n1;
    while(flag){
        flag=0;
        for(int i=1;i<=26;i++){
            if(i==root) continue;
            if(t[i].size==0) continue;
            if(t[i].size<t[t[i].l].size+t[t[i].r].size+1){
                //cout<<t[t[i].l].size<<" "<<t[t[i].r].size<<endl;
                flag=1;
                t[i].size=t[t[i].l].size+t[t[i].r].size+1;
            }
        }
        //for(int i=0;i<26;i++) cout<<t[i].size<<" ";
        //cout<<endl<<endl;
    }
    
    dfs(root);
    return 0;
}