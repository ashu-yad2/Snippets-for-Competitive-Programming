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


struct SuffixArray {
    int n, csz;
    vector<vector<int>> classes;
    vector<int> cnt, order, oldc, newc, left,c,lcp;
    string str;

    SuffixArray(string s, bool cyclic) :
        n(s.size() + !cyclic), csz(max(n, 256)), cnt(csz),
        order(n), oldc(n), newc(n), left(n), c(n), lcp(n), str(s) {
            if (!cyclic) str += '\0';
        }

    vector<int> Build() {
        for (int i = 0; i < n; ++i) {
            oldc[i] = newc[i] = str[i];
            order[i] = left[i] = i;
        }

        for (int step = 1; step <= 2 * n; step *= 2) {
            // Counting sort (can be replaced by sort with left)
            // although not trivial
            fill(cnt.begin(), cnt.end(), 0);
            for (int i = 0; i < n; ++i) ++cnt[oldc[left[i]]];
            for (int i = 1; i < csz; ++i) cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; --i)
                order[--cnt[oldc[left[i]]]] = left[i];

            newc[order[0]] = 0;

            for (int i = 1; i < n; ++i) {
                int now1 = order[i], last1 = order[i - 1],
                now2 = (now1 + step / 2) % n,
                last2 = (last1 + step / 2) % n;

                newc[now1] = newc[last1] + (oldc[now1] != oldc[last1]
                        or oldc[now2] != oldc[last2]);
            }

            classes.push_back(newc);
            swap(oldc, newc);

            for (int i = 0; i < n; ++i) {
                left[i] = (order[i] + n - step) % n;
            }
        }

        return order;
    }

    int Compare(int i, int j, int len) {
        for (int step = 0; len; ++step, len /= 2) {
            if (len % 2 == 0) continue;

            int ret = classes[step][i] - classes[step][j];
            if (ret != 0) return ret < 0 ? -1 : 1;

            i = (i + (1 << step)) % n;
            j = (j + (1 << step)) % n;
        }
        return 0;
    }

    int GetLCP(int i, int j) {
        if (i == j) return str.back() == '\0' ? n - i - 1 : n;
        int ans = 0;
        for (int step = classes.size() - 1; step >= 0; --step) {
            if (classes[step][i] == classes[step][j]) {
                i = (i + (1 << step)) % n;
                j = (j + (1 << step)) % n;
                ans += (1 << step);
            }
        }
        return min(ans, n); // if cyclic
    }
    
    vector<int> lcp_array() {
				for(int i = 0; i < n; i++) {
					c[order[i]] = i;
				}
				int k = 0;
				for(int i = 0; i < n - 1; i++) {
					int pi = c[i];
					int j = order[pi - 1];
		
					while(str[i + k] == str[j + k]) k++;
					lcp[pi] = k;
					k = max(k - 1, 0);
				}
				
				return lcp;
			}
			
};



void solve() {
	string s;
	cin >> s;
	SuffixArray a(s, false);
	vi ans = a.Build();
	vi lcp_ = a.lcp_array();
	
	for(auto x: ans) {
		cout << x << " ";
	}
	
	cout << endl;
	
	for(int i = 1; i < lcp_.size(); i++) {
		cout << lcp_[i] << " ";
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t = 1;
	//cin >> t;
	while(t--) {
		solve();
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
