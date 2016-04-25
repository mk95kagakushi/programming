// coin game3
//
// x個のコインがある
// 手番のプレイヤーは 1〜ｋ個，コインを取って良い
// 取れなくなった方の負け
//
// x 	: コインの総数
// k	: 取って良いコインの最大値
//
// 先手が勝つか？
//
// algorithm
// ＊1回目にすべて取れれば先手の勝ち
// ＊ｋ＋1 の倍数個残っている状態で回ってきたら負け
// ＊初期状態がK+1の倍数だったら後手必勝
// ＊K+1の倍数以外のすべて状態からK+1の倍数の状態へ遷移可能を使って考える

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back

typedef vector<int> vi;
typedef long long ll;

int main(){
	int x;
	cin>>x;
	cin>>k;

	// 初期状態が 1回ですべてのコマが取れる or K+1 の倍数でなかったら
	// 初期状態が K+1の倍数だったら後手必勝
	if(x<=k || x%(k+1)!=0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}