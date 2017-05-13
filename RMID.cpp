#include<iostream>
#include<vector>
#include<map>
using namespace std;

void min_heapify(int i , vector<int>& v , int n)
{
	int l_child = 2*i +1;
	int r_child = 2*i +2;
	int small = i;
	if(l_child<n && v[small] > v[l_child])
		small = l_child;
	if(r_child<n && v[small] > v[r_child])
		small = r_child;
	if(small != i)
	{
		int t = v[small];
		v[small] = v[i];
		v[i] = t;
		min_heapify(small , v , n);
	}
}
int extract_min(vector<int>& v,int* n)
{
	int t = ceil(*n / 2) -1;
	int ans = v[t];
	v[t] = v[(*n)-1];
	(*n)--;
	min_heapify(t,v,*n);
	v.erase(--v.end());
	return t;
}/*
void add(int m,vector<int>& v,int* n)
{
	v.push_back(m);
	(*n)++;
	min_heapify(((*n)-2)/2,v,*n);
}*/
int main()
{
	vector<int> v;
	int n,a;
	cin >> n;
	for(int i=0 ; i<n ;i++)
	{
		cin >> a;
		v.push_back(a);
	}
	for(int i=n/2-1 ; i>=0 ; i--)
	{
		min_heapify(i,v,n);
	}
	int min;
	min = extract_min(v,&n);
	cout << min << endl;
	min = extract_min(v,&n);
	cout << min << endl;
	min = extract_min(v,&n);
	cout << min << endl;
	/*int m;
	cin >> m;
	add(m,v,&n);
	for(int i=0 ; i<n ; i++)
		cout << v[i] << " ";
	*/
	return 0;
}
