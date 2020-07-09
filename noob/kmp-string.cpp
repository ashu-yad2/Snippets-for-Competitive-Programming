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
 
 
const  int mxN = 2e6+500;
const  long long INF= 1e18;
const long long mod= 1e9+7;

int pref[mxN], c;

string kmp(string s) {
	string a = s;
	reverse(a.begin(), a.end());
	a = s + "#" + a;
	c = 0;
	
	for(int i = 1; i < (int)a.size(); i++) {
		
		while(c != 0 && a[c] != a[i]) c = pref[c - 1];
		
		if(a[c] == a[i]) c++;
		pref[i] = c;
	}
	return s.substr(0, c);
}
 
 
int main(){
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int n = s.size();
		int i;
		
		for( i = 0; i < n/2; i++) {
			if(s[i] != s[n - i - 1]) break;
		}
		cout << s.substr(0, i);
		
		string temp = s.substr(i, n - 2*(i));
		string x = kmp(temp);
		reverse(temp.begin(), temp.end());
		string y = kmp(temp);
		
		if(y.size() > x.size())
		 cout << y;
		 else cout << x;
		cout << s.substr(n - i, i + 1);
		cout << endl;
		
		
	}
}
		
		
		
		
		
		
				
