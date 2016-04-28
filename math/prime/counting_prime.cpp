#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;


#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define each(it,c) for(__typeof(c.begin()) it=c.begin(); it!=c.end(); it++)
#define INF 1<<30
#define mp make_pair
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vp;
typedef map<int, int> mpii;

typedef long long ll;

vi primes;
vi nop; //number of prime
vector<bool> isp; //is_prime
map<ll, ll> Leh; //memo
vi psi3; //memo
int MaX; // 適当な打ち切り 立方根を目指したい（未実装）
// i 番目の素数を求めるところ 特に ｂ がMaXよりも大きくなると エラー
// ある程度確保しないとだめ．

int p235;
int phi235;

//使ってない
map< pair<long long, long long> ,long long> psi_memo;

ll phi(ll n) {
	ll ret = n;
	int i = 2;
	while (i*i <= n) {
		if (n%i == 0) {
			ret -= ret / i;
			while (n%i == 0) {
				n /= i;
			}
		}
		i++;
	}
	if (n>1) ret -= ret / n;
	return ret;
}

ll psi(ll x, ll a) {
	if (a == 1) return x - x / 2;
	if (a == 2) return (x - x / 2 - x / 3 + x / 6);
	if (a == 3) return (x / p235*phi235 + psi3[x%p235]);
	if (x < primes[a]) return 1;
	if (x<MaX && primes[a] * primes[a] > x) {
		return nop[x] - a + 1;
	}
	ll w1 = psi(x, a - 1);
	ll w2 = psi(x / primes[a - 1], a - 1);
	return w1 - w2;
}

ll lehmer(ll n) {
	if (n<=MaX) return Leh[n] = nop[n];
	cout<<n<<endl;
	if (Leh.find(n) == Leh.end()) {
		ll a = lehmer(floor(pow(n, 1.0 / 4.0)));
		ll b = lehmer(floor(pow(n, 1.0 / 2.0)));
		ll c = lehmer(floor(pow(n, 1.0 / 3.0)));
		ll Psum = 0;
		for (int i = a; (ll)i < b; i++) {
			ll t = lehmer(n / primes[i]);
			Psum += t;
		}
		for (int i = a; (ll)i < c; i++) {
			ll Bi = lehmer((int)sqrt(n / primes[i]));
			for (ll j = i; j < Bi; j++) {
				Psum += lehmer(floor(n / (primes[i] * primes[j]))) - j;
			}
		}
		ll W = psi(n, a);
		Leh[n] = W + (b + a - 2)*(b - a + 1) / 2 - Psum;
	}
	return Leh[n];
}

void init(int n) {
	MaX = 100000000;
	isp.resize(MaX+1, true);
	nop.resize(MaX+1, 0);
	isp[0] = isp[1] = false;
	for (int i = 2; i < sqrt(MaX)+1; i++) {
		if (isp[i]) {
			for (int j = i*i; j <= MaX; j += i) {
				isp[j] = false;
			}
		}
	}
	REP(i, 1, nop.size()) {
		nop[i] = nop[i - 1];
		if (isp[i]) nop[i]++;
	}
	REP(i, 1, isp.size()) {
		if (isp[i]) primes.pb(i);
	}
	p235 = 2 * 3 * 5;
	phi235 = phi(p235);
	psi3.resize(p235);
	for (int i = 0; i < 3; i++) {
		ll p = primes[i];
		for (int j = p; j < p235; j += p) {
			psi3[j] = 1;
		}
	}
	ll s = 0;
	for (int i = 1; i < p235; i++) {
		s += (1 - psi3[i]);
		psi3[i] = s;
	}
}

int main() {
	ll n; cin >> n;
	init(n);
	cout << lehmer(n) << endl;
	return 0;
}
