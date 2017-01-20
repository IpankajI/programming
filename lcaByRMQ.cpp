#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> gh[N],agh[N];
int F[N],index[N],in,A[N],E[N];
bool visited[N];
pair<int,int> edge[N];
void eulerArray(int x){
	visited[x]=1;
	E[++in]=x;
	if(F[x]==0) F[x]=in;
	for(int i=0;i<agh[x].size();++i){
		if(!visited[agh[x][i]]){
			eulerArray(agh[x][i]);
			E[++in]=x;
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
int ST[N<<1];
int makeST(int in,int s, int e){
	int mid=(s+e)/2;
	if(s>e) return 1e9;
	if(s==e){
		ST[in]=E[s];
		return E[s];
	}
	int l=makeST(in*2,s,mid);
	int r=makeST(in*2+1,mid+1,e);
	ST[in]=l<r?l:r;
	return ST[in];
}
int queryST(int in,int l,int r,int s,int e){
	int mid=(s+e)/2;
	int left=in*2;
	int right=in*2+1;
	if(l>e || r<s) return 1e9;
	if(l<=s && r>=e) return ST[in];
	int ll=queryST(left,l,r,s,mid);
	int rr=queryST(right,l,r,mid+1,e);
	return ll<rr?ll:rr;
}
void swap(int &x,int &y){
	int t=x;
	x=y;
	y=t;
}
int main(){
	int n,s,u,v,q;
	// tree
	cin>>n;				//n is number of node in tree
	for(int i=n-1;i--;){
		cin>>u>>v;
		edge[i]=make_pair(u,v);
		gh[u].push_back(v);
		gh[v].push_back(u);
	}
	memset(visited,0,n+1);
	// mapping of tree
	cin>>s; 		//s is starting node;
	bfs(s);
	for(int i=n-1;i--;){
		agh[A[edge[i].first]].push_back(A[edge[i].second]);
		agh[A[edge[i].second]].push_back(A[edge[i].first]);
	}
	memset(visited,0,n+1);
	// making eulerArray E;
	in=0;
	eulerArray(1);
	for(int i=1;i<2*n;i++) cout<<E[i]<<" ";
	cout<<endl;
	// making segment Tree
	for(int i=0;i<=n*2;++i) ST[i]=1e9;
	makeST(1,1,2*n-1);
	//for(int i=1;i<2*n;i++) cout<<ST[i]<<" ";
	// query
	cin>>q;
	for(int i=q;i--;){
		cin>>u>>v;
		int x=F[A[u]];
		int y=F[A[v]];
		//cout<<x<<" "<<y<<endl;
		if(x>y) swap(x,y);
		cout<<index[queryST(1,x,y,1,n*2-1)]<<endl;
	}
}
