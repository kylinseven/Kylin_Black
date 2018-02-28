#include<iostream>
using namespace std;
int dfn[100],low[100],head[100],num,number,stack[100],top,k,n,m,x,y;
bool vis[100];
struct node{
	int next,to;
}a[1000];
void tarjan(int u){
	dfn[u]=low[u]=++number,vis[u]=1,stack[++top]=u;
	for(int i=head[u],v;v=a[i].to,i;i=a[i].next)
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(vis[v]) low[u]=min(low[u],dfn[v]);
	if(low[u]==dfn[u]){
		k=stack[top--];
		while(k!=u){
			cout<<k<<' ';
			k=stack[top--];
		}
		cout<<u<<endl;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		a[++num].next=head[x],a[num].to=y,head[x]=num;
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);
	return 0;
}