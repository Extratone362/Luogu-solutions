#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[1005];
int check(){
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=fa[i]==i;
    return cnt;
}
int find_fa(int x){
    if(fa[x]==x) return x;
    return fa[x]=find_fa(fa[x]);
}
int enemy[1005];
int main(){
    
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=0;i<m;i++){
        char c;
        int p,q;
        cin>>c>>p>>q;
        if(c=='F'){
            if(find_fa(p)!=find_fa(q)) fa[find_fa(q)]=find_fa(p);
        }
        else{
            if(enemy[p]) {if(find_fa(enemy[p])!=find_fa(q)) fa[find_fa(q)]=find_fa(enemy[p]);enemy[q]=p;}
            else if(enemy[q]) {if(find_fa(enemy[q])!=find_fa(p)) fa[find_fa(p)]=find_fa(enemy[q]);enemy[p]=q;}
            else {enemy[p]=q; enemy[q]=p;}
        }
    }
    cout<<check();                                             
}
