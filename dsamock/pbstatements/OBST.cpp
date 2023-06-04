#include <bits/stdc++.h>
using namespace std;

int sum(int freq[], int i, int j);

int optCost(int p[], int q[], int i, int j)
{
	// Base cases
	if (j < i) // no elements in this subarray
		return 0;
	if (j == i) // one element in this subarray
		return p[i];
	
	// Get sum of freq[i], freq[i+1], ... freq[j]
	int fsum = sum(p, i, j);
    fsum += sum(q, i-1, j); 
	
	// Initialize minimum value
	int min = INT_MAX;
	
	// One by one consider all elements
	// as root and recursively find cost
	// of the BST, compare the cost with
	// min and update min if needed
	for (int r = i; r <= j; ++r)
	{
		int cost = optCost(p,q, i, r - 1) +
				optCost(p, q, r + 1, j);
		if (cost < min)
			min = cost;
	}
	
	// Return minimum value
	return min + fsum;
}

int optimalSearchTree(int keys[],
					int p[], int q[], int n)
{
	return optCost(p, q, 1, n);
}

int sum(int freq[], int i, int j)
{
	int s = 0;
	for (int k = i; k <= j; k++)
	s += freq[k];
	return s;
}

// Driver Code
int main()
{
	int keys[] = {0,10, 12, 20, 34, 45};
	int p[] = {0, 2, 4, 5, 6, 3};
    int q[] = {3,2,6,5,4,1};
	int n = sizeof(keys) / sizeof(keys[0])-1;
    cout<<n<<endl;
	cout << "Cost of Optimal BST is "
		<< optimalSearchTree(keys, p, q, n);
	return 0;
}
