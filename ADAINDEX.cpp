#include<bits/stdc++.h>
using namespace std;

struct trie{
	struct trie* c[26];
	int cnt;
};

struct trie* getNewNode(){
	struct trie* n = (struct trie*)malloc(sizeof(struct trie));
	for(int i=0 ; i<26 ; i++)
	{
		n->c[i] = NULL;		
	}
	n->cnt = 0;
	return n;
}

void cnstr(struct trie* node,string s)
{
	struct trie* temp = node;
	int l = s.length();
	for(int i=0 ; i<l ; i++)
	{
		if(temp->c[s[i]-'a'] == NULL)
		{
			temp->c[s[i]-'a'] = getNewNode();
		}
		temp = temp->c[s[i]-'a'];
		temp->cnt = temp->cnt + 1;
	}
}

int check(struct trie* node,string s)
{
	struct trie* temp = node;
	int l = s.length();
	int ans=0;
	for(int i=0 ; i<l ; i++)
	{
		if(temp->c[s[i]-'a'] != NULL)
		{
			temp = temp->c[s[i]-'a'];
		}
		else
		{
			return 0;
		}
	}
	return temp->cnt;
}
int main()
{
	int n,q;
	cin >> n >> q;
	string s;
	struct trie* root = getNewNode();
	for(int i=0 ; i<n ; i++)
	{
		cin >> s;
		cnstr(root,s);
	}
	while(q--)
	{
		cin >> s;
		int ans = check(root,s);
		cout << ans << endl;
	}
}
