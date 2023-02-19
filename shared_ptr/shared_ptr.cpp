#include <memory>
#include <iostream>

class A
{

public:
	A(const char* const name_)
	{
		size_t len = std::strlen(name_) + 1;


		//Definition

		//ptr_name 
		this->ptr_name =
			std::shared_ptr<char[]>(new char[len], [](char* p)-> void {delete[] p; });
		strcpy_s(this->ptr_name.get(), len, name_);
		//ptr_buffer
		this->ptr_buffer =
			std::shared_ptr<int[]>(new int[SIZE] {1, 2, 3, 4}, std::default_delete<int[]>());

	}
	void Print()
	{
		std::cout << "Print name " << std::endl;
		std::cout << this->ptr_name << '\n';
		std::cout << "Print buffer " << std::endl;
		for (int i = 0; i < SIZE; ++i)
		{
			std::cout << this->ptr_buffer[i] << '\n';
		}
	}
private:
	//Declaration
	std::shared_ptr<char[]> ptr_name;
	std::shared_ptr<int[]> ptr_buffer;
public:
	const static size_t SIZE = 5;

};
void func(A object)
{
	object.Print();
}
int main()
{

	const char* str = "Hello World!";
	A a(str);
	func(a);
	a.Print();


}