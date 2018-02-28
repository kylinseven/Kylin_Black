#include<iostream>
#include<cstring>
using  namespace std;
const int inf(0x1f1f1f1f);
int n,m,map[105][105],d[105][105],ans=inf,what[3],p[105][105];
void print(int x,int y){
	if(!p[x][y]) cout<<x<<' ';
	else print(x,p[x][y]),print(p[x][y],y);
}
int main(){
	cin>>n>>m;
	memset(map,inf,sizeof(map));
	memset(d,inf,sizeof(d));
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;
		d[x][y]=d[y][x]=map[x][y]=map[y][x]=min(map[x][y],z);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<k;i++)
			for(int j=i+1;j<k;j++)
				if(d[i][j]+map[i][k]+map[k][j]<ans){
					ans=d[i][j]+map[i][k]+map[k][j];
					what[0]=k,what[1]=i,what[2]=j;
				}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(d[i][j]>d[i][k]+d[k][j])
					d[i][j]=d[i][k]+d[k][j],p[i][j]=k;
	}
	if(ans==inf) cout<<"No solution.";
	else print(what[1],what[2]),cout<<what[2]<<' '<<what[0];
	return 0;
}
