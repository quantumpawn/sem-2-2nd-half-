#include <iostream>
using namespace std;

int l = 0;
int heap[100];

void insert(int data)
{
	if (l == 0)
	{
		heap[0] = data;
	}
	else
	{
		heap[l] = data;
		int i = l;
		int p = (i - 1) / 2;
		while (heap[i] >= heap[p])
		{
			int t = heap[i];
			heap[i] = heap[p];
			heap[p] = t;
			i = p;
			p = (i - 1) / 2;
			if (i == p || i == 0)
			{
				break;
			}
		}
	}
	l++;
}
  void max_heapify(int *a, int i, int n)
  {
      int j, temp;
      temp = a[i];
      j = 2*i;
      while (j<=n)
      {
          if (j<n && a[j+1]>a[j])
              j = j + 1;
          if (temp > a[j])
              break;
          else if (temp<=a[j])
          {
              a[j/2] = a[j];
              j =2*j;
          }
      }
      a[j/2] = temp;
  }
  void build_maxheap(int *a,int n)
  {
      int i;
      for(i = n/2; i >= 1; i--)
      {
          max_heapify(a,i,n);
      }
  }

void deleteroot(int *a){
  if (l==0){
    cout << "heap empty" << endl;}
  else{
    for (int j=0;j<=l-2;j++){
      heap[j] = heap[j+1];}
    l = l-1;
    build_maxheap(heap,l);}
}
int main()
{
    insert(4);
    insert(1);
    insert(3);
    insert(2);
    insert(16);
    insert(9);
    insert(10);
    insert(14);
    insert(8);
    insert(7);
    build_maxheap(heap,l);
    for (int i = 0;i<l;i++){
      cout << heap[i] << endl;}
  //-----------------------------------------------------------------//
  //------------------deleting root once-----------------------------//
    deleteroot(heap);
    if (l!=0){
      cout << "new heap:" << endl;}
    for (int i = 0;i<l;i++){
      cout << heap[i] << endl;}
    return 0;
}
