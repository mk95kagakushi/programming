// coin game2
//
// 円状に並んだコインを交互に1枚か2枚取る．
// 2枚取る場合は連続しているコインでなければならない．
// スペースが空いている場所は連結しているとはみなされない
//
// x 	: コインの総数
//
// 先手が勝つか？
//
// algorithm
// ＊最初先手が１個か２個取る．
// ＊次に同じ数の２グループができるるように反対側を1つか２つ取る．
// ＊あとは相手と同じことをすればよい
// ＊コマが3個以上の時，後手必勝

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

	// 2個以上なら後手必勝
	if(x<=2) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}