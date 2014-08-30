// Author: Benwei Gong
// Date: 2014.7.13
/* The Program is for insertion-sort.
   All the numbers in u hand are sorted, so the new one is need to insert into the right place.
   A[i] is the array.
*/ 
//

#include<iostream>
using namespace std;

void InsertSort(int A[], int n)
{
	int i,j;
	int tempVal = 0;
	for(i=1; i<n; ++i)
	{
		int tempVal = A[i];
		for(j=i-1; j>=0 && A[j]>tempVal; --j)
			A[j+1] = A[j];
		A[j+1] = tempVal;
	}
}


int main()
{
	int Array[] = {5,2,4,6,1,3,7,2};
	InsertSort(Array, 8);
	for(int i=0; i<8; ++i)
		cout<<Array[i]<<" ";
	cout<<endl;
	return 0;
}
