// nim1
//
// 単純なニム
// 好きな山から1個以上取って良い．取れなくなったら負け．
//
// ｎ 	: 山の数
// ai 	: それぞれの山の値
//
// 先手が勝つか？
//
// algorithm
// ＊単純なニム そのままニム和＝0なら後手必勝
// ＊何もない状態＝ニム和 ＝ 0
// ＊ニム和が0の状態 ＝ 負けの状態（相手が追いかけてくれば負け）

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
	int n;
	cin>>n;
	int x = 0;

	rep(i,n){
		int t; cin>>a;
		x ^= a;
	}

	if(x!=0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}