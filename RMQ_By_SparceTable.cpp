#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int LG=log2(N);
const int inf=1e9;
int arr[N];
int table[N][LG];
void process(int n){
	int lg=log2(n)+1;
	for(int i=0;i<=N;++i){
		for(int j=0;j<=LG;++j) table[i][j]=inf;
	}
	for(int i=1;i<=n;++i) table[i][0]=arr[i];
	for(int j=1;j<=lg;++j){
		for(int i=1;i<=n;++i){
			table[i][j]=min(table[i+(1<<(j-1))][j-1],table[i][j-1]);
			//cout<<i<<" "<<(i+(1<<j)-1)<<":"<<table[i][j]<<endl;
		}
	}
}
int query(int l,int r){
	int lg=log2(r-l+1);
	return min(table[l][lg],table[r-(1<<lg)+1][lg]);
}
int main(){			//1 based indexing
	int n,l,r,q;
	cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	process(n);
	cin>>q;
	while(q--){
		cin>>l>>r;
		cout<<query(l,r)<<endl;
	}
}
