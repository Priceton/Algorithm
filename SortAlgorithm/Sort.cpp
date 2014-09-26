//
//

#include<iostream>
#include<algorithm>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

//******** Bubble Sort **********/
//*** 交换相邻的两元素 ******//
void Buble(int A[], int n)
{
	for(int i=0; i<n-1; ++i){
		for(int j=n-1; j>i; --j){
			if(A[j] < A[j-1])
				swap(A[j], A[j-1]);
		}
	}
}

void Bubble2(int A[], int n)
{
	bool flag;
	for(int i=0; i<n-1; ++i){
		flag = false;
		for(int j=n-1; j>i; --j){
			if(A[j] < A[j-1]){
				swap(A[j], A[j-1]);
				flag = true;
			}
		}
		if(!flag)
			return;
	}
}


//******** Quick Sort ******************//
//***********************************//
int partition(int *A, int low, int high){
	if(A == NULL) return -1;
	const int pivot = A[low];
	while(low < high){
		while(low < high && A[high] > pivot) --high;
		A[low] = A[high];
		while(low < high && A[low] < pivot) ++low;
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}

void Quick_Sort(int *A, int low, int high){
	if(A == NULL) return;
	if(low < high){
		int mid = partition(A, low, high);
		Quick_Sort(A, low, mid-1);
		Quick_Sort(A, mid+1, high);
	}
}

void QuickSort(int *A, int low, int high){
	if(A == NULL) return;
	stack<int> stk;
	if(low<high){
		stk.push(low);
		stk.push(high);
		while(!stk.empty()){
			int h = stk.top();
			stk.pop();
			int l = stk.top();
			stk.pop();
			int m = Partition(A, l, h);
			if(l<m){
				stk.push(l);
				stk.push(m-1);
			}
			if(m<h){
				stk.push(m+1);
				stk.push(e);
			}
		}
	}
}


//Get the kth Smallest num in A.
int Get_kth_small(int *A, int start, int end, int k){
	if(A == NULL || start + k < end) return -1;
	int pos = partition(A, start, end);
	int num = pos - start +1;
	if(num < k)
		Get_kth_small(A, pos+1, end, k-num);
	else if(num > k)
		Get_kth_small(A, start, pos-1, k);
	else
		return A[pos];
}


int Partition2(int A[], int p, int q)
{
	int x = A[q];
	int i = p-1;
	for(int j=p; j<q; ++j){
		if(A[j] <= x){
			++i;
			swap(A[i], A[j]);
		}
	}
	swap(A[i+1], A[q]);
	return i+1;
}

//******* Merge_Sort *****************//
//*******************************//
void merge(int *A, int *tmp, int start, int mid, int end){
	for(int i=start, i<=end; ++i)
		tmp[i] = A[i];
	int i=start, j=mid+1, k=start;
	while(i<=mid && j<=end){
		if(tmp[i]<tmp[j]) A[k++] = tmp[i++];
		else A[k++] = tmp[j++];
	}
	while(i<=mid)
		A[k++] = tmp[i++];
	while(j<=end)
		A[k++] = tmp[j++];
}

void Merge_Sort(int *A, int *tmp, int start, int end){
	if(A == NULL || tmp == NULL) return;
	if(start < end){
		int mid = start+(end-start)/2;
		Merge_Sort(A, tmp, start, mid);
		Merge_Sort(A, tmp, mid+1, end);
		merge(A, tmp, start, mid, end);
	}
}

//***** Merge Sort ********************//
//************************************//
void merge(int A[], int p, int m, int q)
{
	int n1 = m-p;
	int nw = q-m;
	int *L = new int[n1+1];
	for(int i=0; i<n1+1; ++i)
		L[i] = A[p+i];
	int *R = new int[n2+1];
	for(int i=0; i<n2+1; ++i)
		R[i] = A[m+i];
	
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

void MergeSort(int A[], int p, int q)
{
	if(p<q){
		int m = (p+q)/2;
		Mergesort(A, p, m);
		MergeSort(A, m+1, q);
		merge(A, p, m, q);
	}
}

//*********** Insert_Sort **************//
//********8**************************//
void Insert_Sort(int *A, int n){
	for(int i=1; i<n; ++i){
		int tmpVal = A[i];
		for(int j=i-1; j>=0 && A[j]>tmpVal; --j)
			A[j+1] = A[j];
		A[j+1] = tmpVal;
	}
}

//******* Shell_Sort ********************//
//***********//
void Shell_Sort(int *A, int n){
	int step = n;
	while(step > 1){
		step = step/3 +1;
		for(int i=step; i<n; ++i){
			int tmpVal = A[step];
			for(int j=i-step; j>=0  && A[j]>tmpVal; j-=step)
				A[j+step] = A[j];
			A[j+step] = tmpVal;
		}
	}
}

//********** Select_Sort *****************//
//*********************************//
void Select_Sort(int *A, int n){
	if(A == NULL) return;
	for(int i=0; i<n-1; ++i){
		int min_idx = i;
		for(int j=i+1, j<n; ++j){
			if(A[j] < min_idx)
				min_idx = j;
		}
		if(min_idx != i)
			swap(A[i], A[min_idx]);
	}
}



