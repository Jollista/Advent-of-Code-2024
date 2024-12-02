#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

int frequency(int i, vector<int> list)
{
	int count = 0;
	for (auto e : list)
	{
		if (e == i)
			count++;
	}
	return count;
}

int getSimilarity(vector<int> left, vector<int> right)
{
	int sum = 0;
	//for each element in left
	for (auto e : left)
	{
		int freq = frequency(e, right);
		sum += e * freq;
		printf("%d * %d\n", e, freq);
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
		//printf("%d ", l);
		left.push_back(l);

		//printf("%d ", r);
		right.push_back(r);
	}

	int distance = getSimilarity(left, right);
	printf("\nSimilarity is %d", distance);

	return 0;
}