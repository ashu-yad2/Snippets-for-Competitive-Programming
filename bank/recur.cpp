// recursion when ans of different segements is to be combined
#include<bits/stdc++.h>
 
#define ar array 
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for(int i = a; i < b; i++)
#define deb(x) cout << #x << "=" << x << endl
#define PI 3.1415926535897932384626
#define endl '\n'
 
using namespace std;
 
typedef long long ll; 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
 
 
const  int mxN = 1e5+5;
const  long long INF= 1e18;
const long long mod= 1e9+7;

vi v;

int get(int l, int r, int h) {
	if(l > r) return 0;
	
	int ind = -1;
	int val = 2e9;
	for(int i = l; i <= r; i++) {
		if(v[i] < val) {
			ind = i;
			val = v[i];
		}
	}
	
	int temp = min(r - l + 1, get(l, ind - 1,val ) + get(ind + 1 , r, val) + val - h);
	return temp;
}

void solve() {
	int n;
	cin >> n;
	v.clear();
	v.resize(n);
	rep(i, 0, n) cin >> v[i];
	
	int ans = get(0, n - 1, 0);
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t = 1;
	//cin >> t;
	while(t--) {
		solve();
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
