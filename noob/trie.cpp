#include<bits/stdc++.h>
 
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i,n) for(int i = 0; i < n; i++)
#define for1(i,n) for(int i = 1; i <= n; i++)
#define ford(i,n) for(int i = n-1; i >= 0; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
 
 
const  int mxN = 2e6+5;
const  long long INF= 1e18;
const long long mod= 1e9+7;

int trie[mxN][26];
int cnt[mxN];
int n, k;
int node;
ll ans;

void insert(string s) {
	int u = 0; 
	for(int i = 0; i < (int)s.size(); i++) {
		if(!trie[u][s[i] - 'A']) {
			trie[u][s[i] - 'A'] = node++; // new node
		}
		u = trie[u][s[i] - 'A']; 
	}
	cnt[u]++; // string end
}


void dfs(int u, int d) {
	for(int i = 0; i < 26; i++) {
		if(trie[u][i]) {
			dfs(trie[u][i], d + 1);
			cnt[u] += (cnt[trie[u][i]] % k);
		}
	}
	ans += (cnt[u] / k) * d;
}

 
int main(){
		int t;
		cin >> t;
		for1(l, t) {
			node = 1;
			ans = 0;
			for(int i = 0; i < mxN; i++){
				cnt[i] = 0; 
				for(int j = 0; j < 26; j++){ 
					trie[i][j] = 0;
				}
			}
		
		
		cin >> n >> k;
		
		forn(i, n) {
			string s;
			cin >> s;
			insert(s);
		}
		dfs(0, 0);
		cout << "Case #"<<l<<":"<<" " << ans << endl;
	}
}
