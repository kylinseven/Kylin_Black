#include<iostream>
#include<cstdlib>
#include<cctype>
using namespace std;
int father[500010],head[500010],qhead[500010],que[500010],cnt,x,y,n,m,s;
struct Edge{
	int next,to;
}edge[1000010];
struct qEdge{
	int next,to,ans=0;
}q[1000010];
void add(int x,int y){
	edge[++cnt].to=y,edge[cnt].next=head[x],head[x]=cnt;
}
void qadd(int x,int y,int k){
	q[k].to=y,q[k].next=qhead[x],qhead[x]=k;
}
int find(int x){
	return father[x]!=x? father[x]=find(father[x]):father[x];
}
void unionn(int x,int y){
	x=find(x);y=find(y);
	father[y]=x;
}
void tarjan(int x){
	que[x]=1;
	for(int i=head[x],to;to=edge[i].to,i;i=edge[i].next)
		if(!que[to]){
			tarjan(to);
			unionn(x,to);
		}
	for(int i=qhead[x],to;i,to=q[i].to;i=q[i].next)
		if(que[to]==2){
			q[i].ans=find(to);
			if(i%2)	q[i+1].ans=q[i].ans;
			else q[i-1].ans=q[i].ans;
		}
	que[x]=2;
}
int main(){
	cin>>n>>m>>s;
	for(int i=1;i<n;++i){
		cin>>x>>y;
		add(x,y);add(y,x);
		father[i]=i;
	}
	father[n]=n;
	for(int i=1;i<=m;++i){
		cin>>x>>y;
		qadd(x,y,i*2-1);qadd(y,x,i*2);
	}
	tarjan(s);
	for(int i=1;i<=n;++i)
		cout<<q[i*2].ans;
	return 0;
}
