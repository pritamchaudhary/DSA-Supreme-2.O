int main() {

	int num = 4217;
	vector<int> ans;
	printDigits(num,ans);

	for(int num: ans) {
		cout << num << endl;
	}