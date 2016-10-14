//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1000005;
int arr[N],K[N],curL,curR,sq;
long long ans=0,R[N];
struct Q{
	int l,r,in;
} qu[N];
bool cmp(Q x,Q y){
	int p=x.l/sq,q=y.l/sq;
	if(p==q){
		return x.r<y.r;
	}
	else return p<q;
}
void execute(int l,int r,int index){
	while(curL<l) {
		ans+=arr[curL]*(1-(K[arr[curL]]<<1));
		K[arr[curL++]]--;
	}  
	while(curL>l) {
		curL--;
		ans+=arr[curL]*(1^(K[arr[curL]]<<1));
		K[arr[curL]]++;
	}  
	while(curR<r){
		curR++;
		ans+=arr[curR]*(1^(K[arr[curR]]<<1));
		K[arr[curR]]++;
	}   
	while(curR>r){
		ans+=arr[curR]*(1-(K[arr[curR]]<<1));
		K[arr[curR--]]--;
	}
	R[index]=ans;
}
int main(){
	int n,t;
	scanf("%d %d",&n,&t);
	sq=sqrt(n);
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	Q x;
	int u,v;
	for(int i=1;i<=t;i++){
		scanf("%d %d",&u,&v);
		x.in=i;
		x.l=u;
		x.r=v;
		qu[i]=x;
	}
	sort(&qu[1],qu+(t+1),cmp);
	for(int i=1;i<=t;i++) execute(qu[i].l,qu[i].r,qu[i].in);
	for(int i=1;i<=t;i++) printf("%I64d\n",R[i]);
}
