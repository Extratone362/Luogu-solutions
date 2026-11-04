#include<bits/stdc++.h>
using namespace std;
long long int a[2005][4]={};
vector<int> g[2005];//g[i]的元素为由i可以到达的点的编号
int head[2005],idx=0;
bool issquare(long long int n){
    long long r=sqrt(n);
    return r*r==n||(r+1)*(r+1)==n;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        
        idx=0;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1];
            g[i].clear();
            if(issquare(a[i][0])) head[idx++]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(issquare(a[i][1]*a[j][0])) g[i].push_back(j);
            }
        }
        int ans=2147483647;
        bool flag=1;
        for(int i=0;i<idx;i++){

            for(int j=0;j<n;j++) a[j][2]=a[j][3]=0;
            queue<int> q;
            q.push(head[i]);
            a[head[i]][2]=a[head[i]][3]=1;
            while(!q.empty()){
                int tmp=q.front();
                q.pop();
                a[tmp][2]=1;
                bool f=1;
                
                if(issquare(a[tmp][1])&&tmp!=head[i]){
                    ans=ans<a[tmp][3]?ans:a[tmp][3];
                }
                for(int j=0;j<g[tmp].size();j++){
                    if(a[g[tmp][j]][2]==1) continue;
                    a[g[tmp][j]][2]=1;
                    a[g[tmp][j]][3]=a[tmp][3]+1;
                    q.push(g[tmp][j]);
                }
            }
        }
        if(ans==2147483647) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
