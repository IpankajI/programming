#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1<<20;
int cnr[N];
ll dp1[N],dp2[N];
vector<pair<int,int> > vc;
int main(){
	ios_base::sync_with_stdio(false);
	int t,n,m,k,q,foo,p,mx,submask;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		memset(dp1,0,sizeof dp1);
		memset(dp2,0,sizeof dp2);
		mx=1<<n;
		for(int i=mx;i--;) dp1[i]=1e9,dp2[i]=1e9;
		for(int i=0;i<n;i++) {
			scanf("%d",&cnr[i]);
			dp1[1<<i]=cnr[i];
			dp2[1<<i]=cnr[i];
		}
		for(int i=m;i--;){
			scanf("%d %d",&p,&q);
			foo=0;
			for(int j=q;j--;){
				scanf("%d",&k);
				foo|=1<<(k-1);
			}
			dp1[foo]=min(dp1[foo],p*1ll);
			//printf("%lld haha\n",dp1[foo]);
			dp2[foo]=dp1[foo];
		}
		for(int i=0;i<mx;i++){
			submask=i&(i-1);
			while(submask>0){
				dp1[submask]=min(dp1[i],dp1[submask]);
				dp2[submask]=dp1[submask];
			//	printf("%lld ggg\n",dp1[submask]);
				submask=(submask-1)&i;
			}
		}
		dp2[0]=0;
		for(int i=0;i<mx;i++){
			submask=i&(i-1);
			while(submask>0){
				dp2[i]=min(dp2[i],dp2[submask]+dp1[submask^i]);
				//printf("%lld  %d   kk\n",dp2[i],submask);
				submask=(submask-1)&i;
			}
		}
		printf("%lld\n",dp2[mx-1]);
	}
} 
