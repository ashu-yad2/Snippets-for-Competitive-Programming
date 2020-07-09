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
typedef double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
 
 
const  int MAXn= 3e5+5;
const  long long INF= 1e18;
const long long mod= 1e9+7;
 
ll st[4 * MAXn];
ll lazy[4 * MAXn];
int n,q;
 
void rangeupdate(int start, int end, ll value, int l, int r, int pos) {
	if(start > end) return;
	
	if(lazy[pos] != 0) {
		st[pos] += (lazy[pos]) * (end - start + 1);
		if( start != end) {  // not  a leaf node
		lazy[2 * pos] += lazy[pos];
		lazy[2 * pos + 1] += lazy[pos];
		}
		lazy[pos] = 0;
	}
	
	if( start > r || end < l ) { // no overlap
		return ;
	} 
	
	if( start >= l && end <= r ) {
		st[pos] += value * (end - start + 1);
		if( start != end) {  // not  a leaf node
		lazy[2 * pos] += value;
		lazy[2 * pos + 1] += value;
		}
		return ;
	}
	
	int mid = (start + end) / 2;
	rangeupdate(start, mid, value, l, r, 2 * pos);
	rangeupdate(mid + 1, end, value, l, r, 2 * pos + 1);
	
	st[pos] = st[2 * pos] + st[2 * pos + 1];
}
 
ll query(int start, int end, int l, int r, int pos) {
	if(start > end ) return 0;
	
	if(lazy[pos] != 0) {
		st[pos] += (lazy[pos])*(end - start + 1);
		if( start != end) {  // not  a leaf node
		lazy[2 * pos] += lazy[pos];
		lazy[2 * pos + 1] += lazy[pos];
		}
		lazy[pos] = 0;
	}
	
	if( start > r || end < l ) { // no overlap
		return 0 ;
	} 
	 
	 if( start >= l && end <= r ) { // complete overlap
		return st[pos];
	}
	int mid = (start + end) / 2;
	 return query(start, mid, l, r, 2 * pos) + query(mid + 1, end, l, r, 2 * pos + 1);
	 
	 
}
	 
	 
 
 
int main(){
	   int t;
	   cin >> t;
	   while(t--) {
       for(int i = 0 ; i < 4 * MAXn; i++){
		   st[i] = lazy[i] = 0;
	   }
       
       cin >> n >> q;
       
       while(q--){
		   int type;
		   cin >> type;
		   if(type == 0) {
			   int l, r; ll value;
			   cin >> l >> r >> value;
			   rangeupdate(1, n, value, l, r, 1);
		   }
		   
		   else {
			   int l, r;
			   cin >> l >> r;
			   cout << query(1, n, l, r, 1) << endl;
		   }
	   }
	   
   }
 }
       
       
