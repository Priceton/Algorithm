// Author: Benwei Gong
// Date: 2014.7.13
/* The program is used for practise selection_sort.
   During each loop, choose the smallest one and exchange it to the front.
eg: input->A[]={5,2,4,6,1,3,7,2} output->A[]={1,2,2,3,4,5,6,7}

*/
//

#include<iostream>
using namespace std;

void selection_sort(int A[], int n)
{
	for(int i=0; i<n; ++i)
	{
		int min = i;
		for(int j=i+1; j<n; ++j)
		{
			if(A[min] > A[j])
			{
				int key = A[j];
				A[j] = A[min];
				A[min] = key;
			}
		}
	}
	for(int i=0; i<n; ++i)
		cout<<A[i]<<" ";
	cout<<endl;
}

int main()
{
	int Array[] = {5,2,4,6,1,3,7,2};
	selection_sort(Array, 8);
	for(int i=0; i<8; ++i)
		cout<<Array[i]<<" ";
	cout<<endl;
	return 0;
}

