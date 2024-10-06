#include<iostream>
#include<stack>

using namespace std;


class advancestack
{
	stack<int>main;
	stack<int>min;
	int count;
public:
	advancestack()
	{
		count = 0;
	}
	void push(int value)
	{
		main.push(value);
		if (min.empty() || value <= min.top())
		{
			min.push(value);
		}
		count++;
	}
	void pop()
	{
		if (main.empty())
		{
			cout << "Stack is already empty";
			exit(1);
		}
		count--;
		if (main.top() == min.top())
		{
			min.pop();
		}
		main.pop();
	}
	int minvalue()
	{
		return min.top();
	}
	int size()
	{
		return count;
	}
};

void ngep(int num[], int result[])
{
	stack<int>s1;

	for (int i = 0;i < 5;i++)
	{
		result[i]= -1;
	}

	for (int i = 4; i >= 0; i--)
	{
		if (!s1.empty() && s1.top() <= num[i])
		{
			s1.pop();
		}
		if (!s1.empty())
		{
			result[i] = s1.top();
		}
		s1.push(num[i]);
	}
}
int main()
{
    string opt = "";
	while (opt != "3")
	{
		cout << "1)ADVANCE STACK" << endl;
		cout << "2)Next Greater Element Problem" << endl;
		cout << "3)Exit" << endl;
		cin >> opt;
		if (opt == "1")
		{ 
			int a;
			advancestack astack;

			cout << "Enter first number: ";
			cin >> a;
			astack.push(a);
			cout << "Enter second number: ";
			cin >> a;
			astack.push(a);
			cout << "Enter third number: ";
			cin >> a;
			astack.push(a);

			cout << "Size = " << astack.size() << endl;
			cout << "Min value = " << astack.minvalue() << endl;
			system("pause");
			system("cls");
		}
		if (opt == "2")
		{
			int a[5];
			int b[5];
			for (int i = 0; i < 5; i++)
			{
				cout << "Enter " << i + 1 << " Value : ";
				cin >> a[i];
			}
			cout << endl;
			for (int i = 0; i < 5; i++)
			{
				cout << a[i]<<" ";
			}
			cout << endl;
			ngep(a, b);
			for (int i = 0;i < 5;i++)
			{
				cout << b[i]<<" ";
			}
			cout << endl;
			system("pause");
			system("cls");
		}
	}
	return 0;
}

