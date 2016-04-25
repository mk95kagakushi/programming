// coin game4
//
// x個のコインがある
// 最初の先手の手番は，ｘー1個まで好きな数取って良い
// 手番のプレイヤーは，直前に取ったコマの2倍まで取って良い
// 取れなくなった方の負け
//
// x 	: コインの総数 (2以上)
//
// 先手が勝つか？
//
// algorithm
// ＊フィボナッチ2進数にする
// ＊1番最下位ビットに近い1が立っているビットを取る
// ＊事実1．フィボナッチ2進法は隣り合うビットが立つことがない
// ＊事実2． F_{n+2} > 2*F_{n} 
// ＊事実3．フィボナッチ数（どこか1ビットしか立っていない）の時は
//         F_{n} ー＞ F_{n-k} をしても2倍まで取れるからすべて取られてしまう
//         F_{n} ー＞ not F_{n-k} にしてもさっきと同じ戦法が使われる
// ＊結論 フィボナッチ数で回ってきた時 必ず負ける
// ＊初期がフィボナッチ数でなければ，一番右の1が立っているビットを取れば，先手必勝

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

	ll f1 = 1, f2 = 1;

	while(1){
		if(f2==x){
			cout<<"No"<<endl;
			break;
		}
		if(f2 > x){
			cout<<"Yes"<<endl;
			break;
		}
		f2 = f2 + f1;
		f1 = f2 - f1;
	}

	return 0;
}