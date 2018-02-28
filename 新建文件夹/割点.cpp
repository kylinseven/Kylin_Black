#include<iostream>
using namespace std;
const int N=1e5+5;
int n,m,num,head[N],dfn[N],low[N],cnt,f[N],ans;
bool b[N];
struct edge{
	int to,next;
}e[N<<1];
void add(int x,int y){e[++num]=(edge){y,head[x]},head[x]=num;}
void Tarjan(int u,int fa){
	int child=0;
	dfn[u]=low[u]=++cnt;
	for(int i=head[u],v;v=e[i].to,i;i=e[i].next){
		if(v==fa) continue;
		if(!dfn[v]){
			child++,f[v]=u;
			Tarjan(v,u);
			low[u]=min(low[u],low[v]);
			if(!f[u]&&child>=2&&!b[u]) b[u]=1,ans++;
			else if(f[u]>0&&low[v]>=dfn[u]&&!b[u]) b[u]=1,ans++;
		}
		else if(dfn[v]) low[u]=min(low[u],dfn[v]);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i,i);
	cout<<ans<<endl;
	for(int i=1;i<=n;i++) if(b[i]) cout<<i<<' ';
	return 0;
}
