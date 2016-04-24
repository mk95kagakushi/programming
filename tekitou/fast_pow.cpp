#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define INF 1<<30
#define mp make_pair
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vp;
typedef map<int, int> mpii;

typedef long long ll;

struct Node {
	int p; //値
	int d; //深さ
	int from; //親
	vi v; //計算済みベクター
	Node(int _p, int _d, int _from, vi _v) {
		p = _p;
		d = _d;
		from = _from;
		v = _v;
	}
};

typedef vector<Node> vn;
vi h;
vector< vn > G;

bool check() {
	bool f = false;
	rep(i, h.size()) f |= (h[i] == -1);
	return f;
}

void init(int n) {
	h.resize(n, -1);
	//add 0
	vi v0; v0.pb(0);
	Node z0(0, 0, -1, v0);
	vn _vn0; _vn0.pb(z0);
	G.pb(_vn0);
	h[0] = 0;
	//add 1
	vi v1; v1.pb(1);
	Node z1(1, 1, 0, v1);
	vn _vn1; _vn1.pb(z1);
	G.pb(_vn1);
	h[1] = 1;
}


void add(Node t, int k) {
	rep(i, t.v.size()) {
		int n = t.p + t.v[i];
		if (n > 100) continue;
		//未更新 か 同じ高さだったら
		if (h[n] == -1 || h[n] == t.d + 1) {
			int pp = n;
			int dd = t.d + 1;
			int ff = t.p;
			vi vv = t.v;
			vv.pb(n);
			Node x(pp, dd, ff, vv);
			G[k].pb(x);
			h[n] = dd;
		}
	}
}

int main() {
	int n; n = 1001;
	init(n);
	int i = 1;
	while (check()) {
		int sz = G[i].size();
		rep(j, sz) {
			Node t = G[i][j];
			add(t, i);
		}
	}

	vp a;
	rep(i, n) {
		a.pb(mp(h[i], i));
	}
	sort(all(a));
	rep(i, n) {
		cout << a[i].second << " " << a[i].first << endl;
	}

	return 0;
}