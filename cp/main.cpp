#include <bits/stdc++.h>
using namespace std;

#define int ll

#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)((v).size())
#define fs first
#define sd second

typedef long long ll;

typedef pair < int, int > pi;
typedef pair < pi, int > ppi;

typedef vector < int > vi;
typedef vector < vector < int > > vvi;
typedef vector < pi > vpi;
typedef vector < vpi > vvpi;
typedef vector < ppi > vppi;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}

void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx,
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}

#ifdef LOCAL
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

double get_time() {
	return 1.0 * clock() / CLOCKS_PER_SEC;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vvi adj(n);
	vi in(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		in[v]++;
	}
	vi active, toposort;
	for(int i = 0; i < n; i++)
		if(in[i] == 0)
			active.pb(i);
	while(!active.empty()) {
		int u = active.back();
		active.pop_back();
		toposort.pb(u);
		for(int v : adj[u]) {
			--in[v];
			if(in[v] == 0)
				active.pb(v);
		}
	}

	for(int i = 0; i < n; i++) {
		for(int v : adj[i])
			in[v]++;
	}
	// cout << sz(toposort) << '\n';
	// for(int u : toposort)
	// 	cout << u + 1 << ' ';
	// cout << '\n';
	assert(sz(toposort) == n);
	vi del(n);
	int k = 0;
	for(int i = 0; i < n; i++) {
		int u = toposort[i];
		// debug(u, del[u], in[u]);
		if(del[u] || in[u] == 0)
			continue;
		for(int v : adj[u]) {
			// debug(u, v, in[v], del[v]);
			if(del[v])
				continue;
			del[v] = true;
			for(int w : adj[v])
				in[w]--;
			k++;
		}
	}
	assert(k <= 4*n/7);
	cout << k << '\n';
	for(int i = 0; i < n; i++) {
		if(del[i])
			cout << i + 1 << ' ';
	}
	cout << '\n';
}

int32_t main() {
	fast();
	int t;
	cin >> t;
	while(t--)
		solve();
}
