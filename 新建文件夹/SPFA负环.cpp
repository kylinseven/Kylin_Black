#include<iostream>
#include<cstring>
using namespace std;
const int N=200005;
int n,m,T,head[N],dis[N],num;
bool vis[N],flag;
struct node{
	int to,next,w;
}edge[N<<1];
void SPFA(int u){
	vis[u]=1;
	for(int i=head[u],v;v=edge[i].to,i;i=edge[i].next)
		if(dis[v]>dis[u]+edge[i].w){
			dis[v]=dis[u]+edge[i].w;
			if(vis[v]){
				flag=1;return;
			}
			SPFA(v);
		}
	vis[u]=0;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		memset(head,0,sizeof(head));
		num=0,flag=0,dis[1]=0;
		for(int a,b,w,i=1;i<=m;i++){
			cin>>a>>b>>w;
			edge[++num].to=b,edge[num].next=head[a],edge[num].w=w,head[a]=num;
			if(w>=0) edge[++num].to=a,edge[num].next=head[b],edge[num].w=w,head[b]=num;
		}
		for(int i=1;i<=n&&!flag;i++) SPFA(i);
		if(flag) cout<<"YE5"<<endl;
		else cout<<"N0"<<endl;
	}
	return 0;
}
