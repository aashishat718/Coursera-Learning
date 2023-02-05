#include <bits/stdc++.h>

// #define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define lld long double
#define f(i,a,b) for(int i=a;i<b;i++)
#define all(v) v.begin(), v.end()
#define mod 1000000007
using namespace std;

const double PI = 2*acos(0.0);

// I have done without using it (by directly moving pointers in bwMatching count occurences)
vector<int> findLastToFirst(string &bwt, string &f)
{
    int n = bwt.size();

    map<char, vector<int>> mpBwt, mpF;
    for(int i=0;i<n;i++) {
        mpBwt[bwt[i]].push_back(i);
        mpF[f[i]].push_back(i);
    }

    vector<int> lastToFirst(n);
    int counter = 0;
    int currInd = 0;
    char ch = bwt[currInd];
    while(counter != n) {
        int order = lower_bound(all(mpBwt[ch]), currInd) - mpBwt[ch].begin();

        lastToFirst[currInd] = mpF[ch][order];

        currInd = mpF[ch][order];
        ch = bwt[currInd];
        counter++;
    }

    return lastToFirst;
}

int countOccurences(string &bwt, string &f, map<char, vector<int>> &mpBwt, map<char, vector<int>> &mpF, string &pattern) 
{
    int n = pattern.size();
    vector<int> currInd = mpF[pattern[n-1]];
    for(int i=n-2;i>=0;i--) {
        vector<int> temp;
        for(int ind : currInd) {
            if(bwt[ind] == pattern[i]) {
                int order = lower_bound(all(mpBwt[pattern[i]]), ind) - mpBwt[pattern[i]].begin();
                temp.push_back(mpF[pattern[i]][order]);
            }
        }
        currInd = temp;
    }
    return currInd.size();
}

void solve()
{
    string bwt, f, pattern;
    cin>>bwt;

    int n = bwt.size();
    f = bwt;
    sort(f.begin(), f.end());

    // vector<int> lastToFirst = findLastToFirst(bwt, f); // I haven't used this !!!

    map<char, vector<int>> mpBwt, mpF;
    for(int i=0;i<n;i++) {
        mpBwt[bwt[i]].push_back(i);
        mpF[f[i]].push_back(i);
    }

    int pc;
    cin>>pc;
    while(pc--) {
        cin>>pattern;
        int c = countOccurences(bwt, f, mpBwt, mpF, pattern);
        cout<< c << " ";
    }
}

int main()
{
	// boost;
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE

	int t=1;
	// cin>>t;
	int t1=t;
	while(t--)
	{
	    //cout<<"Case #"<<t1-t<<": ";
		solve();
		cout<<endl;
	}
	return 0;
}