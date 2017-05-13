#include<bits/stdc++.h>
using namespace std;

struct trie{
	struct trie* c[10];
	bool check;
};

struct trie* getNewNode(){
	struct trie* n = (struct trie*)malloc(sizeof(struct trie));
	for(int i=0 ; i<10 ; i++)
	{
		n->c[i] = NULL;
	}
	n->check = false;
	return n;
}

bool cnstr(struct trie* node,string s)
{
	struct trie* temp = node;
	int l = s.length();
	for(int i=0 ; i<l ; i++)
	{
		if(temp->c[s[i]-'0'] == NULL)
		{
			temp->c[s[i]-'0'] = getNewNode();
		}
		temp = temp->c[s[i]-'0'];
		if(temp->check)
			return true;
	}
	if(temp->check)
		return true;
	temp->check = true;
	for(int i=0;i<10;i++)
	{
		if(temp->c[i] != NULL)
		{
			return true;
		}
	}
	return false;
}
/*
bool check(struct trie* node,string s)
{
	struct trie* temp = node;
	int l = s.length();
	for(int i=0 ; i<l ; i++)
	{
		if(temp->c[s[i]-'a'] != NULL)
		{
			temp = temp->c[s[i]-'a'];
		}
		else
		{
			return false;
		}
	}
	return true;
}*/
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,f=1;
		cin >> n ;
		string s[n];
		struct trie* root = getNewNode();
		for(int i=0;i<n;i++)
		{
			cin >> s[i];
		}
		for(int i=0;i<n;i++)
		{
			if(cnstr(root,s[i]))
			{
				cout << "NO" << endl;
				f=0;
				break;
			}
		}
		if(f)
			cout << "YES" << endl;
	}
	

}
