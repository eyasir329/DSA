#include <bits/stdc++.h>

using namespace std;

#define int long long int

int linear_search(int arr[],int n,int key){
	for(int i=0;i<n;i++){
		if(arr[i]==key){
			return i;
		}
	}
	return -1;
}

void solve()
{
    int arr[] = {2,6,3,0,9};
    int n = sizeof(arr)/sizeof(int);
    int k = linear_search(arr,n,arr[1]);
    cout<<"at index : "<<k;
}

int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    cout << endl;

    return 0;
}