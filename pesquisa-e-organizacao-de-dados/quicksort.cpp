#include <iostream>
#include <vector>

using namespace std;

int partition(int *v, int left, int right)
{
	int x = v[(left+right)/2];
	int i = left-1;

	for( int j = left; j <= right-1; j++ )
	{
		if ( v[j] <= x )
		{
			i = i+1;

			v[i] = v[j];
		}

	}
	v[i+1] = v[right];
	return i+1;
}
void quick_sort( int *v, int left, int right )
{
	int q;
	if ( left < right )
	{
		q = partition( v, left, right );

		quick_sort( v, left, q-1 );
	        quick_sort( v, q+1, right );	
			
	
	}
}

void print(int *v, int size)
{
	cout<<"Elementos da lista"<<endl;
	for( int i = 0; i< size; i++)
	{
		cout<<v[i]<<endl;
	}
}

void insert(int *v, int size_input)
{
	for( int  i = 0; i < size_input; i++)
	{
		cout<< "Insira o elemento " << "("<<i+1<<"): ";
		cin>>v[i];
	}
}

int main(void)
{
	int v[10];
	int size;

	cin>>size;
	insert(v,size);
	print(v,size);
	quick_sort(v,0,size);
	print(v,size);
	return 0;
}
