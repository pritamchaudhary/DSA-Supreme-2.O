#include <iostream>
using namespace std;

// void solve(int *arr, int size) {
// 	// cout << "Size of array inside solve func: " << sizeof(arr) << endl;
// 	// cout << "Inside solve -> arr: " << arr << endl;
// 	// cout << "Inside solve -> &arr: " << &arr << endl;
// 	*arr = *arr + 1;
// }
void solve(int* &p) {
	p = p + 1;
}
int main() {

	int a = 5;
	int* p = &a;

	cout << "p: " << p << endl;
	cout << "&p : " << &p << endl;
	cout << "*p: " << *p << endl;
	solve(p);
	cout << "p: " << p << endl;
	cout << "&p : " << &p << endl;
	cout << "*p: " << *p << endl;
	
	

	// int arr[] = {10,20,30};
	// ///cout << "Size of array: " << sizeof(arr) << endl;
	// solve(arr,3);

	// for(int i=0; i<3; i++) {
	// 	cout << arr[i] << " ";
	// }
	
	// // cout << "Inside main -> arr: " << arr << endl;
	// cout << "Inside main -> &arr: " << &arr << endl;

	// int arr[5] = {1,2,3,4,5};

	// //pointer to an array
	// int* ptr1 = arr;
	// //pointer to an array
	// int (*ptr)[5] = &arr;
	// cout << (*ptr)[0];
	

	// // char ch[10] = "Babbar";
	// // char* cptr = &ch;


	return 0;
}