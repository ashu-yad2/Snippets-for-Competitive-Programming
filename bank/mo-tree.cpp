 #pragma GCC optimize("O3", "unroll-loops")
 #pragma GCC target("avx2")

#include<bits/stdc++.h>

#define int long long
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

int BL[2 * mxN];

struct query{
	int l, r, i, sp, an;
}q[mxN];

vector<pii> factors[1000006];
int prime[1000006];
vi adj[mxN];
int in[mxN], out[mxN], id[2 * mxN], d[mxN], anc[mxN][18], val[mxN], occ[mxN];
int timer;
const int BLOCK = 1100;
int ans;
int m[1000006];
int a[mxN];
int inv[1LL * mxN];

bool cmp(query a, query b) {
	if(a.l/BLOCK != b.l/BLOCK){
		return a.l/BLOCK < b.l/BLOCK;
	}
	return (a.l/BLOCK & 1) ? (a.r < b.r) : (a.r > b.r);
}

inline int mul(int a, int b) {
	int x = a * b;
	if(x >= mod){
		x %= mod;
	}
	return x;
}

void dfs(int u=1, int p=-1) {
	in[u] = ++timer;
	id[timer] = u;
	anc[u][0]=p;
	for(int i=1; i<18; ++i)
		anc[u][i]=~anc[u][i-1]?anc[anc[u][i-1]][i-1]:-1;
	for(int v : adj[u]) {
		if(v==p)
			continue;
		d[v]=d[u]+1;
		dfs(v, u);
	}
	out[u] = ++timer;
	id[timer] = u;
}


int lca(int u, int v) {
	if(d[u]<d[v])
			swap(u, v);
	for(int i=17; ~i; --i)
		if(d[u]-(1<<i)>=d[v])
			u=anc[u][i];
	if(u==v)
		return u;
	for(int i=17; ~i; --i) {
		if(anc[u][i]^anc[v][i]) {
			u=anc[u][i];
			v=anc[v][i];
		}
	}
	return anc[u][0];
}


int power(int a,int b) {
	int res = 1;
	while(b > 0) {
		if(b & 1) res = mul(res, a);
		a = mul(a, a);
		b = b >> 1;
	}
	return res;
}

void inv_mod() {
	for(int i = 0; i < 1LL * mxN; i++) {
		inv[i] = 1LL * power(i, mod - 2);
	}
} 


void sieve() {
	for(int i = 2; i <= 1e6; i++) {
		if(prime[i]) continue;
		for(int j = i; j <= 1e6; j += i) {
			prime[j] = 1;
			int x = j, cnt = 0;
			while((x % i) == 0) { x /= i; cnt++;}
			factors[j].pb({i, cnt});
		}
	}
}


inline void add(int i) {
	occ[i]++;
		for(auto x: factors[val[i]]) {
			ans = mul(ans, inv[m[x.fi] + 1]);
			if(occ[i] == 1)
			ans = mul(ans, m[x.fi] + x.se + 1);
			else ans = mul(ans ,m[x.fi] - x.se + 1);
			if(occ[i] == 1)
			m[x.fi] += x.se;
			else m[x.fi] -= x.se;
		}
}
	
			

inline void del(int i) {
	occ[i]--;
	for(auto x: factors[val[i]]) {
			ans = mul(ans, inv[m[x.fi] + 1]);
			if(occ[i] == 1)
			ans = mul(ans, m[x.fi] + x.se + 1);
			else ans = mul(ans ,m[x.fi] - x.se + 1);
			if(occ[i] == 1)
			m[x.fi] += x.se;
			else m[x.fi] -= x.se;
		}
}	

 	
signed main(){
	int t;
	scanf("%lld", &t);
	sieve();
	inv_mod();
	while(t--) {
		int n;
		scanf("%lld", &n);
		timer = 0;
		memset(occ, 0, sizeof(occ));
		memset(m, 0, sizeof(m));
		for(int i = 0; i < mxN; i++) adj[i].clear();
		ans = 1;
		rep(i, 0, n - 1) {
			int a, b;
			scanf("%lld %lld", &a, &b);
			adj[a].pb(b);
			adj[b].pb(a);
		}
		
		rep(i, 1, n + 1) {
			scanf("%lld", &val[i]);
		}
		dfs();
		
		int x, u, v;
		cin >> x;
		rep(i, 1, x + 1) {
			scanf("%lld %lld", &u, &v);
			
			q[i].sp = lca(u, v);
			if(in[u] > in[v]) swap(u, v);
			if(q[i].sp == u) q[i].l = in[u], q[i].r = in[v];
			else q[i].l = out[u], q[i].r = in[v];
			q[i].i = i;
	}
	
	sort(q + 1, q + x + 1, cmp);
	
	
	int currL = q[1].l, currR = q[1].l - 1, L, R; 
	
	
	rep(i, 1, x + 1) {
		L = q[i].l ; R = q[i].r;
		
		while (currL > L){
			add(id[currL-1]);
			currL--;
		}
		while (currR < R){
			add(id[currR + 1]);
			currR++;
		}
		while (currL < L){
			del(id[currL]);
			currL++;
		}
		while (currR > R){
			del(id[currR]);
			currR--;
		}
		
		
		if(q[i].sp != id[currL] && q[i].sp != id[currR]) {
			add(q[i].sp);
		}
			a[q[i].i] = ans;
			if(q[i].sp != id[currL] && q[i].sp != id[currR]) {	
			del(q[i].sp);
		}
		}
	
	rep(i , 1, x + 1) {
		printf("%lld\n", a[i]);
	}
}
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
