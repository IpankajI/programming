#include <cstdio>
using namespace std;
const int N=20,INF=1e9;
int costs[N][N],dp[1<<N];
inline int min(int a,int b){
	return a>b?b:a;
}
int count(int n){
	int cnt=0;
	while(n){
		cnt++;
		n&=n-1;
	}
	return cnt;
}
int solve(int n){
	for(int i=0;i<(1<<n);i++)
		dp[i]=INF;
	dp[0]=0;
	int bitCnt,newMask;
	for(int i=0;i<(1<<n);i++){
		bitCnt=count(i);
		for(int j=0;j<n;j++){
			if((i&(1<<j))==0){
				newMask=i|(1<<j);
				dp[newMask]=min(dp[newMask],dp[i]+costs[bitCnt][j]);
			}
		}
	}
	return dp[(1<<n)-1];
}
int main(){
	freopen("in.txt","r",stdin);
	int n;
	printf("enter dimension of cost matrix\n");
	scanf("%d",&n);
	printf("enter cost matrix\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			scanf("%d",&costs[i][j]);
	}
	printf("%d\n",solve(n) );
}