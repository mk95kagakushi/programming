#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

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
//typedef priority_queue<int, vi, greater<int> > pqi;

typedef long long ll;

struct Date {
	ll Y, M, D;
	static const ll dd[3];
	static const ll days[2][13];
	static const ll dsum[2][13];
	static const string week[7];

	//初期化
	Date() {}
	Date(ll Y_, ll M_, ll D_) { Y = Y_; M = M_; D = D_; }

	//表示
	void p() { cout << this->Y << " " << this->M << " " << this->D << endl; }

	//いずうるう
	static ll is_uruu(ll y){
		return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
	}

	string Week() const {
		int y, m, d, j, k, h;
		y = this->Y; m = this->M; d = this->D;
		if (m <= 2) m += 12, y--;
		j = y / 100;
		k = y % 100;
		h = (d + int((m + 1)*2.6) + k + k / 4 + j / 4 + 5 * j) % 7;
		return week[h];
	}


	//プラス 日付＋ｎ　ｎ日後　
	Date operator+(ll x) const{
		ll y, m, d; y = this->Y; m = this->M; d = this->D;
		ll u = is_uruu(this->Y);
		while (x > dd[u]) {
			x -= dd[u]; y++;
			if (u == 1 && (m > 2)) x++;
			u = is_uruu(y);
		}
		while(x > days[is_uruu(y)][m] - d) {
			x -= (days[is_uruu(y)][m] - d);
			d = 0; m++;
			if (m == 13) { m = 1; y++; }
		}
		d += x;
		Date ret(y, m, d);
		return ret;
	}
	//プラスイコール
	Date &operator+=(ll x) { 
		ll y, m, d; y = this->Y; m = this->M; d = this->D;
		ll u = is_uruu(this->Y);
		while (x > dd[u]) {
			x -= dd[u]; y++;
			if (u == 1 && (m > 2)) x++;
			u = is_uruu(y);
		}
		while (x > days[is_uruu(y)][m] - d) {
			x -= (days[is_uruu(y)][m] - d);
			d = 0; m++;
			if (m == 13) { m = 1; y++; }
		}
		d += x;
		this->Y = y; this->M = m; this->D = d;
		return *this;
	}
	// 日付１－日付２　日付の差
	long long operator-(const Date &that) const {
		ll sgn = 1;
		Date S = *this; Date K = that;
		if (S < K) { swap(S, K); sgn = -1; }
		ll ret = 0; 
		while ( !(S.M == K.M && S.D == K.D) ){
			K += 1; ret++;
		}
		ll u = (S.Y - K.Y);
		K.Y = S.Y - u % 400;
		ret += dd[2] * (u / 400);
		while (S.M != K.M && S.D != K.D) {
			K += 1; ret++;
		}
		return sgn*ret;
	}
	
	//　演算子
	bool operator==(const Date &that) const {
		bool f = true;
		f *= (this->Y == that.Y);
		f *= (this->M == that.M);
		f *= (this->D == that.D);
		return f;
	}
	bool operator!=(const Date &that) const { return !(*this == that); }
	bool operator< (const Date &that) const {
		bool f = false;
		f += (this->Y < that.Y);
		f += (this->Y == that.Y && this->M < that.M);
		f += (this->Y == that.Y && this->M == that.M && this->D < that.D);
		return f;
	}
	bool operator<=(const Date &that) const { return (*this < that) || (*this == that); }
	bool operator> (const Date &that) const { return !(*this < that) && (*this != that); }
	bool operator>=(const Date &that) const { return (*this > that) || (*this == that); }
};

const ll Date::dd[3] = { 365,366,146097 };
const ll Date::days[2][13] = { { 0,31,28,31,30,31,30,31,31,30,31,30,31 },{ 0,31,29,31,30,31,30,31,31,30,31,30,31 } };
const ll Date::dsum[2][13] = { { 0,31,59,90,120,151,181,212,243,273,304,334,365 },{ 0,31,60,91,121,152,182,213,244,274,305,335,366 } };
const string Date::week[7] = { "Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday" };

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	Date d1(a, b, c);
	cout << d1.Week() << endl;
	return 0;
}