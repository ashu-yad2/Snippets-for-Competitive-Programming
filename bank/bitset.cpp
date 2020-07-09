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

void update(bitset<2001> bit[], int n, int ind, bitset<2001> val) {
	ind++;
	while(ind <= n) {
		bit[ind] ^= val;
		ind += ind & (-ind);
	}
}

bitset<2001> sum(bitset<2001> bit[], int ind) {
	bitset<2001> s;
	ind++;
	while(ind > 0) {
		s ^= bit[ind];
		ind -= ind & (-ind);
	}
	return s;
}


void solve() {
	int n;
	cin >> n;
	int mx = 0;
	vi v(n);
	rep(i, 0, n){
		 cin >> v[i];
		 mx = max(v[i], mx);
	 }
	 
	 int q;
	 cin >> q;
	 
	 bitset<2001> bit[n + 1];
		
		rep(i, 0, n) {
			bitset<2001> b;
			b.set(v[i]);
			update(bit, n, i, b);
		}
		
		while(q--) {
			int a, l, r;
			cin >> a >> l >> r;
			
			if(a == 0) {
				bitset<2001> temp;
				temp[v[l]] = 1;
				update(bit, n, l, temp);
				temp[v[l]] = 0;
				temp[v[r]] = 1;
				update(bit, n, l, temp);
				update(bit, n, r, temp);
				temp[v[r]] = 0;
				temp[v[l]] = 1;
				update(bit, n, r, temp);
				swap(v[l], v[r]);
			}
			
			else {
				bitset<2001> ans;
				if(l <= r) {
					ans = sum(bit, r) ^ sum(bit, l - 1);
				}
				else {
					ans = sum(bit, r) ^ sum(bit, l - 1) ^ sum(bit, n - 1);
				}
				
				cout << ans.count() << endl;
			}
		}
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
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
