#include<bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
typedef vector<vector<ll> > matrix;
const int K = 4;

matrix mul(matrix A, matrix B) {
	matrix C(K, vector<ll> (K));
	forn(i,K) forn(j, K) forn(k, K)
		C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
	return C;
}

matrix power(matrix A, ll p) {
	if(p == 1) {
		return A;
	}
	if(p % 2) 
		return mul(A, power(A, p - 1));
		
	matrix X = power(A, p/2);
	return mul(X, X);
}

ll solve(ll N) {
	vector<ll> F1(K);
	F1[0] = 6516;
	F1[1] = 108;
	F1[2] = 1;
	F1[3] = 1260 * 35;
	matrix T(K, vector<ll> (K));
	forn(i, K) forn(j, K) T[i][j] = 0;
	
	T[0][0] = 108;
	T[0][1] = (-3 * 36 * 36 + mod) % mod;
	T[0][2] = 36 * 36 * 36;
	T[0][3] = 1;
	T[1][0] = T[2][1] = T[3][3] = 1;
	
	if(N <= 2) return F1[2 - N];
	
	T = power(T, N - 2);
	
	ll res = 0;
	forn(i, K) 
		res = (res + T[0][i] * F1[i]) % mod;
	
	return res;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		cout << solve(n) << endl;
	}
}


	
	
