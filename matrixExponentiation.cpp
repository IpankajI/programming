#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int M=1e9+7;
ll** mul(ll** m1, ll** m2){
	ll** tmp=new ll*[2];
	tmp[0]=new ll[2];
	tmp[1]=new ll[2];
	tmp[0][0]=((m1[0][0]*m2[0][0])%M+(m1[0][1]*m2[1][0])%M)%M;
	tmp[0][1]=((m1[0][0]*m2[0][1])%M+(m1[0][1]*m2[1][1])%M)%M;
	tmp[1][0]=((m1[1][0]*m2[0][0])%M+(m1[1][1]*m2[1][0])%M)%M;
	tmp[1][1]=((m1[1][0]*m2[0][1])%M+(m1[1][1]*m2[1][1])%M)%M;
	return tmp;
}
ll** expp(int n,ll** m){
	if(n==1) return m;
	if(n&1){
		return mul(m,expp(n-1,m));
	}
	else{
		ll** tmp=new ll*[2];
		tmp[0]=new ll[2];
		tmp[1]=new ll[2];
		tmp=expp(n/2,m);
		return mul(tmp,tmp);
	}
}
ll solve(int n){
	if(n==1) return 1;
	if(n==2) return 3;
	ll** m=new ll*[2];
	m[0]=new ll[2];
	m[1]=new ll[2];
	m[0][0]=2;
	m[0][1]=2;
	m[1][0]=1;
	m[1][1]=0;
	ll** tmp;
	tmp=expp(n-2,m);
	return (tmp[0][1]+3*tmp[0][0])%M;
}
int main(){
	int t;
	ll n;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		printf("%lld\n",solve(n));
	}
}
//problem link-https://www.codechef.com/problems/CSUMD
