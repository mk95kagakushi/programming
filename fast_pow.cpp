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
typedef pair<int,int> pii;
typedef vector<pair<int, int> > vp;
typedef map<int,int> mpii;

typedef long long ll;

struct Node{
    int h; //深さ
    int v; //値
    int from; //親
    vi c; //計算済み
    Node(int _v, int _from, vi _c){
        v = _v;
        from = _from;
        c = _c;
    }
};

typedef vector<Node> vn;
vi d;
vector< vn > G;

bool check(){
    bool f = false;
    rep(i,d.size()) f |= (d[i]==-1);
    return f;
}

void init(int n){
    d.resize(n,-1);
    vi p0; p0.pb(0);
    Node z0(0,0,p0);
    vn _vn0; _vn0.pb(z0);
    G.pb(_vn0);
    vi p1; p1.pb(1);
    Node z1(1,0,p1);
    vn _vn1; _vn1.pb(z1);
    G.pb(_vn1);
}

int main(){
    int n; n = 101;
    int i = 1;
    while(check()){
        int sz = 
    }

    
    return 0;
}