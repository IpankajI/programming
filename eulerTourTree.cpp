#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> gh[N],agh[N];
int F[N],index[N],in,A[N];
bool visited[N];
pair<int,int> edge[N];
void eulerArray(int x){
	visited[x]=1;
	cout<<index[x]<<" ";
	for(int i=0;i<agh[x].size();++i){
		if(!visited[agh[x][i]]){
			eulerArray(agh[x][i]);
			cout<<index[x]<<" ";
		}
	}
}
void bfs(int x){
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		visited[x]=1;
		++in;
		A[x]=in;
		index[in]=x;
		for(int i=0;i<gh[x].size();++i){
			if(!visited[gh[x][i]]){
				q.push(gh[x][i]);
			}
		}
	}
}
int main(){
	int n,s,u,v;
	cin>>n>>s;		//n number of nodes in tree and s is starting node
	for(int i=n-1;i--;){
		cin>>u>>v;
		edge[i]=make_pair(u,v);
		gh[u].push_back(v);
		gh[v].push_back(u);
	}
	memset(visited,0,n+1);
	bfs(s);
	for(int i=n-1;i--;){
		agh[A[edge[i].first]].push_back(A[edge[i].second]);
		agh[A[edge[i].second]].push_back(A[edge[i].first]);
	}
	memset(visited,0,n+1);
	cout<<endl;
	eulerArray(1);
}
