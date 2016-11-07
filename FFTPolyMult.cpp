#include <bits/stdc++.h>
#define cpx complex<double>
#define pi 3.14159265359
using namespace std;
vector<cpx> FFT(vector<int> vc){
	int n=vc.size();
	if(n==1){
		vector<cpx> tmp;
		tmp.push_back(cpx(1.0*vc[0],0.0));
		return tmp;
	}
	int half=n/2;
	vector<int> v0,v1;
	for(int i=0;i<half;i++){
		v0.push_back(vc[i<<1]);
		v1.push_back(vc[i<<1^1]);
	}
	vector<cpx> Y0=FFT(v0),Y1=FFT(v1),foo(n);
	cpx w(1,0),wn(cos(2*pi/n),sin(2*pi/n));
	for(int i=0;i<half;i++){
		foo[i]=Y0[i]+w*Y1[i];
		foo[i+half]=Y0[i]-w*Y1[i];
		w*=wn;
	}
	return foo;
}
vector<cpx> iFFT(vector<cpx> vc){
	int n=vc.size();
	if(n==1){
		return vc;
	}
	int half=n/2;
	vector<cpx> v0,v1;
	for(int i=0;i<half;i++){
		v0.push_back(vc[i<<1]);
		v1.push_back(vc[i<<1^1]);
	}
	vector<cpx> Y0=iFFT(v0),Y1=iFFT(v1),foo(n);
	cpx w(1,0),wn(cos(2*pi/n),sin(-2*pi/n));
	for(int i=0;i<half;i++){
		foo[i]=Y0[i]+w*Y1[i];
		foo[i+half]=Y0[i]-w*Y1[i];
		w*=wn;
	}
	return foo;
}
vector<cpx> comMul(vector<cpx> c1,vector<cpx> c2){
	int n1=c1.size(),n2=c2.size(),mx,mn;
	mx=max(n1,n2);
	mn=min(n1,n2);
	vector<cpx> res;
	for(int i=0;i<mn;i++) res.push_back(c1[i]*c2[i]);
	for(;mn<mx;mn++) res.push_back(cpx(0,0));
	return res;
}
int main() {
	vector<cpx> coef;
	vector<int> coef1,coef2;
	int n,m,tmp;
	scanf("%d %d",&n,&m);		// n and m degree of two polynomials
	n++;
	m++;
	for(int i=n;i--;) {			// enter n+1 coefficients as c0+c1*x+c2*x*x+....
		scanf("%d",&tmp);
		coef1.push_back(tmp);
	}
	tmp=1;
	while(tmp<=n) tmp<<=1;
	for(int i=n;i<tmp;i++) coef1.push_back(0);
	tmp<<=1;
	for(int i=tmp>>1;i<tmp;i++) coef1.push_back(0);
	for(int i=m;i--;) {			// enter m+1 coefficients as c0+c1*x+c2*x*x+....
		scanf("%d",&tmp);
		coef2.push_back(tmp);
	}
	tmp=1;
	while(tmp<=m) tmp<<=1;
	for(int i=m;i<tmp;i++) coef2.push_back(0);
	tmp<<=1;
	for(int i=tmp>>1;i<tmp;i++) coef2.push_back(0);
	coef=iFFT(comMul(FFT(coef1),FFT(coef2)));
	for(int i=0;i<(n+m-1);i++){
		cout<<round(real(coef[i]))/tmp<<"  "; // coefficients of polynomial which is product of
	}										 // two polunomials 
}
