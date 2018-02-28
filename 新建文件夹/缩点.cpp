#include<iostream>
using namespace std;
const int N=10005;
const int M=100005;
int n,m,head[N],dfn[N],low[N],vis[N],s[N],top,cnt,ans,num;
int Head[N],w[N],D[N],F[N],tot,in[N];
struct node{
	int x,y,next;
}e[M*2],ne[M*2];
void Tarjan(int u){
	dfn[u]=low[u]=++cnt,vis[u]=1,s[++top]=u;
	for(int i=head[u],v;v=e[i].y,i;i=e[i].next)
		if(!dfn[v]){
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v]) low[u]=min(low[u],dfn[v]);
	if(low[u]==dfn[u])
		while(int k=s[top--]){
			vis[k]=0,F[k]=u;
			if(k==u) break;
			w[u]+=w[k];
		}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		e[i].x=x,e[i].y=y,e[i].next=head[x],head[x]=i;
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i]) Tarjan(i);
	for(int i=1,x,y;x=F[e[i].x],y=F[e[i].y],i<=m;i++)
		if(x!=y) ne[++tot].x=x,ne[tot].y=y,ne[tot].next=Head[x],Head[x]=tot,in[y]++;
	top=0;
	for(int i=1;i<=n;i++)
		if(F[i]==i&&!in[i]) 
			s[++top]=i,D[i]=w[i];
	while(top){
		int k=s[top--];
		for(int i=Head[k],v;v=ne[i].y,i;i=ne[i].next){
			D[v]=max(D[v],D[k]+w[v]);
			if(--in[v]==0) s[++top]=v;
		}
	}
	for(int i=1;i<=n;i++) ans=max(ans,D[i]);
	cout<<ans;
	return 0;
}
