#include<iostream>
using namespace std;
int head[100],next[100],to[100],cnt,num,n,m,dfn[100],low[100];
void Tarjan(int u,int fa){
    low[u]=dfn[u]=++num;
    for(int i=head[u],v;v=to[i],i;i=next[i])
        if(!dfn[v]){
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]) cout<<u<<"--"<<v<<endl;
        }
        else if(v!=fa) low[u]=min(low[u],dfn[v]);
}
int main(){
    cin>>n>>m;
    for(int i=1,x,y;i<=m;i++){
        cin>>x>>y;
        to[++cnt]=y,next[cnt]=head[x],head[x]=cnt;
        to[++cnt]=x,next[cnt]=head[y],head[y]=cnt;
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) Tarjan(i,i);
    return 0;
} 
