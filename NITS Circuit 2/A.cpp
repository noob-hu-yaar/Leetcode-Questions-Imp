#include<bits/stdc++.h>
#include<iostream>
#define el "\n"
#define ll long long int
#define pb push_back
#define u_m unordered_map
#define u_s unordered_set
#define p_q priority_queue
using namespace std;

// ================ MAIN FUNCTION ===============
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		string a,b; cin>>a>>b;
		int hb[26]={0};
		for (int i=0; i<b.length(); i++) {
			hb[b[i]-'a'] = 1;
		}
		int flag=1;
		for (int i=0; i<a.length(); i++) {
			if (hb[a[i]-'a'] == 0) {
				flag = 0; break;
			}
		}
		cout << flag << el;
	}
}