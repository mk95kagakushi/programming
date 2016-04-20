// g++ chinese_gmp.cpp -lgmpxx -lgmp
//
// Summary
// 中国人剰余の定理 m_iはそれぞれは互いに素
//
// a_1 = X mod m_1
// a_2 = X mod m_2
// ...
// a_n = X mod m_n
// 
// X を求める
//
// Algorithm
// 拡張ユークリッドの互除法
//
// input format
// n
// a1 m1
// a2 m2
// .....
// an mn
//
// output
// ans
//
// date:2016/03/14
//  	2016/04/20

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
#define each(it,c) for(__typeof(c.begin()) it=c.begin(); it!=c.end(); it++)
#define EXIST(c,e) ( (c).find( e ) != (c).end() )
#define INF 1<<30
#define mp make_pair
#define pb push_back 

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pair<int, int> > vp; 
typedef map<int,int> mpii;
typedef priority_queue<int, vi, greater<int> > pqi;

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

mpz_class chinese(mpz_class a1,mpz_class m1,mpz_class a2,mpz_class m2){
    mpz_class y1 = modinv(m1,m2);
    mpz_class y2 = modinv(m2,m1);
    return (m2*a1*y2+m1*a2*y1)%(m1*m2);
}

int main(){
	vector<mpz_class> a;
	vector<mpz_class> m;
	int n; cin>>n;
	rep(i,n){
		mpz_class at,mt;
		cin>>at>>mt;
		a.pb(at);
		m.pb(mt);
	}
	mpz_class mod;
	mpz_class ans;
	ans = a[0];
	mod = m[0];
	rep(i,n-1){
		ans = chinese(ans,mod,a[i+1],m[i+1]);
		mod = mod * m[i+1];
	}

    cout<<ans<<endl;

    return 0;
}
