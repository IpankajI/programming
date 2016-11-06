#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,cnr[1005],dpMax[1005],dp[1005],tmp,ans;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&cnr[i]);
	dp[1]=1;
	dpMax[1]=1;
	ans=1;
	for(int i=2;i<=n;i++){
		dp[i]=1;
		dpMax[i]=1;
		for(int j=1;j<i;j++){
			if(cnr[i]>cnr[j]){
				dpMax[i]=max(dpMax[i],1+dpMax[j]);
			}
			else if(cnr[i]<cnr[j]){
				dp[i]=max(dp[i],dp[j]+1);
				dp[i]=max(dp[i],dpMax[j]+1);
			}
			else{
				dpMax[i]=max(dpMax[i],1+dpMax[j]);
				dp[i]=max(dp[i],dp[j]+1);
				dp[i]=max(dp[i],dpMax[j]+1);
			}
		}
		if(ans<dp[i]) ans=dp[i];
	}
	printf("%d",ans);
}
