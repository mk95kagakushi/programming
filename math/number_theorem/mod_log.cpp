// g++ baby_giant_step.cpp
//
// Summary
// x^k = y mod m となるような k を求める．
//
// Algorithm
// Baby step Giant step
// G = <x> を位数がmを超えない巡回群として
// x^k = y mod m となるような　k　を求める．
// k は　[0,1,...m-1] の中から探すことにする
// b = ceil(sqrt(m)) として
// k = i + j*b となる　0<= i,j <b を探す．
// h = x^(-1) とすれば
// x^(j*b) = y*x^(-1*i) = y*h^(i) となるので
// i = [x^(0*b=0),x^(1*b=b),...,x^(b-1)*b] と
// j = [y*h^0,y*h^1,....,y*h^(b-1)] を計算して並び替えて
// x^i = y*h^j となるものを見つければ良い．
// return k = i+j*b を返せば良い．
// i,jをペアで持っておいて，見つける時は片方だけをソートして
// ２分探索で見つければ良い

//
// input
// x y m
//
// output
// k
//
// date: 2016/04/23


#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define each(it,c) for(__typeof(c.begin()) it=c.begin(); it!=c.end(); it++)
#define INF 1<<30
#define mp make_pair
#define pb push_back

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pair<int, int> > vp;
typedef map<int,int> mpii;
typedef map<ll,ll> mpll;

ll powMod(ll x,ll n, ll mod){
	if(n==0) return 1;
	ll ret = powMod(x*x%mod,n/2,mod);
	if(n&1) ret = ret * x % mod;
	return ret;
}


ll logMod(ll x, ll y, ll m){
	ll b = sqrt(m) + 1; 

	// baby step
	vector< pair<ll,ll> > baby;
	ll yh = y;
	rep(j,b){
		baby.pb(mp(yh,j));
		yh = (yh*x)%m;
	}
	sort(all(baby));

	// giant step
	ll h = powMod(x,b,m);
	ll xh = h;
	REP(i,1,b+1){
		vector< pair<ll,ll> >::iterator it = lower_bound(all(baby),mp(xh,0ll));
		if(it == baby.end()) continue;
		if((*it).first == xh) return i*b - it->second;
		xh = (xh*h)%m;
	}
	return -1;
}

int main(){
	ll x,y,m;
	cin>>x>>y>>m;
	cout<<logMod(x,y,m)<<endl;
	return 0;
}