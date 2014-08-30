// Author: Benwei Gong
// Date: 2014.7.13
/* The program is for Bubble_sort.In the first loop find the min and set it in the front,in the second one, find the 2ed-min....
eg: Input->A[]={5,2,4,6,1,3,7,2}  output->A[] = {1,2,2,3,4,5,6,7}
*/
//

#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int key = a;
	a = b;
	b = key;
}
void Bubble_sort(int A[], int n)
{
	for(int i=0; i<n; ++i)
	{
		for(int j=n-1; j>i; --j)
		{
			if(A[j]<A[j-1])
				swap(A[j], A[j-1]);
		}
	}
}

void Bubble_sort1(int A[], int n)
{
	for(int i=0; i<n; ++i)
	{
		bool flag = false;
		for(int j=n-1; j>i; --j)
		{
			if(A[j]<A[j-1])	{
				swap(A[j], A[j-1]);
				flag = true;
			}
		}
		if(!flag)
			return;
	}
}


int main()
{
	int Array[] = {5,2,4,6,1,3,7,9,2};
	Bubble_sort1(Array, 9);
	for(int i=0; i<9; ++i)
		cout<<Array[i]<<" ";
	cout<<endl;
	return 0;
}
