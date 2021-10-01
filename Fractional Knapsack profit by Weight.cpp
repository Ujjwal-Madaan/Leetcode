// fractional Knapsack Problem
#include <bits/stdc++.h>
using namespace std;

struct Item {
	int value, weight;

	// Constructor
	Item(int value, int weight)
	{
	this->value=value;
	this->weight=weight;
	}
};

// Comparison function to sort Item according to val/weight
// ratio
bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.value / (double)a.weight;
	double r2 = (double)b.value / (double)b.weight;
	return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int n)
{
	// sorting Item on basis of ratio
	sort(arr, arr + n, cmp);
	
	cout<<"Profit/Weight ratio"<<endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].value << " " << arr[i].weight << " :" << ((double)arr[i].value / arr[i].weight) << endl;
	}
	

	int curWeight = 0; // Current weight in knapsack
	double finalvalue = 0.0; // Result (value in Knapsack)

	// Looping through all Items
	for (int i = 0; i < n; i++) {
		// If adding Item won't overflow, add it completely
		if (curWeight + arr[i].weight <= W) {
			curWeight += arr[i].weight;
			finalvalue += arr[i].value;
		}

		// If we can't add current Item, add fractional part **************************************************************     IMP
		else {
			int remain = W - curWeight;
			finalvalue += arr[i].value * ((double)remain / (double)arr[i].weight);
			break;
		}
	}

	// Returning final value
	return finalvalue;
}

// Driver code
int main()
{
	cout<<"Enter the weight of the bag"<<endl;
	int W; // Weight of knapsack
	cin>>W;
	// Profit, weight
	cout<<"\nEnter the profit and weight in the code"<<endl;
	Item arr[] = { { 18,5 }, { 25,3 }, { 12,4 },{4,4},{8,3} };

	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << "Maximum profit = "<< fractionalKnapsack(W, arr, n);
	return 0;
}

