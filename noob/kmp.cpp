#include<bits/stdc++.h>
 
#define ar array 
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz(v) int((v).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for(int i = a; i < b; i++)
#define deb(x) cout << #x << "=" << x << endl
#define PI 3.1415926535897932384626
#define endl '\n'
 
using namespace std;
 
typedef long long ll; 
typedef long double ld; 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
 
const  int mxN = 1e6+5;
const  long long INF= 1e18;
const long long mod= 1e9+7;

string text, pat;
int lps[mxN], ans[mxN];
int n, m;

void compute_lps() {

  for(int i = 1; i < m; i++) {
    int j = lps[i - 1];
    while(j > 0 && pat[i] != pat[j]) {
      j = lps[j - 1];
    }
    if(pat[i] == pat[j]) j++;
    lps[i] = j;
  }
}

void kmp() {
  int i = 0, j = 0;
  while(i < n) {
    if(pat[j] == text[i]) { i++; j++;}

    if(j == m) { // pattern found;
      ans[i - 1] = 1;
      j = lps[j - 1];
    }
    else if(i < n && pat[j] != text[i]) {
      if(j != 0)  j = lps[j - 1];
      else i++;
    }
  }
}


void solve() {
  cin >> text >> pat;

  n = sz(text);
  m = sz(pat);
  
  compute_lps();
  kmp();

  rep(i, 0, m) cout << lps[i] << " ";
  cout << endl;
  rep(i, 0, n) cout << ans[i] << " ";
  cout << endl;

}

int main() {
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int t = 1;
cin >> t;
while(t--) {
solve();
}
}

