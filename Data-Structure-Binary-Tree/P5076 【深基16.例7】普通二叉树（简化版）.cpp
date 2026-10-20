//题目：P5076 【深基16.例7】普通二叉树（简化版）
//链接：https://www.luogu.com.cn/problem/P5076
//数据结构：二叉树
//日期：2026-10-20
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val,l,r,size;
}t[10005];
int idx=0,root=0;
void insert(int &p,int x){
    if(p==0){
        p=++idx;
        t[p].val=x;
        t[p].size=1;
        return;
    }
    if(x<t[p].val) insert(t[p].l,x);
    else insert(t[p].r,x);
    t[p].size=t[t[p].l].size+t[t[p].r].size+1;
}
int get_rank(int p,int x){
    if(p==0) return 1;
    if(t[p].val>=x) return get_rank(t[p].l,x);
    else return t[t[p].l].size+1+get_rank(t[p].r,x);
}
int get_kth(int p,int x){
    if(p==0) return -1;
    //if(x==0) return 1; 
    if(t[t[p].l].size>=x) return get_kth(t[p].l,x);
    else if(t[t[p].l].size+1==x) return t[p].val;
    else return get_kth(t[p].r,x-t[t[p].l].size-1);
}

int main(){
    int q;
    cin>>q;
    while(q--){
        int x,op;
        cin>>op>>x;
        switch(op){
            case 1:{
                cout<<get_rank(root,x)<<endl;
                break;}
            case 2:{
                cout<<get_kth(root,x)<<endl;
                break;}
            case 3:{
                int ans=-2147483647,p=root;
                while(p!=0){
                    if(t[p].val<x){
                        ans=t[p].val;
                        p=t[p].r;
                    }
                    else p=t[p].l;    
                }
                cout<<ans<<endl;
                break;}
            case 4:{
                int ans=2147483647,p=root;
                while(p!=0){
                    if(t[p].val>x){
                        ans=t[p].val;
                        p=t[p].l;
                    }
                    else p=t[p].r;
                }
                cout<<ans<<endl;
                break;}
            case 5:{
                insert(root,x);
                break;}
        }
    }
    return 0;
}