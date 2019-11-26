#include <iostream>
#include <ctime>
using namespace std;

int iParent(const int& i) {
	return floor((i - 1) / 2);
}
int iLeftChild(const int& i) {
	return 2 * i + 1;
}
int iRightChild(const int& i) {
	return 2 * i + 2;
}

void siftDown(int a[], const int& start, const int& end) {
	int root = start;
	while (iLeftChild(root) <= end) {
		int child = iLeftChild(root);
		int s = root;
		if (a[s] < a[child])
			s = child;
		if (child + 1 <= end && a[s] < a[child + 1])
			s = child + 1;
		if (s == root)
			return;
		else {
			swap(a[root], a[s]);
			root = s;
		}
	}
}
void heapify(int a[], const int& count) {
	int start = iParent(count - 1);
	while (start >= 0) {
		siftDown(a, start, count - 1);
		start--;
	}
}
void heapSort(int a[], const int& count) {
	heapify(a, count);
	int end = count - 1;
	while (end > 0) {
		swap(a[0], a[end]);
		end--;
		siftDown(a, 0, end);
	}
}

int main() {
	srand(time(0));
	int N = 0 + rand() % 30;
	int* array = new int[N];
	for (int i = 0; i < N; i++) {
		array[i] = rand() % 1000;
	}
	//const int N = 5;
	//int array[N] = { 14, 9, 6, 23, 2 };
	cout << "Not sorted data:\n";
	
	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	cout << "\n\nSorted data:\n";
	heapSort(array, N);
	for (int i = 0; i < N; i++) {
		cout << array[i] << " ";
	}
	cout << "\n";
	return 0;
}