#include <iostream>

using namespace std;

void read_mas(int* mas, int size)
{
	cout << "mas: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i << "] = ";
		cin >> mas[i];
	}
}

void write_mas(int* mas, int size)
{
	cout << "mas: ";
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
}

int find_min(int* mas, int size)
{
	int min = 100000;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] < min)
		{
			min = mas[i];
		}
	}
	return min;
}

int find_min_index(int* mas, int size)
{
	int min = 100000;
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] < min)
		{
			min = mas[i];
			index = i;
		}
	}
	return index;
}

int find_max(int* mas, int size)
{
	int max = -100000;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] > max)
		{
			max = mas[i];
		}
	}
	return max;
}

int find_max_index(int* mas, int size)
{
	int max = -100000;
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (mas[i] > max)
		{
			max = mas[i];
			index = i;
		}
	}
	return index;
}

void swap_min_max(int* mas, int size)
{
	int min_index = find_min_index(mas, size);
	int max_index = find_max_index(mas, size);
	swap(mas[0], mas[min_index]);
	swap(mas[size - 1], mas[max_index]);
}

bool is_even(int number)
{
	bool res = number % 2 == 0;
	return res;
}

void remove_even(int* mas, int size)
{
	int k = 0; //количество уже найденных чётных
	for (int i = 0; i < size; i++)
	{
		mas[i - k] = mas[i];
		if (is_even(mas[i]))
		{
			k++;
		}
	}

	for (int i = size - k; i < size; i++)
	{
		mas[i] = 0;
	}
}

void print_menu()
{
	cout << "1. Ввод массива" << endl;
	cout << "2. Вывод массива" << endl;
	cout << "3. Найти минимум массива" << endl;
	cout << "4. Найти максимум массива" << endl;
	cout << "5. Заменить минимум и максимум с началом и концом массива" << endl;
	cout << "6. Удалить все чётные числа из массива" << endl;
	cout << "0. Выход" << endl;
}

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "Автор: Чепель Егор Максимович" << endl;
	cout << "Программа по манипулированию массивом с помощью функций" << endl;

	int size = 5;
	int* mas = new int[size]{1, 2, 3, 4, 5};


	int t;
	do
	{
		print_menu();
		cin >> t;
		switch (t)
		{
		case 1:
			{
				cout << "Введите размер массива: ";
				cin >> size;

				mas = new int[size];
				read_mas(mas, size);
				break;
			}
		case 2:
			{
				if (size == -1)
				{
					cout << "Перед выводом необходимо ввести массив!" << endl;
					break;
				}
				write_mas(mas, size);
				break;
			}
		case 3:
			{
				if (size == -1)
				{
					cout << "Перед поиском минимума необходимо ввести массив!" << endl;
					break;
				}
				int min = find_min(mas, size);
				cout << "Минимум массива: " << min << endl;
				break;
			}
		case 4:
			{
				if (size == -1)
				{
					cout << "Перед поиском максимума необходимо ввести массив!" << endl;
					break;
				}
				int max = find_max(mas, size);
				cout << "Максимум массива: " << max << endl;
				break;
			}
		case 5:
			{
				if (size == -1)
				{
					cout << "Перед заменой необходимо ввести массив!" << endl;
					break;
				}
				swap_min_max(mas, size);
				cout << "Значения заменены." << endl;
				break;
			}
		case 6:
			{
				if (size == -1)
				{
					cout << "Перед удалением необходимо ввести массив!" << endl;
					break;
				}
				remove_even(mas, size);
				cout << "Чётные числа удалены." << endl;
				break;
			}
		}
	}
	while (t != 0);


	system("pause");

	return 0;
}
