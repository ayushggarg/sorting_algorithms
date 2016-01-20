#include<iostream>
using namespace std;

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}
	
int heapify(int arr[], int node, int size)
{
	int largest = 0;
	if (node <= size)
	{	
		if((arr[node] < arr[2*node+1]) && (2*node+1 <= size))
			largest = 2*node+1;
		else
			largest = node;
		if(arr[largest] < arr[2*node+2] && (2*node+2 <= size))
			largest = 2*node+2;
		if(largest != node)
		{
			swap(arr[node], arr[largest]);
			heapify(arr, largest, size);
		}
	}
}

int max_heap(int arr[], int size)
{
	for(int i = (size/2)-1; i>=0; i--)
	{	
		heapify(arr, i, size);
	}
}

int heapsort(int arr[], int size)
{
	int i;
	max_heap(arr, size);

	/*for(i=0; i<=size; i++)
		cout<<arr[i];
	cout<<endl;*/

	for(i=size; i>0; i--)
	{	
		//cout<<arr[0];
		swap(arr[0], arr[i]);
		//cout<<arr[0];
		size--;
		heapify(arr, 0, size);
	}
}

int main()
{
	int arr[10], size, i;
	cin >> size;

	for(i=0; i<size; i++)
		cin>>arr[i];

	heapsort(arr, size-1);
	
	for(i=0; i<size; i++)
		cout<<arr[i]<<endl;
}
