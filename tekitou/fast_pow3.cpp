#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdio>
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
vi par;
vector< vn > G;
vn G1;
vn G2;
int N;

bool check() {
	bool f = false;
	rep(i, h.size()) f |= (h[i] == -1);
	return f;
}

void init(int n) {
	h.resize(n, -1);
	par.resize(n, -1);
	//add 1
	vi v1; v1.pb(1);
	Node z1(1, 1, 0, v1);
	G1.pb(z1);
	h[1] = 1;
	h[0] = 0;
}


void add(Node t, int k) {
	rep(i, t.v.size()) {
		int n = t.p + t.v[i];
		if (n+1 > N) continue;
		//未更新 か 同じ高さだったら
		//if (h[n] == t.d + 1)cout << "@:" << n << " "<< t.p<<" "<< t.v[i]<<endl;
		if (h[n] == -1 || h[n] == t.d + 1) {
			int pp = n;
			int dd = t.d + 1;
			int ff = t.p;
			vi vv = t.v;
			vv.pb(n);
			Node x(pp, dd, ff, vv);
			G2.pb(x);
			h[n] = dd;
			par[n] = t.p;
		}
	}
}

int main() {
	N = 1001;
	init(N);
	int i = 0;
	while (check()) {
		vn t;
		int sz = G1.size();
		rep(j, sz) {
			Node t = G1[j];
			add(t, i);
		}
		i++;
		G1 = G2;
		G2.clear();
	}

	vector<pair< int , pair<int,int> > > a;
	rep(i, N) {
		a.pb(mp(h[i], mp(i,par[i])));
	}

	int m = 5;
	sort(all(a));
	for (int i = 0; i < N;i+=m) {
		rep(j, m) {
			printf("%4d:", a[i + j].second.first);
			printf("%3d ", a[i + j].first);
			printf("%4d ", a[i + j].second.second);
			cout << ( (j==m-1)?"":"   " );
			if (i + j == N-1) {
				cout << endl;
				return 0;
			}
		}
		cout << endl;
	}

	return 0;
}