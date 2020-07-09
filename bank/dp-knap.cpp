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


#define n_l '\n'
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; cout << to_string(__VA_ARGS__) << endl
template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c){ return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgm(){;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgm(T...); } 
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cout << endl


int pos[2005][2005];
int cnt[2005][10];
 	
signed main(){
	int n, k_;
	cin >> n >> k_;
	
	vector<string> dig = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
	vector<string> v(n + 1);
	
	rep(i, 1, n + 1) cin >> v[i];
	
	
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 10; j++) {
			bool flag = true;
			int c = 0;
			for(int k = 0; k < 7; k++) {
				if(v[i][k] == '1' && dig[j][k] == '0') { flag = false; break;}
				if(v[i][k] == '0' && dig[j][k] == '1') { c++;}
			}
			cnt[i][j] = (flag ? c : -1);
		}
	}
	pos[n + 1][k_] = 1;
	
	for(int i = n; i >= 1; i--) {
		for(int j = 0; j < 10; j++) {
			if(cnt[i][j] == -1) continue;
			int diff = cnt[i][j];
			for(int k = 0; k <= k_; k++) {
				if(pos[i + 1][k + diff] && k + diff <= k_) {
					pos[i][k] = 1;
				}
			}
		}
	}
	
	if(!pos[1][0]) {
		cout << -1 ;
		return 0;
	}
	int temp = 0;
	string ans = "";
	
	for(int i = 1; i <= n; i++) {
		for(int j = 9; j >= 0; j--) {
			int diff = cnt[i][j];
			if(diff == -1) continue;
			
			if(temp + diff <= k_ && pos[i + 1][temp + diff]) {
				ans += char('0' + j);
				temp += diff;
				break;
			}
		}
	}
	cout << ans;
}
			
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
