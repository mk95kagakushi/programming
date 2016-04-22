// g++ mod_inv.cpp
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

using namespace std;

typedef long long ll;

ll eea(ll a,ll b,ll& x,ll& y){
	ll gcd = a;
	if(b != 0){
		gcd = eea(b,a%b,y,x);
		y -= (a/b) * x;
	}
	else{
		x = 1; y = 0;
	}
	return gcd;
}

ll modinv(ll a,ll m){
	ll a,m,c,s,t;
	c = eea(a,m,s,t);
	if(c==1){
		return (s%m+m)%m;
	}
	else{
		return -1;
	}
}

int main(){
	ll a,m; cin>>a>>m;
	cout<<modinv(a,m)<<endl;
	return 0;
}
