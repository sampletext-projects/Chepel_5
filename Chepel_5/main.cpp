#include <ctime>
#include <iostream>

using namespace std;

void read_mas(int* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i << "] = ";
		cin >> mas[i];
	}
}

void write_mas(int* mas, int size)
{
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
	int min = mas[min_index];
	int max = mas[max_index];
	mas[min_index] = mas[0];
	mas[0] = min;
	mas[max_index] = mas[size - 1];
	mas[size - 1] = max;
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

void fill_random(int* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		mas[i] = rand() % 100;
	}
}

bool is_simple(int number)
{
	bool res = true;
	//можно искать все множители до корня числа, т.к. сам корень уже является делителем
	for (int i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
		{
			res = false;
		}
	}
	return res;
}

int* remove_non_simple(int* mas, int size, int& m_size)
{
	int* dst = new int[size];
	int k = 0; //количество удалённых элементов
	for (int i = 0; i < size; i++)
	{
		dst[k] = mas[i];
		if (is_simple(mas[i]))
		{
			k++;
		}
	}

	m_size = k; //меняем размер (это значение будет возвращено)
	int* dest = new int[m_size]; //новый массив
	for (int i = 0; i < m_size; i++)
	{
		dest[i] = dst[i];
	}
	return dest; //пересохраняем массив
}

void print_menu()
{
	cout << "1. Ввод массива" << endl;
	cout << "2. Вывод массива" << endl;
	cout << "3. Найти минимум массива" << endl;
	cout << "4. Найти максимум массива" << endl;
	cout << "5. Заменить минимум и максимум с началом и концом массива" << endl;
	cout << "6. Удалить все чётные числа из массива" << endl;
	cout << "7. Заполнить случайными числами" << endl;
	cout << "8. Оставить только простые числа" << endl;
	cout << "0. Выход" << endl;
}

int main()
{
	setlocale(LC_ALL, "russian");

	srand(time(0));

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
		case 7:
			{
				cout << "Введите размер массива: ";
				cin >> size;

				mas = new int[size];
				fill_random(mas, size);
				cout << "Массив заполнен." << endl;
				break;
			}
		case 8:
			{
				if (size == -1)
				{
					cout << "Перед удалением необходимо ввести массив!" << endl;
					break;
				}
				int m_size;
				int* m = remove_non_simple(mas, size, m_size);
				write_mas(m, m_size);
				break;
			}
		}
	}
	while (t != 0);


	system("pause");

	return 0;
}
