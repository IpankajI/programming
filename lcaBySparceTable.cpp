#include<bits/stdc++.h>
using namespace std;
const int N=1000,LG=log2(N)+1;
vector<int> adj[N];
int parent[N],level[N],P[N][LG],n;
void dfs(int node,int prev){
	parent[node]=prev;
	for(int i=0;i<adj[node].size();i++){
		if(adj[node][i]!=prev){
			level[adj[node][i]]=level[node]+1;
			dfs(adj[node][i],node);
		}
	}
}
int lca(int u,int v){
	if(level[u]<level[v]){ //swap(u,v)
		int x=u;
		u=v;
		v=x;
	}
	int dis=level[u]-level[v];
	while(dis>0){
		int raiseU=log2(dis);
		u=P[u][raiseU];
		dis-=1<<raiseU;
	}
	if(u==v) return u;
	for(int j=LG;j--;){
		if(P[u][j]!=P[v][j]){
			u=P[u][j];
			v=P[v][j];
		}
	}
	return parent[u];
}
int main(){
	int m,u,v;
//	freopen("in.txt","r",stdin);
	scanf("%d %d",&n,&m); // n for number of nodes and m for number of queries
	for(int i=n-1;i--;){
		scanf("%d %d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// setting height (level) and parent of nodes by dfs
	dfs(1,-1);
	//lca by sparce table ->initialise P[][] 
	for(int i=0;i<=n;i++) for(int j=0;j<LG;j++) P[i][j]=-1;
	for(int i=1;i<=n;i++) P[i][0]=parent[i];
	for(int j=1;j<LG;j++){
		for(int i=1;i<=n;i++){
			if(P[i][j-1]!=-1) P[i][j]=P[P[i][j-1]][j-1];
		}
	}
	for(int i=m;i--;){
		scanf("%d %d",&u,&v);
		printf("%d\n",lca(u,v));
	}
}
