#include <bits/stdc++.h>

// #define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define lld long double
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
using namespace std;

const double PI = 2*acos(0.0);

/*
    This is brute force method of creating suffix tree by compressing suffix trie.
*/

class TrieNode {
public:
    int startInd;
    int len;
    vector<TrieNode*> children;

    TrieNode(int startInd) {
        this->startInd = startInd;
        this->len = 1;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode(-1);
    }

    void insert(string &s, int start) {
        TrieNode* r = root;
        for(int i=start;i<s.size();i++) {
            bool found = false;
            for(TrieNode* child : r->children) {
                if(s[i] == s[child->startInd]) {
                    found = true;
                    r = child;
                    break;
                }
            }

            if(!found) {
                TrieNode* child = new TrieNode(i);
                r->children.push_back(child);
                r = child;
            }
        }
    }

    void compressTrie() {
        compressTrieHelper(root);
    }

    void compressTrieHelper(TrieNode* node) {
        if(node->children.size() == 0)
            return;
        
        for(TrieNode* child : node->children) {
            compressTrieHelper(child);
        }

        if(node->children.size() == 1) {
            node->len += (node->children[0])->len;
            node->children = (node->children[0])->children;
        }
    }

    void printTrie(string &s) {
        printTrieHelper(s, root);
    }

    void printTrieHelper(string &s, TrieNode* node) {
        for(TrieNode* child : node->children) {
            printTrieHelper(s, child);
        }

        if(node->startInd != -1)
            cout<< s.substr(node->startInd, node->len) << endl;
    }
};

void solve()
{
    Trie* t = new Trie();
    string text;
    cin>>text;

    for(int i=text.size()-1;i>=0;i--) {
        t->insert(text, i);
    }

    t->compressTrie();
    t->printTrie(text);
}

int main()
{
	// boost;
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE

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