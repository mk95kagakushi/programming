#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define INF 1<<30
#define mp make_pair
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pair<int, int> > vp;

typedef long long ll;

string itos(int N){
  stringstream ss;
  ss<<N;
  return ss.str();
}

int main(){
    int a,b; cin>>a>>b;
    string nsa = itos(a);
    string nsb = itos(b);
    cout<<nsa<<"+"<<nsb<<"="<<itos(a+b)<<endl;
    return 0;
}
