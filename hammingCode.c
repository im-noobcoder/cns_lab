#include<bits/stdc++.h>
using namespace std;

void printCode(int *arr)
{
	printf("Hamming code is : ");
	for(int i=1; i<8; i++)
		printf("%d ", *(arr+i));
	cout<<endl;
}

void correctError(int *arr)
{
	int r1 = (arr[1] + arr[3] + arr[5] + arr[7]) % 2;
	int r2 = (arr[2] + arr[3] + arr[6] + arr[7]) % 2;
	int r4 = (arr[4] + arr[5] + arr[6] + arr[7]) % 2;
	int pos = r4*4 + r2*2 + r1*1;
	cout<<"Error happened at position "<<pos<<endl;
	(arr[pos] == 0)? arr[pos] = 1 : arr[pos] = 0;
	cout<<"After correcting the error\n";
	printCode(arr);
}

void makeError(int *arr)
{
	int pos;
	cout<<"Enter position you want to make error [1-7] : ";
	cin>>pos;
	(arr[pos] == 0)? arr[pos] = 1 : arr[pos] = 0;
	cout<<"After making error\n";
	printCode(arr);
}

int main()
{
	int arr[8];
	cout<<"Enter 4 data bits : ";
	cin>>arr[3]>>arr[5]>>arr[6]>>arr[7];
	((arr[3] + arr[5] + arr[7]) % 2 == 0)? arr[1] = 0 : arr[1] = 1;
	((arr[3] + arr[6] + arr[7]) % 2 == 0)? arr[2] = 0 : arr[2] = 1;
	((arr[5] + arr[6] + arr[7]) % 2 == 0)? arr[4] = 0 : arr[4] = 1;
	printCode(arr);
	int ch = 0;
	printf("\nDo you want to make error?\n1.Yes\t0.No\t");
	cin>>ch;
	if(ch)
	{
		makeError(arr);
		correctError(arr);
	}
	return 0;
}
