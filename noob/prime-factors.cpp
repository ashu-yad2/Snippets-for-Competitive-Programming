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
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
 
 
const  int mxN = 1e4+5;
const  long long INF= 1e18;
const long long mod= 1e9+7;
 
vector<pii> factors[mxN];
int prime[mxN];
void factor() {
	
	for(int i = 1; i <= 10000; i++) {
		int x = i;
		for(int j = 2; j *j <= x; j++) {
			int cnt  = 0;
			if(x % j == 0) {
				while((x % j) == 0){ x /= j; cnt++;}
			factors[i].pb({j, cnt});
		}
		}
		if(x > 1) factors[i].pb({x, 1});
	}
}

void sieve() {
	for(int i = 2; i <= 1e4; i++) {
		if(prime[i]) continue;
		for(int j = i; j <= 1e4; j += i) {
			prime[j] = 1;
			int x = j, cnt = 0;
			while((x % i) == 0) { x /= i; cnt++;}
			factors[j].pb({i, cnt});
		}
	}
}
			

int main(){
//	factor();
	sieve();
	int t;
	cin >>t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		int arr[m + 5] = {0};
		while(n--) {
			int x; cin >> x;
			for(auto i: factors[x]) {
				arr[i.fi] = max(arr[i.fi], i.se);
			}
		}
		
		int ans1 = 1, ans2 = 1;
		
		for(int i = 2; i <= m; i++) {
			int temp = 1;
			for(auto x: factors[i]) {
				if(x.se > arr[x.fi]) {
					temp *= (ll)pow(x.fi, x.se - arr[x.fi]);
				}
			}
			if(temp > ans1) {
				ans1 = temp;
				ans2 = i;
			}
		}
		cout << ans2 << endl;
		
	}
}
	
	
