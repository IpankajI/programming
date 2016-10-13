#include<bits/stdc++.h>
using namespace std;
const int N=10000,INF=1e9;
int arr[N],st[N<<1],lazy[N<<1];		// 1 based indexing
void build(int node,int s,int e){
	if(s==e){
		st[node]=arr[s];
		return;
	}
	int n=node<<1,mid=(s+e)>>1;
	build(n,s,mid);
	build(n^1,mid+1,e);
	st[node]=st[n]+st[n^1];
}
void lazyUpdate(int node,int l,int r,int s,int e,int val){ //update from l to r
	int n=node<<1,mid=(s+e)>>1;
	if(lazy[node]!=0){
		st[node]+=(e-s+1)*lazy[node];
		if(s!=e){
			lazy[n]+=lazy[node];
			lazy[n^1]==lazy[node];
		}
		lazy[node]=0;
	}
	if(s>e || l>e || r<s) return;
	if(l<=s && e<=r){
		st[node]+=(e-s+1)*val;
		if(s!=e){
			lazy[n]+=val;
			lazy[n^1]+=val;
		}
		else{
			arr[s]+=val;
		}
		return ;
	}
	lazyUpdate(n,l,r,s,mid,val);
	lazyUpdate(n^1,l,r,mid+1,e,val);
	st[node]=st[n]+st[n^1];
}
int lazyQuery(int node,int l,int r,int s,int e){ // query from l to r
	if(l>e || r<s || s>e) return 0;
	int n=node<<1,mid=(s+e)>>1;
	if(lazy[node]!=0){
		st[node]+=(e-s+1)*lazy[node];
		if(s!=e){
			lazy[n]+=lazy[node];
			lazy[n^1]==lazy[node];
		}
		lazy[node]=0;
	}
	if(l<=s && e<=r) return st[node];
	return lazyQuery(n,l,r,s,mid)+lazyQuery(n^1,l,r,mid+1,e);
}
int main(){
	int n,l,r,q,x,val;
	scanf("%d %d",&n,&q);	// n for number of elements in array, q for number of query
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);  
	build(1,1,n);
	for(int i=1;i<n*2;i++) printf("%d   ",st[i]);
	printf("\n");
	for(int i=q;i--;){
		scanf("%d",&x);// x=0 for query 1 for update;
		if(x){
			scanf("%d %d %d",&l,&r,&val);
			lazyUpdate(1,l,r,1,n,val);
		}
		else{
			scanf("%d %d",&l,&r);
			printf("%d\n",lazyQuery(1,l,r,1,n));
		}
	}
}
