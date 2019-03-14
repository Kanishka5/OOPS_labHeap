#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Heap
{
public:
	int *H;
	int p;
	Heap()
	{
		H=new int[MAX];
		p=0;
	}
	int insert(int x);
	void display();
	~Heap()
	{
		delete [] H;
		p=0;
	}

};

int Heap::insert(int x)
{
	*(H+p)=x;
	int i=p,count=0;
	p+=1;
	while(*(H+((i-1)/2)) < *(H+i))
	{
		int temp=*(H+((i-1)/2));
		*(H+((i-1)/2))=*(H+i);
		*(H+i)=temp;
		count++;
		i=(i-1)/2;
	}
	return count;
}

void Heap::display()
{
	int i=0,q=1;
	while(i<p)
	{
		int j=0;
		while(j<q && i<p)
		{
			cout<<*(H+i)<<" ";
			i++;
			j++;
		}
		q*=2;
		cout<<"\n";

	}
}

int main()
{
	cout<<"Enter the number of elements to be entered : ";
	int n,total=0;
	cin>>n;
	Heap myH;
	for(int i=0;i<n;i++)
	{
		int x;
		cout<<"Input the element : ";
		cin>>x;
		total+=myH.insert(x);
	}
	myH.display();
	return 0;
}
