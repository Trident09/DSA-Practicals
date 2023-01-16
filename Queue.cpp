// C++ Program to implement above approach
#include <bits/stdc++.h>
using namespace std;

// Helper class Geeks to implement
// insert() and findFrequency()
class Geeks
{

// Function to insert
// element into the queue
public:
void insert(queue<int> &q, int k)
{

	// adding N integers into the Queue
	q.push(k);
}
// Function to find frequency of an element
// return the frequency of k
int findFrequency(queue<int> &q, int k)
{

	// to count frequency of elements
	int cntFrequency = 0;

	// storing size of queue in a variable
	int h = q.size();

	// running loop until size becomes zero
	while (h)
	{
	h = h - 1;

	// storing and deleting
	// first element from queue
	int x = q.front();
	q.pop();
	// comparing if it's equal to integer K
	// that belongs to M
	if (x == k)
	{

		// increment count
		cntFrequency += 1;
	}
	// add element back to queue because
	// we also want N integers
	q.push(x);
	}
	// return the count
	return cntFrequency;
}
};

// Driver code

int main()
{
queue<int> q;
int N = 8;
int a[N] = {1, 2, 3, 4, 5, 2, 3, 1};
int M = 5;
int b[M] = {1, 3, 2, 9, 10};

// Invoking object of Geeks class
Geeks obj;

for (int i = 0; i < N; i++)
{

	// calling insert()
	// to add elements in queue
	obj.insert(q, a[i]);
}

for (int i = 0; i < M; i++)
{

	// calling findFrequency()
	int f = obj.findFrequency(q, b[i]);
	if (f != 0)
	{

	// variable f
	// will have final frequency
	cout << f << " ";
	}
	else
	{
	cout << ("-1") << " ";
	}
}
}
