//Author: Benwei Gong
//Date: 2014.7.13
/* This program is used for Practising the Quick_sort.
   A an array A[p...q] is divided into two subArray A1[p...r-1] and A2[r+1...q].
st: A1[i] <= A[r] and A2[i] >= A[r];
   */
//

#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b= temp;
}

int partition(int A[], int p, int q)
{
	int x = A[q];
	int i = p-1;
	for(int j=p; j<q; ++j)
	{
		if(A[j]<x){
			++i;
			swap(A[i],A[j]);
		}
	}
	swap(A[i+1], A[q]);
	return i+1;
}

int partition2(int A[], int p, int q)
{
	int key = A[p];
	while(p < q)
	{
		while(p<q && A[q]>=key) --q;
		swap(A[p], A[q]);
		while(p<q && A[q]<=key) ++p;
		swap(A[p], A[q]);
	}
	return p;
}

void Quick_Sort(int A[], int p, int q)
{
	if(p<q){
		int m = partition(A, p, q);
		Quick_Sort(A, p, m-1);
		Quick_Sort(A, m+1, q);
	}
}

int main()
{
	int A[] = {5,2,4,6,1,3,7,2};
	Quick_Sort(A, 0, 7);
	for(int i=0; i<8; ++i)
		cout<<A[i]<<" ";
	cout<<endl;
	return 0;
}
