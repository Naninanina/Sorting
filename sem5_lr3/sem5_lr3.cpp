#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;

void insertion_sort(int arr[], int size)				// Сортировка вставками (Insertion sort)
{
	for (int i = 1; i < size; i++)
	{
		int j = i - 1;
		int key = arr[i];
		while (arr[j] > key && j >= 0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void selection_sort(int arr[], int size)				// Сортировка выбором (Selection sort)
{
	for (int i = size - 1; i > 0; i--)
	{
		int max = arr[0];
		int index = 0;
		for (int j = 0; j <= i; j++)
		{
			if (arr[j] > max)
			{
				max = arr[j];
				index = j;
			}
		}
		swap(arr[index], arr[i]);
	}
}

void bubble_sort(int arr[], int size)					// Пузырьковая сортировка (Bubble sort)
{
	while (size--)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
			}
		}
	}
}

void merge(int arr[], int first, int last, int mid)		// Сортировка слиянием (Merge sort)
{
	int size = last - first + 1;
	int *newArr = new int[size];
	int start = first;
	int final = mid + 1;
	for (int i = 0; i < size; i++)
	{
		if ((start <= mid) && ((final > last) || (arr[start] < arr[final])))
		{
			newArr[i] = arr[start];
			start++;
		}
		else
		{
			newArr[i] = arr[final];
			final++;
		}
	}
	int count = 0;
	for (int i = first; i <= last; i++, count++) arr[i] = newArr[count];
	delete [] newArr;
}

void merge_sort(int arr[], int start, int end)
{
	int mid;
	if (start < end)
	{
		mid = (start + end) / 2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, start, end, mid);
	}
}

void shell_sort(int arr[], int size)					// Сортировка Шелла (Shell sort)
{
	int d = size / 2;

	while (d >= 1)
	{
		for (int i = d; i < size; i++)
		{
			int j = i;
			while ((j >= d) && (arr[j - d] > arr[j]))
			{
				swap(arr[j - d], arr[j]);
				j = j - d;
			}
		}
		d = d / 2;
	}
}

void quick_sort(int arr[], int size)					// Быстрая сортировка (Quick sort)
{
	int i = 0;
	int j = size - 1;

	int mid = arr[size / 2];

	do {
		while (arr[i] < mid) {
			i++;
		}

		while (arr[j] > mid) {
			j--;
		}

		if (i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) {
		quick_sort(arr, j + 1);
	}
	if (i < size) {
		quick_sort(&arr[i], size - i);
	}
}

void print(int arr[], int size, string message = "Массив: ")
{
	cout << message << endl;
	for (int i = 0; i < size; i++) cout << "\t" << i << "\t" << arr[i] << endl;
	cout << endl;
}

void swap(int *ind1, int *ind2)
{
	int temp = *ind1;
	*ind1 = *ind2;
	*ind2 = temp;
}

int intValidation()
{
	while (true)
	{
		int val;
		cin >> val;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(2147483647, '\n');
			cout << "Вы ввели неверное значение, попробуйте еще раз: ";
		}
		else
		{
			cin.ignore(2147483647, '\n');
			return val;
		}
	}
}

int checkForExistence(int numOne, int numTwo, string message)
{
	int choice;
	cin >> choice;
	if (choice >= numOne && choice <= numTwo)
	{
		return choice;
	}
	else
	{
		do
		{
			cout << message << endl;
			choice = intValidation();
		} while (!(choice >= numOne && choice <= numTwo));
		return choice;
	}
}

void autocomplete(int arr[], int size)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand();
	}
} 

void autocomplete_descending_order(int arr[], int size)		// Автозаполнение в порядке убывания
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = size - i;
	}
}

void autocomplete_ascending_order(int arr[], int size)		// Автозаполнение в порядке возрастания
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
}

void autocomplete_shell_sort_worst(int arr[], int size)		// Автозаполнение для худшего случая сортировки Шелла (самые большие числа находятся на нечетных позициях в порядке убывания, а самые маленькие находятся на четных позициях тоже в порядке убывания)
{
	for (int i = 0; i < size; i += 2)
	{
		arr[i] = size - i;
	}
	for (int i = 1; i < size; i += 2)
	{
		arr[i] = size/2 - i;
	}
}

void autocomplete_quick_sort_worst(int arr[], int size)		// Автозаполнения для худшего случая быстрой сортировки
{
	if (size % 2)
	{
		int count = 0;										// Заполнение для массива с нечетным количеством элементов, пример: 1 3 5 7 6 4 2
		for (int i = size / 2; i >= 0; i--)					// Заполнение первой половины массива:								1 3 5 7
		{
			arr[i] = size - count;
			count += 2;
		}
		count = 0;
		for (int i = size / 2 + 1; i < size; i++)			// Заполнение второй половины массива:										6 4 2
		{
			arr[i] = size - count - 1;
			count += 2;
		}
	}
	else
	{
		int count = 0;										// Заполнение для массива с нечетным количеством элементов, пример: 2 4 6 7 5 3
		for (int i = size / 2; i < size; i++)				// Заполнение второй половины массива:									  7 5 3
		{
			arr[i] = size - count;
			count += 2;
		}
		count = 0;
		for (int i = size / 2 - 1; i >= 0; i--)				// Заполнение первой половины массива:								2 4 6
		{
			arr[i] = size - count - 1;
			count += 2;
		}
	}
}

void copy_arr(int arr[], int newArr[], int size)
{
	for (int i = 0; i < size; i++) newArr[i] = arr[i];
}

void print_menu()
{
	//system("cls");
	cout << "Какой сортировкой отсортируем массив?" << endl;
	cout << "1. Сортировка вставками (Insertion sort)" << endl;
	cout << "2. Сортировка выбором (Selection sort)" << endl;
	cout << "3. Пузырьковая сортировка (Bubble sort)" << endl;
	cout << "4. Сортировка слиянием (Merge sort)" << endl;
	cout << "5. Сортировка Шелла (Shell sort)" << endl;
	cout << "6. Быстрая сортировка (Quick sort)" << endl;
	cout << "7. Функция сортировки из базовой библиотеки С++" << endl;
	cout << "8. Выйти" << endl;
	cout << ">";
}

void timing(void (*sorting)(int arr[], int size), void (*autocomplete)(int arr[], int size))
{
	string strx = "";
	string stry = "";
	for (int i = 10000; i <= 50000; i += 5000)
	{
		int *tempArr = new int[i];

		autocomplete(tempArr, i);
		//print(tempArr, i);

		auto start = chrono::high_resolution_clock::now();
		sorting(tempArr, i);
		auto end = chrono::high_resolution_clock::now();

		chrono::duration<float> duration = end - start;
		cout << "Время выполнения для " << i << " элементов: " << duration.count() << endl;

		strx += to_string(i) + ", ";
		string tempstry = to_string(duration.count());
		int pos = tempstry.find(',');
		tempstry.replace(pos, 1, 1, '.');
		stry += tempstry + ", ";

		delete[] tempArr;
	}
	cout << "string x: " << strx << endl;
	cout << "string y: " << stry << endl;
	cout << endl;
}

void timing(void(*sorting)(int arr[], int start, int end), void(*autocomplete)(int arr[], int size))
{
	string strx = "";
	string stry = "";
	for (int i = 10000; i <= 50000; i += 10000)
	{
		int *tempArr = new int[i];

		autocomplete(tempArr, i);

		auto start = chrono::high_resolution_clock::now();
		sorting(tempArr, 0, i - 1);
		auto end = chrono::high_resolution_clock::now();

		chrono::duration<float> duration = end - start;
		cout << "Время выполнения для " << i << " элементов: " << duration.count() << endl;

		strx += to_string(i) + ", ";
		string tempstry = to_string(duration.count());
		int pos = tempstry.find(',');
		tempstry.replace(pos, 1, 1, '.');
		stry += tempstry + ", ";

		delete[] tempArr;
	}
	cout << "string x: " << strx << endl;
	cout << "string y: " << stry << endl;
}

void asymptotics(void(*sorting)(int arr[], int size), void(*autocomplete_worst)(int arr[], int size), void(*autocomplete_average)(int arr[], int size), void(*autocomplete_best)(int arr[], int size))
{
	cout << "Худший случай: " << endl;
	timing(sorting, autocomplete_worst);
	cout << "Средний случай: " << endl;
	timing(sorting, autocomplete_average);
	cout << "Лучший случай: " << endl;
	timing(sorting, autocomplete_best);
}

void asymptotics(void(*sorting)(int arr[], int start, int end), void(*autocomplete_worst)(int arr[], int size), void(*autocomplete_average)(int arr[], int size), void(*autocomplete_best)(int arr[], int size))
{
	cout << "Худший случай: " << endl;
	timing(sorting, autocomplete_worst);
	cout << "Средний случай: " << endl;
	timing(sorting, autocomplete_average);
	cout << "Лучший случай: " << endl;
	timing(sorting, autocomplete_best);
}

int main()
{
	setlocale(LC_ALL, "ru");

	int choice;

	do {
		print_menu();
		choice = checkForExistence(1, 11, "Вы ввели несуществующий пункт. Повторите попытку: ");

		switch (choice)
		{
		case 1:
		{
			cout << "Сортировка вставками" << endl;
			asymptotics(insertion_sort, autocomplete_descending_order, autocomplete, autocomplete_ascending_order);
			break;
		}
		case 2:
		{
			cout << "Сортировка выбором" << endl;
			asymptotics(selection_sort, autocomplete_descending_order, autocomplete, autocomplete_ascending_order);
			break;
		}
		case 3:
		{
			cout << "Пузырьковка сортировка" << endl;
			asymptotics(bubble_sort, autocomplete_descending_order, autocomplete, autocomplete_ascending_order);
			break;
		}
		case 4:
		{
			cout << "Сортировка слиянием" << endl;
			asymptotics(merge_sort, autocomplete_shell_sort_worst, autocomplete, autocomplete_ascending_order);
			break;
		}
		case 5:
			cout << "Сортировка Шелла" << endl;
			asymptotics(shell_sort, autocomplete_shell_sort_worst, autocomplete, autocomplete_ascending_order);
			break;
		case 6:
			cout << "Быстрая сортировка" << endl;
			asymptotics(quick_sort, autocomplete_quick_sort_worst, autocomplete, autocomplete_ascending_order);
			break;
		case 7:
		{
			string strx = "";
			string stry = "";
			for (int i = 10000; i <= 50000; i += 5000)
			{
				int *tempArr = new int[i];
				autocomplete(tempArr, i);
				auto start = chrono::high_resolution_clock::now();
				sort(tempArr, tempArr + i);
				auto end = chrono::high_resolution_clock::now();
				chrono::duration<float> duration = end - start;
				cout << "Время выполнения для " << i << "элементов: " << duration.count() << endl;
				strx += to_string(i) + ", ";
				stry += to_string(duration.count()) + ", ";
				delete[] tempArr;
			}
			cout << "string x: " << strx << endl;
			cout << "string y: " << stry << endl;
			break;
		}
		case 8:
			cout << "Всего доброго!" << endl;
			return 0;
		}
	} while (choice != 7);
}
