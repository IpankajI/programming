#include<bits/stdc++.h>
using namespace std;
const int N=10000,INF=1e9;
int st[N<<1],arr[N];				//1 base indexing for arr and segment tree st;
void build(int node,int s,int e){	// s for start e for end of arr;
	if(s==e){
		st[node]=arr[s];
		return ;
	}
	int mid=(s+e)>>1,n=node<<1;
	build(n,s,mid);
	build(n+1,mid+1,e);
	st[node]=st[n]<st[n+1]?st[n]:st[n+1]; 
}
int query(int node,int l,int r,int s,int e){	// query from l to r
	if(l>e || r<s) return INF;
	if(l<=s && r>=e) return st[node];
	int x=node<<1,mid=(s+e)>>1;
	int a=query(x,l,r,s,mid);
	int b=query(x+1,l,r,mid+1,e);
	return a<b?a:b;
}
void update(int node,int in,int val,int s,int e){
	if(in==s && in ==e){
		arr[in]=val;
		st[node]=val;
		return;
	}
	int n=node<<1,mid=(s+e)>>1;
	if(s<=in && in<=mid){
		update(n,in,val,s,mid);
	}
	else if(mid+1<=in && in<=e){
		update(n+1,in,val,mid+1,e);
	}
	st[node]=st[n]<st[n+1]?st[n]:st[n+1];
}
int main(){
	int n,q,x,l,r,type;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	build(1,1,n);
	for(int i=1;i<2*n;i++) printf("%d ",st[i]);
	printf("\n");
	for(int i=q;i--;){
		scanf("%d",&type); // 0 for update and 1 for query
		if(type){
			scanf("%d %d",&l,&r);
			printf("%d\n",query(1,l,r,1,n));
		}
		else{
			scanf("%d %d",&l,&r);//l for value ,r for index
			update(1,r,l,1,n);
		}
	}
}
