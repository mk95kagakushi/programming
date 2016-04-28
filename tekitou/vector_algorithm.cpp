#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

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
typedef pair<int,int> pii;
typedef vector<pair<int, int> > vp;
typedef map<int,int> mpii;
typedef priority_queue<int, vi, greater<int> > pqi;

typedef long long ll;


int main(){
	int n; cin>>n;
	vi a(n);
	rep(i,n){
		cin>>a[i];
	}
	int a_min = *min_element(all(a));
	int a_max = *max_element(all(a));
	int a_sum = accumulate(all(a),0);
	sort(all(a));

	vi::iterator lb;
	vi::iterator ub;
	int vmin = 10, vmax = 20;
	lb = lower_bound(all(a), vmin);
	ub = upper_bound(all(a), vmax);

	cout<<a_min<<" "<<a_max<<" "<<a_sum<<endl;
	for(vi::iterator it = lb; it != ub; it++){
		cout << *it << " ";
	}
	cout<<endl;
	return 0;
}
