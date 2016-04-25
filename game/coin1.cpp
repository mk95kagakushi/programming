// coin game1
//
// x 	: コインの総数
// k 	: 取って良いコインの数の種類
// a_i	: 取って良いコインの数 （1を必ず含む）
//
// 先手が勝つか？
//
// algorithm
// ＊相手を負けの状態にすることができれば勝ち
// ＊基本を負けとしておいて，1つでも負けへの遷移があれば勝ちにする
//

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
	int k;
	vi a;
	// input
	cin>>x>>k;
	rep(i,k){
		int t; cin>>t;
		a.pb(t);
	}
	vector<bool> g; // ゲームの状態
	g.resize(x+1,false); //0 ~ x までの勝ち（1）負け（0）


	// 0〜ｘまで下から順に遷移できるところへ遷移する
	REP(i,1,x+1){
		// 使えるコインのループ
		rep(j,k){
			// 0<= i-a[j] ： 遷移ができる
			// !g[i-a[j]] ： 負けへの遷移
			g[i] = g[i] || ( 0<= i-a[j] && !g[i-a[j]] );
		}
	}

	// 先手必勝なら Yes
	if(g[x]) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}