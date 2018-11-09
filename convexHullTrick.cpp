// https://www.spoj.com/problems/ACQUIRE/
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
typedef long long ll;

using namespace std;
const int N=1e5+100;



vector<ll> M,B;
ll pointer;


bool bad(int l1, int l2, int l3){
	return (B[l3]-B[l1])*(M[l1]-M[l2]) < (B[l2]-B[l1])*(M[l1]-M[l3]);
}

void add(ll m, ll b){
	M.pb(m);
	B.pb(b);

	while(M.size()>2 && bad(M.size()-3,M.size()-2,M.size()-1)){
		M.erase(M.end()-2);
		B.erase(B.end()-2);
	}

}

ll query(ll x){
	if(pointer>= M.size())
		pointer=M.size()-1;

	while(pointer< M.size()-1 && 
		M[pointer]*x+B[pointer] > M[pointer+1]*x+B[pointer+1])
		pointer++;

	return M[pointer]*x+B[pointer];
}

int main(){
	ios_base::sync_with_stdio(false);
	// freopen("input","r",stdin);


	ll n;
	pair<ll,ll> plots[N],rects[N];
	cin>>n;
	for(ll i=0;i<n;++i){
		cin>>plots[i].ff>>plots[i].ss;
	}
	sort(plots,plots+n);

	ll cnt=0;
	for(ll i=0;i<n;++i ){
		while(cnt>0 && rects[cnt-1].ss <= plots[i].ss)
			--cnt;
		rects[cnt++]=plots[i];
	}

	ll cost;
	pointer=0;
	add(rects[0].ss, 0);

	for(int i=0;i<cnt;++i){
		cost = query(rects[i].ff);
		if(i < n-1)
			add(rects[i+1].ss,cost);
	}
	cout<<cost<<endl;
	
}