#include<bits/stdc++.h>
using namespace std;
bool dp[20][1<<15];
int main(){
	int n,m,mat[20][20],u,v;
	scanf("%d %d",&n,&m);
	memset(mat,0,sizeof mat);
	for(int i=m;i--;){
		scanf("%d %d",&u,&v);
		mat[u][v]=1;
		mat[v][u]=1;
	}
//	printf("\n");
	memset(dp,0,sizeof dp);
	for(int i=0;i<n;i++){
		dp[i][1<<i]=1;
	}
	for(int mask=1;mask<(1<<n);mask++){
		for(int i=0;i<n;i++){
			if(!(mask&(1<<i))){
				for(int j=0;j<n;j++){
					if(dp[j][mask] && mat[i][j]) {
						dp[i][mask^(1<<i)]=1;
					//	printf("%d %d\n",i,mask^(1<<i));
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(dp[i][(1<<n)-1]){
			printf("YES");
			return 0;
		}
	}
	printf("NO");
}
//problem link-https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/tutorial/#dpbitmasksol
