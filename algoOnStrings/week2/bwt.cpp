#include <bits/stdc++.h>

// #define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define lld long double
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
using namespace std;

const double PI = 2*acos(0.0);

void solve()
{
    string s;
    cin>>s;

    vector<string> l;
    for(int i=0;i<s.size();i++) {
        string st = s.substr(i+1) + s.substr(0,i+1);
        l.push_back(st); 
    }
    sort(l.begin(), l.end());

    string bwt = "";
    for(string st : l) {
        bwt.push_back(st.back());
    }

    cout<< bwt << endl;
}

int main()
{
	// boost;
	
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif // ONLINE_JUDGE

	int t=1;
	// cin>>t;
	int t1=t;
	while(t--)
	{
	    //cout<<"Case #"<<t1-t<<": ";
		solve();
		//cout<<endl;
	}
	return 0;
}