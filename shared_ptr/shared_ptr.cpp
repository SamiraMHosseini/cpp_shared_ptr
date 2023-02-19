#include <memory>
#include <iostream>

class A
{

public:
	A(const char* const name_)
	{

		/*
		Using std::shared_ptr for char[] and int[] Arrays, and Custom Deleters to Manage Dynamic Memory
		
		*/
		size_t len = std::strlen(name_) + 1;

		//Definition

		//ptr_name 
		this->ptr_name =
			std::shared_ptr<char[]>(new char[len], [](char* p)-> void {delete[] p; });
		strcpy_s(this->ptr_name.get(), len, name_);
		//ptr_buffer
		this->ptr_buffer =
			std::shared_ptr<int[]>(new int[SIZE] {1, 2, 3, 4, 5}, std::default_delete<int[]>());

	}
	void Print()
	{
		std::cout << "Print name " << std::endl;

		std::cout << this->ptr_name << std::endl;

		std::cout << "Print buffer " << std::endl;
		for (int i = 0; i < SIZE; ++i)
		{
			std::cout << this->ptr_buffer[i] << std::endl;
		}
	}

	//Data
public:
	const static size_t SIZE = 5;
private:

	//Declaration
	std::shared_ptr<char[]> ptr_name;
	std::shared_ptr<int[]> ptr_buffer;


};
void func(A object)
{
	object.Print();
}
int main()
{

	const char* str = "Hello World!";
	A objectA(str);
	func(objectA);
	objectA.Print();


}