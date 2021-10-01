#include<bits/stdc++.h>
#include<iostream>
#define el "\n"
#define ll long long
#define pb push_back
#define u_m unordered_map
#define u_s unordered_set
#define p_q priority_queue
#define ff first
#define ss second
#define mp make_pair
using namespace std;

// namespace std {
// template <> struct hash<std::pair<int, int>> {
// 	inline size_t operator()(const std::pair<int, int> &v) const {
// 		std::hash<int> int_hasher;
// 		return int_hasher(v.first) ^ int_hasher(v.second);
// 	}
// };
// }
// u_s <pair<int,int> > s;
// u_s <pair<int,int> > vis;

struct pair_hash {
	inline std::size_t operator()(const std::pair<int,int> & v) const {
		return v.first*31+v.second;
	}
};
u_s <pair<int,int>, pair_hash> s;
u_s <pair<int,int>, pair_hash> vis;

// ========= traditional way =========
bool bfs(int C) {

	queue<pair<int,int> > q;
	q.push(mp(1,1));
	vis.insert(mp(1,1));

	while (!q.empty()) {

		pair<int,int> curr = q.front(); q.pop();
		int r = curr.ff, c=curr.ss;

		if (r==2 and c==C){
			return true;
		}
		if (r-1>0 and !s.count(mp(r-1,c)) and !vis.count(mp(r-1,c))) {
			q.push(mp(r-1,c));
			vis.insert(mp(r-1,c));
		}
		if (r+1<=2 and !s.count(mp(r+1,c)) and !vis.count(mp(r+1,c))) {
			q.push(mp(r+1,c));
			vis.insert(mp(r+1,c));
		}
		if (c+1<=C and !s.count(mp(r,c+1)) and !vis.count(mp(r,c+1))) {
			q.push(mp(r,c+1));
			vis.insert(mp(r,c+1));
		}
	}

	return false;
}

// ============== TRICKY WAY =============
bool trick(int C) {
	for (auto i=s.begin(); i!=s.end(); i++) {
		int r = i->ff, c = i->ss;
		if (s.count(mp(r+1,c)) or s.count(mp(r+1,c+1)))
			return false;
		if (s.count(mp(r-1,c)) or s.count(mp(r-1,c+1)))
			return false;
	}
	return true;
}

// ================ MAIN FUNCTION ===============
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		int C,n; cin>>C>>n;
		int r,c;
		s.clear();
		vis.clear();
		for (int i=0; i<n; i++) {
			cin>>r>>c;
			s.insert(mp(r,c));
		}
		cout << trick(C) << el;
	}
}