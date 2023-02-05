#include <bits/stdc++.h>

// #define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define lld long double
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
using namespace std;

const double PI = 2*acos(0.0);

class TrieNode {
public:
    static int nodeCount;
    int currNode;
    map<char,TrieNode*> children;

    TrieNode() {
        this->currNode = TrieNode::nodeCount;
        children['A'] = children['C'] = children['G'] = children['T'] = NULL;
        TrieNode::nodeCount++;
    }
};

int TrieNode::nodeCount = 0;

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode;
    }

    void insert(string &s) {
        TrieNode* r = root;
        for(char ch : s) {
            if(r->children[ch] == NULL) {
                r->children[ch] = new TrieNode();
                printTrieNode(ch, r, r->children[ch]);
            }
            r = r->children[ch];
        }
    }

    void printTrieNode(char ch, TrieNode* before, TrieNode* after) {
        cout<< before->currNode << "->" << after->currNode << ":" << ch << endl;
    }
};

void solve()
{
    Trie* t = new Trie();
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++) {
        cin>>s;
        t->insert(s);
    }
}

int main()
{
	// boost;
	
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif // ONLINE_JUDGE

	int t=1;
	//cin>>t;
	int t1=t;
	while(t--)
	{
	    //cout<<"Case #"<<t1-t<<": ";
		solve();
		// cout<<endl;
	}
	return 0;
}