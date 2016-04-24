#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <sstream>

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
	vi s;
	Node(int _p, int _d, int _from, vi _s, vi _v) {
		p = _p;
		d = _d;
		from = _from;
		s = _s;
		v = _v;
	}
};

typedef vector<Node> vn;
vi h;
vvi par;
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
	par.resize(n);
	//add 1
	vi v1; v1.pb(1);
	vi s1; s1.pb(1);
	Node z1(1, 1, 0, s1, v1);
	G1.pb(z1);
	h[1] = 1;
	h[0] = 0;
	par[0].pb(-1);
	par[1].pb(0);
}

multimap< int, string > shiki;

void p(int n, vi s) {
	sort(all(s));
	stringstream ss;
	char chr[10];
	sprintf(chr, "%4d : ", n);
	string str = string(chr);
	ss << str;
	rep(i, s.size()) {
		ss << s[i] << " ";
	}
	ss << endl;
	str = ss.str();
	shiki.insert(mp(n, str));
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
			vi ss = t.s;
			ss.pb(t.v[i]);
			p(n, ss);
			Node x(pp, dd, ff, ss, vv);
			G2.pb(x);
			h[n] = dd;
			par[n].pb(t.p);
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
		a.pb(mp(h[i], mp(i,par[i][0])));
	}

	int m = 5;
	sort(all(a));

	string st = "";
	each(it,shiki){
		if(st == it->second) continue;
		st = it->second;
		cout<<st;
	}
	//sort(all(shiki));
	//rep(i, shiki.size()) {
	//	cout << shiki[i].second;
	//}

	return 0;
}