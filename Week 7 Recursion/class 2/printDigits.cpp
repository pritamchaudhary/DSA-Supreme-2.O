#include<iostream>
#include<vector>
using namespace std;

void printDigits(int num, vector<int>& ans) {
	//base case
	if(num == 0) {
		return;
	}

	//processing
	int digit = num % 10;

	//Recursive call
	printDigits(num/10,ans);

	//processing
	ans.push_back(digit);
}

int main() {

	int num = 4217;
	vector<int> ans;
	printDigits(num,ans);

	for(int num: ans) {
		cout << num << endl;
    }

}