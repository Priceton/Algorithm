// Most of the code from my friend sunway.
// Date: 2014/9/3. 
//

#include<iostream>
#include<string>
using namespace std;

const int N = 210;
char str1[N], str2[N];
int num1[N], num2[N];	//number input
int num3[N+1], num4[N*2];	//store the result

//Default num1, num2 >= 0
void add(int num1[], int num2[], int num3[])
{
	for(int i=0; i<N+1; ++i)
		num3[i] = 0;

	for(int i=0; i<N; ++i){
		int num3[i] = num1[i] + num2[i] + num3[i]; //add num3[i] itself.
		if(num3[i] >= 10){
			num3[i] -= 10;
			num3[i+1]++;
		}
	}
}

//Default num1 >= num2 >=0
void subtract(int num1[], int num2[], int num3[])
{
	for(int i=0; i<N+1; ++i)
		num3[i] = 0;

	for(int i=0; i<N; ++i){
		num3[i] = num1[i] - num2[i] + num3[i];
		if(num3[i] < 0){
			num3[i] += 10;
			num3[i+1]--;
		}
	}
}

//Default num1 , num2 >= 0
void multiple(int num1[], int num2[], int num4[])
{
	for(int i=0; i<N*2; ++i)
		num4[i] = 0;
	
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			num4[i+j]= num1[i] * num2[j] + num4[i+j];
			if(num4[i+j] >= 10){
	//			num4[i+j+1] = num4[i+j]/10; 
				num4[i+j+1] += num4[i+j]/10;
				num4[i+j] = num4[i+j]%10;
			}
		}
	}
}

void print(int num[], int K){
	int i,j;
	
	for(i = K; i>=0 && num[i] != 0; --i){}

	if(i == -1)
		cout<<0;
	else{
		for(int j=i; j>=0; --j){
			cout<<num[j];
		}
	}
	cout<<endl;
}


int main()
{
	cin>>str1>>str2;
	memset(num1, 0, sizeof(num1));
	memset(num2, 0, sizeof(num2));
	const int str1_length = strlen(str1);
	const int str2_length = strlen(str2);
	int i, j;
	j=0;
	for(i = str1_len -1; i >= 0; --i)
		num1[j++] = str1[i] - '0';
	j = 0;
	for(i = str2_len -1; i >= 0; --i)
		num2[j++] = str2[i] - '0';

	add(num1, num2, num3);
	print(num3, N);

	subtract(num1, num2, num3);
	print(num3, N);

	multiple(num1, num2, num4);
	print(num4, 2*N);

	return 0;
}
