#include <algorithm>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int getDistance(vector<int> left, vector<int> right)
{
	//sort lists
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	//while not empty, add pair distance to sum and pop
	int sum = 0;
	while(!left.empty())
	{
		sum += abs(left.back()-right.back());
		left.pop_back();
		right.pop_back();
	}

	return sum;
}

int main()
{
	//read from file
	fstream myfile("input", ios_base::in);

	//initialize lists
	int l, r;
	vector<int> left;
	vector<int> right;

	while (myfile >> l >> r)
	{
		printf("%d ", l);
		left.push_back(l);

		printf("%d ", r);
		right.push_back(r);
	}

	int distance = getDistance(left, right);
	printf("\ndistance is %d", distance);

	return 0;
}