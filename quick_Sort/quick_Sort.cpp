#include <iostream>
#include <vector>
#include <ctime>

int partition(std::vector<int>& arr, int left, int right)
{
	int pivot = arr[left];
	int i = left;
	int j = right + 1;

	while (true)
	{
		while (arr[++i] < pivot)
		{
			if (i == right) break;
		}

		while (arr[--j] > pivot)
		{
			if (j == left) break;
		}

		if (i >= j) break;

		std::swap(arr[i], arr[j]);
	}

	std::swap(arr[left], arr[j]);

	return j;
}

//int partition(std::vector<int>& arr, int left, int right)
//{
//	int pivot = arr[right];
//	int i = left;
//	int j = left-1;
//
//	while (j++ < right)
//	{
//		if (arr[j] < pivot)
//		{
//			std::swap(arr[i], arr[j]);
//			++i;
//		}
//		//++j;
//	}
//
//	std::swap(arr[i], arr[right]);
//
//	return i;
//}

void quick_Sort(std::vector<int>& arr, int l, int r)
{
	if (l < r)
	{
		int _pivot = partition(arr, l, r);

		quick_Sort(arr, l, _pivot - 1);
		quick_Sort(arr, _pivot + 1, r);
	}
}

void print(std::vector<int>& arr)
{

	for (int i = 0; i < arr.size(); ++i) {
		std::cout << arr[i] << " ";
	}

}

int main()
{
	std::vector<int> myvector(10);

	srand(time(NULL));

	for (auto& elem : myvector)
	{
		elem = rand() % 50 - 10;
	}

	print(myvector);

	std::cout << "\nSorted vecor: \n";

	quick_Sort(myvector, 0, myvector.size() - 1);

	print(myvector);

	return 0;
}