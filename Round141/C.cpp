#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 5e5 + 5;
int n, m, a[MAX_N], b[MAX_N];

bool check(int wins) {
  int sum = 0;
  for(int i=0; i<wins; ++i) sum += b[i];

  return m >= sum;
}

void solve()
{
  cin >> n >> m;

  for(int i=0; i<n; ++i) {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(b, b+n);

  int lo = 0, hi = n+1;
  while((hi-lo) > 1) {
    int mid = (lo + hi) / 2;

    if(check(mid)) lo = mid;
    else hi = mid;
  }

  int sum = 0;
  for(int i=0; i<lo; ++i) sum += b[i];

  if(lo == 0) 
    cout << n+1 << '\n';
  else if(lo == n) 
    cout << 1 << '\n';
  else
    cout << n-lo + (sum-b[lo-1]+a[lo] > m) << '\n';
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