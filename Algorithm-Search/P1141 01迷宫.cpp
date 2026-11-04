#include<bits/stdc++.h>
using namespace std;
int a[1005][1005]={};
int ans[1005][1005]={};
int cnt[1000005]={},idx=1;
int dirx[4]={-1,0,1,0},diry[4]={0,1,0,-1};
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            cin>>c;
            a[i][j]=(c=='1');
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ans[i][j]!=0) continue;
            cnt[idx]=1;
            queue<pair<int,int>> q;
            q.push({i,j});
            ans[i][j]=idx;
            while(!q.empty()){
                int r=q.front().first,c=q.front().second;
                q.pop();
                for(int k=0;k<4;i++){
                    int nr=r+dirx[k],nc=c+diry[k];
                    if(a[nr][nc]!=a[r][c]&&ans[nr][nc]==0&&nr>=0&&nr<n&&nc>=0&&nc<n){
                        q.push({nr,nc});
                        cnt[idx]++;
                        ans[nr][nc]=idx;
                    }
                }
            }
            idx++;
        }
    }
    while(m--){
        int i,j;
        cin>>i>>j;
        cout<<ans[a[i-1][j-1]]<<endl;
    }
    return 0;
}