#include<stdio.h>
#include<stdlib.h>

void heapify(int* a, int n, int i){
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if(l < n && a[l] > a[largest])
		largest = l;

	if(r < n && a[r] > a[largest])
		largest = r;

	if(largest != i) {
		int temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		heapify(a, n, largest);
	}

}

void TopK(int* a, int k, int n){
	// implement your sort algorithm here
	//1.build heap
	//2.Max Heap
	//3.reverse the order of the array
	
	for (int i = n / 2 - 1; i >= 0; i--){
		heapify(a, n, i);
	}

	for (int i = n - 1; i > 0; i--){
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapify(a, i, 0);
	}
}


void TestTopK(int seed,int k,int n)
{
	int* a = (int*)malloc(n*(sizeof(int)));
	srand(seed);
        int i = 0;
	int max = 0;
	for (i = 0; i < n; i++){
	  a[i]=rand()%(n*100); 
	  if (a[i] > max) max =a[i];
	}

	TopK(a, k, n);
	for (i = n - 1; i > n - k - 1; i--)
	{
		printf("%d\n", a[i]);
	}
	free(a);
	printf("finished\n");
}

int main(int argc, char** argv)
{
	printf("test TopK\n");
	int seed = atoi(argv[1]);
	int k 	= atoi(argv[2]);
	int num = atoi(argv[3]);
	TestTopK(seed,k,num);
	return 0;
}
