// divideser game
//
// 1つの整数 n がある．
// 手番のプレイヤーは，nの真の約数個取れる
// 取れなくなった人の負け
//
// ｎ 	: コインの総数 (2以上)
//
// 先手が勝つか？
//
// algorithm
// ＊愚直にグランディ数を計算して mex を求めている．
// ＊解析してあとでわかったことは，
// ＊奇数もしくは 2^(2n+1) だったら先手必負
// ＊奇数のグランディ数はすべて0

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define exist( c, e ) ( (c).find( e ) != (c).end() )

typedef vector<int> vi;
typedef long long ll;

vi g;

int grundy(int x){
	if(g[x]!=-1) return g[x];

	set<int> mex; //使ってない最小を探すための集合

	REP(i,2,x){
		if(x%i==0){
			mex.insert(grundy(x-i));
		}
	}

	int ret = 0;
	while( exist(mex,ret) ) ret++;

	return g[x] = ret;
}

int main(){
	int n;
	cin>>n;
	bool f;
	g.resize(n+1,-1);
	f = (grundy(n)!=0);

	if( f ) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}