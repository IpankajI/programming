#include<bits/stdc++.h>
using namespace std;
const int N=1e3+100;
const int NN=sqrt(N);
const int inf=1e9;
int arr[N];		//container array
int R[N];		//results for every segments;
int sg;	//number of segments
void process(int n){
	sg=sqrt(n);
	for(int i=1;i<=sg;++i) R[i]=inf;
	for(int i=1;i<=sg;++i){
		int x=(i-1)*sg;
		for(int j=1;j<=sg;++j){
			R[i]=min(R[i],arr[x+j]);
		}
	}
}
int segNumber(int in){
	for(int i=1;i<=sg+2;++i){
		if(in>(i-1)*sg && in<=i*sg) return i;
	}
}
int query(int l,int r){
	int sl=segNumber(l);
	int sr=segNumber(r);
	int ans=inf;
	for(int i=l;i<=sg*sl && i<=r;++i) ans=min(ans,arr[i]);
	for(int j=sl+1;j<sr;++j) ans=min(ans,R[j]);
	for(int j=r;j>(sr-1)*sg && j>=l;--j) ans=min(ans,arr[j]);
	return ans;
}
int main(){
	int n,q,l,r;
	cin>>n;
	for(int i=1;i<=n;++i) cin>>arr[i];
	process(n);
	cin>>q;			//number of query
	while(q--){
		cin>>l>>r;
		cout<<query(l,r)<<endl; 
	}
}
