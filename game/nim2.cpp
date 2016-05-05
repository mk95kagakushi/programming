// nim2  silver dollar
//
// 直線上に並ぶコマを左に動かして行って，動かせなくなったら負け
// 好きな山から1個以上取って良い．取れなくなったら負け．
//
// ｎ 	: コマの数
// ai 	: それぞれのコマの位置 （0から始まる）
//
// 先手が勝つか？
//
// algorithm
// ＊偶数番目と奇数番目のコマの間を山の間として 単純なニム そのままニム和＝0なら後手必勝
// ＊コマの数が偶数なら，0に追加すればいい． 
// ＊何もない状態＝ニム和 ＝ 0
// ＊ニム和が0の状態 ＝ 負けの状態（相手が追いかけてくれば負け）

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define pb push_back

typedef vector<int> vi;
typedef long long ll;

int main(){
	int n;
	cin>>n;
	vi a; a.resize(n);
	rep(i,n) cin>>a[i];

	//奇数個だったらダミーを1個追加
	if(n%2==1) a.pb(0);
	sort(all(a));

	int x = 0;
	for(int i=0;i<n-1;i+=2){
		int t = a[i+1] - a[i] - 1;
		x ^= t;
	}

	if(x!=0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}