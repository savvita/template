#include<iostream>
#include<ctime>
#include"Class.h"
#include"Array.h"

int main()
{
	//Numbers<int, double> nums2(10, 5.2);
	//std::cout << nums2.add() << "\n";
	//std::cout << nums2.subtract() << "\n";
	//nums2.save("C:\\Users\\student\\Desktop\\11.txt");
	//
	//Numbers<int, double> nums3;
	//nums3.load("C:\\Users\\student\\Desktop\\11.txt");

	//Numbers<char, char> nums4('d', 'f');
	//nums4.save("C:\\Users\\student\\Desktop\\11.txt");
	//

	//Numbers<char, char> nums5;
	//nums5.load("C:\\Users\\student\\Desktop\\11.txt");
	//std::cout << nums5.getValue_1() << "\t" << nums5.getValue_2() << "\n";

	srand(time(0));
	int size = 10;
	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 5;
	}

	Array<int> array(arr);
	//array.show();

	//std::cout << "Enter an element: ";
	//int el;
	//std::cin >> el;

	//int index = array.find(el);
	//if (index != -1)
	//{
	//	std::cout << "Index = " << index << "\n";
	//}
	//else
	//{
	//	std::cout << "Not found\n";
	//}

	//std::cout << "===========\n";

	//array.save("C:\\Users\\student\\Desktop\\11.txt");


	//Array<int> array2;
	//array2.load("C:\\Users\\student\\Desktop\\11.txt");
	//array2.show();

	//std::cout << "===========\n";
	//array2.sort();
	//array2.show();
	//array.show();

	//std::cout << "===========\n";
	//std::cout << "===========\n";

	//array.sort();
	//array.show();

	//array.add(-100);
	//array.show();

	//array.insert(-200, 3);
	//array.show();

	Array<int> array7(arr);
	array.show();
	ElementCount<int>* res = array7.count();
	if (res != nullptr)
	{
		int size = _msize(res) / sizeof(ElementCount<int>);
		for (int i = 0; i < size; i++)
			std::cout << res[i].element << "\t" << res[i].count << "\n";
	}
}