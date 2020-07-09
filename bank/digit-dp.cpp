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
 
 
const  int mxN = 1e5+5;
const  long long INF= 1e18;
const long long mod= 1e9+7;

string s;
ll n, k;
ll dp[10001][5][2]; // states : string size(), int constraint on digit, checker on number is small or equal

ll solve(int idx, int cnt, int check) {
	if(idx == n) {
		if(cnt == 0) return 1;
		else return 0;
	}
	ll limit = s[idx] - '0';
	if(check) limit = 9;
	
	ll &ans = dp[idx][cnt][check];
	if(ans != -1) return ans;
	ans = 0;
	for(ll i = 0; i <= limit ; i++) {
		if(i == 0) { // inserting 0; (the item without constraints)
			if(i == limit) ans += solve(idx + 1, cnt, check);
			else ans += solve(idx + 1, cnt, 1);
		}
		else {
			if(cnt == 0) continue; // the item with constraints
			if(i == limit)ans += solve(idx + 1, cnt - 1, check);
			else ans += solve(idx + 1, cnt - 1, 1);
		}
	}
	
	return ans;
}
				 
			
 	
int main(){
	cin >> s >> k;
	n = (ll)s.size();
	memset(dp, -1 , sizeof(dp));
		
	ll ans = solve(0, k, 0);
	cout << ans << endl;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
