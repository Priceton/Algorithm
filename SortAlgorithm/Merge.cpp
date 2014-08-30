//Author: Benwei Gong
//Date: 2014.7.13
/* THis program is used for practising Merge_sort.
   divide the Array into many parts, it is easy for each part to sort. then merge each parts into a new one.
eg: input->A[]={5,2,4,6,1,3,7,2} output->A[]={1,2,2,3,4,5,6,7}
*/
//

#include<iostream>
using namespace std;

const int MAX = 10000;

void merge(int A[], int p, int m, int q)
{
	int n1 = m-p;
	int n2 = q-m;
	int *L = new int[n1+1];
	for(int i=0; i<n1; ++i)
		L[i] = A[p+i];
	L[n1] = MAX;
	int *R = new int[n2+1];
	for(int i=0; i<n2; ++i)
		R[i] = A[m+i];
	R[n2] = MAX;
	
	int i=0, j=0;
	for(int k=p; k<q; ++k)
	{
		if(L[i] <= R[j]){
			A[k] = L[i];
			++i;
		}
		else{
			A[k] = R[j];
			++j;
		}
	}
	delete []L;
	delete []R;
}

void Merge_sort(int A[], int p, int q)
{
	if(p<q)
	{
		int m = (p+q)/2;
		Merge_sort(A, p, m);
		Merge_sort(A, m+1, q);
		merge(A, p, m, q);
	}
}


int main()
{
	int Array[] = {5,2,4,6,1,3,7,2};
	Merge_sort(Array,0,9);
	for(int i=0; i<9; ++i)
		cout<<Array[i]<<" ";
	cout<<endl;
	return 0;
}
