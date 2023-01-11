#include<bits/stdc++.h>

using namespace std;

map<int,int> mp;
vector<vector<int>> p;
int n, k;

void solve()
{
  mp.clear();
  p.clear();

  cin >> n;
  p.resize(n);

  for(int i=0; i<n; ++i) {
    cin >> k;
    p[i].resize(k);

    for(int j=0; j<k; ++j) {
      cin >> p[i][j];
      mp[p[i][j]]++;
    }
  }

  bool ans = false, flag;
  for(int i=0; i<n; ++i) {
    flag = true;

    for(auto& x : p[i]) {
      if(mp[x] == 1) {
        flag = false;
        break;
      }
    }

    if(flag) {
      ans = true;
      break;
    }
  }

  cout << (ans ? "Yes" : "No") << '\n';
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0);

  int TC;
  cin >> TC;

  while(TC--) {
    solve();
  }
  return 0;
}