#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,cnr[1005],dp[1005],tmp,ans;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&cnr[i]);
		dp[1]=cnr[1];
		ans=cnr[1];
		for(int i=2;i<=n;i++){
			dp[i]=cnr[i];
			for(int j=1;j<i;j++){
				tmp=0;
				if(cnr[i]>cnr[j]){
					tmp=dp[j]+cnr[i];
					if(dp[i]<tmp) dp[i]=tmp;
				}
			}
			if(ans<dp[i]) ans=dp[i];
		}
		printf("%d\n",ans);
	}
}
