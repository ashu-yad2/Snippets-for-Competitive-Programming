#include<bits/stdc++.h>

#define ar array 
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for(int i = a; i < b; i++)
 
using namespace std;

typedef long long ll; 
typedef vector<int> vi;
typedef pair<int,int> pii;
 
 
const  int mxN = 1e5+5;
const  long long INF= 1e18;
const long long mod= 1e9+7;

const int p = 31;
const int m = 1e9 + 9;

ll p_pow[mxN];

void fill() {
	p_pow[0] = 1;
	for(int i = 1; i < mxN; i++) {
		p_pow[i] = (p_pow[i- 1] * p) % m;
	}
}

ll bin_pow(ll a, ll b) {
	ll res = 1;
	while(b > 0) {
		if(b & 1) res = (res * a) % m;
		a = (a * a) % m;
		b = b >> 1;
	}
	return res;
}

int main() {
	int t;
	cin >> t;
	fill();
	while(t--) {
		string s;
		cin >> s;
		int n = s.size();
		vector<ll> hash(n, 0);
		
		ll h = 0;
		
		for(int i = 0; i < n; i++) {
			h = (h + (s[i] - 'a' + 1) * p_pow[i]) % m;
			hash[i] = h;
		}
		int cnt = 0;
		
		for(int i = 0; i < (n - 2)/2; i++) {
			ll t1 = hash[i];
			int j = 2 * i + 1;
			ll _t1 = (((hash[j] - (hash[i]) + m) % m) * bin_pow(p_pow[i + 1], m - 2)) % m;
			
			int k = j + (n - (j + 1))/2;
			
			ll t2 = (((hash[k] - (hash[j]) + m) % m) * bin_pow(p_pow[j + 1], m - 2)) % m;
			ll _t2 = (((hash[n - 1] - (hash[k]) + m) % m) * bin_pow(p_pow[k + 1], m - 2)) % m;
			
			if(t1 == _t1 && t2 == _t2) cnt++;
		}
		cout << cnt << endl;
	}
}
			
			
			
		
		
		
	
		
	
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
