#include<iostream>
using namespace std;
int n,m,w[5001][5001],dis[5001],ans,minn,k,x,y,z;
void prime(int s){
    for(int i=1;i<=n;i++) dis[i]=w[s][i];
    dis[s]=0;
    for(int i=1;i<n;i++){
        minn=999999999;
        for(int j=1;j<=n;j++)
            if(dis[j]&&dis[j]<minn)
                minn=dis[j],k=j;
        dis[k]=0,ans+=minn;
        for(int j=1;j<=n;j++)
            if(w[k][j]<dis[j])
                dis[j]=w[k][j];
    }
    cin>>ans;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
			w[i][j]=999999999;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        if(z<w[x][y]) w[y][x]=w[x][y]=z;
    }
    prime(n>>1);
    return 0;
}