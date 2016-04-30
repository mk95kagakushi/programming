// euclid game
//
// 2つの整数 a,b がある．
// 手番のプレイヤーは，大きい方から小さい方のｎ倍を引く．
// 片方を0にした方の勝ち
//
// x 	: コインの総数 (2以上)
//
// 先手が勝つか？
//
// algorithm
// ＊ぼくのあり本の276ページ
// ＊ａ ＜＝ ｂ ＜ 2ａ の時 シミュレーションするしか無い．
// ＊2ａ ＜ ｂ      の時 必勝 
// ＊b = aq + r の時  aq個 とるか a(q-1)個取るか選べてどっちかが少なくとも勝ちパターン
// ＊だから，勝ちパターンじゃない方に遷移すれば必勝
// ＊もちろん ａがｂの倍数だったら必勝

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
	int a,b;
	cin>>a>>b;
	bool f = true;

	while(1){
		if(a>b) swap(a,b);

		//必勝パターン
		if(b%a==0) break;

		// 2a < b の時必勝
		if(2*a < b) break;

		b -= a;
		f = !f;
	}

	if( f ) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}