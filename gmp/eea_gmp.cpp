// g++ eea_gmp.cpp -lgmpxx -lgmp
//
// Summary
// 拡張ユークリッドの互除法を求める
// a*x + b*y = gcd(x,y) となる a,bを求める
//
// Algorithm
// 拡張ユークリッドの互除法
//
// input
// x y
//
// output
// a x b y c
//
// date: 2016/03/14
//  	 2016/04/21

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <gmpxx.h>

using namespace std;

#define BASE 10

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define INF 1<<30
#define mp make_pair
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pair<int, int> > vp;

typedef long long ll;

mpz_class eea(mpz_class a,mpz_class b,mpz_class& x,mpz_class& y){
	mpz_class gcd = a;
	if(cmp(b,0)!=0){
		gcd = eea(b,a%b,y,x);
		y -= (a/b) * x;
	}
	else{
		x = 1; y = 0;
	}
	return gcd;
}

int main(){
	mpz_class a,x,b,y,c;
	cin>>x>>y;
	c = eea(x,y,a,b);
    cout<<a<<" "<<x<<" "<<b<<" "<<y<<" "<<c<<endl;
    return 0;
}
