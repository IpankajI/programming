#include<stdio.h>
typedef long long ll;
#define Get _getchar_nolock()
using namespace std;
const int N=1000002;
ll ST[N<<1],arr[N];
ll getIntLL() {
	ll a=0,s=1;
	char c=0;
	while(c<33) c=Get; 
	if(c=='-') {
	s=-1;
	c=Get;
	}
	while(c>33) {
	a=(a<<3)+(a<<1)+c-'0';
	c=Get;
	} return a*s;
}
int getInt() {
	int a=0,s=1;
	char c=0;
	while(c<33) c=Get; 
	if(c=='-') {
	s=-1;
	c=Get;
	}
	while(c>33) {
	a=(a<<3)+(a<<1)+c-'0';
	c=Get;
	}
	return a*s;
}
void build(int s,int e,int node=1){
	if(s==e) {
		ST[node]=arr[s];
	}
	else{
		int mid=(s+e)/2,y=node<<1;
		build(s,mid,y);
		build(mid+1,e,y^1);
		ST[node]=ST[y]+ST[y^1];
	}
}
ll query(int l,int r,int e,int s=1,int node=1){
	if(s>e || l>e || r<s) return 0;
	if(l<=s && e<=r) return ST[node];
	int mid=(s+e)/2,y=node<<1;
	return query(l,r,mid,s,y)+query(l,r,e,mid+1,y^1);
}
int main(){
	int n,t;
	bool f;
	t=getInt();
//	scanf("%d",&t);
	while(t--){
		n=getInt();
		//scanf("%d",&n);
		f=false;
		for(int i=1;i<=n;i++) arr[i]=getIntLL();  // scanf("%d",&arr[i]);
		build(1,n);
		for(int i=n;i>0;i--){
			for(int j=1;j<=n-i+1;j++){
				if(query(j,j+i-1,n)%2==0){
					printf("%d\n",i);
					f=true;
					break;
				} 
			}
			if(f) break;
		}
	}
}
