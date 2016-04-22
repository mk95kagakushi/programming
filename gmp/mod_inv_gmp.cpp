// g++ mod_inv_gmp.cpp -lgmpxx -lgmp
//
// Summary
// m を法とした a の逆元を求める
//
// Algorithm
// 拡張ユークリッドの互除法
//a*x = 1 mod m となるxを求める
//
// input
// a m
//
// output
// ans
//
// date: 2016/03/14
//  	 2016/04/22

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

mpz_class modinv(mpz_class a,mpz_class m){
    mpz_class x,y,g;
    g = eea(a,m,x,y);
    if(cmp(g,1)==0){
        while(x<0){
            x+=m;
        }
        return x;
    }
    else{
        return -1;
    }
}

int main(){
	mpz_class a,m;
	cin>>a>>m;
	cout<<modinv(a,m)<<endl;
    return 0;
}
