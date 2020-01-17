#include <iostream>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

void fillrandarr(int*, int);     // Заполнение массива случайными числами
int* createmptyarr(int); // Создание пустого массива
void showarr(int*, int);   // Вывод массива
void delarr(int*);       // Удаление массива
int* copyarr(int*, int); // Копирование массива
void selectSort(int*, int); // Сортировка выбором
void bubbleSort(int*, int); // Сортировка пузырьком 
void insertSort(int*, int); // Сортировка вставками 

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n;
	cout << "Введите размер массива. Массив одномерный типа int (целочисленный)" << endl;
	cin >> n;
	int* arr = createmptyarr(n);
	fillrandarr(arr, n);
	int* arr2 = copyarr(arr, n);
	int* arr3 = copyarr(arr, n);

	auto begin = std::chrono::steady_clock::now();
	bubbleSort(arr, n);
	auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    cout << "Время сортировки пузырьком: " << elapsed_ms.count() << " ms\n";
	
	begin = std::chrono::steady_clock::now();
	selectSort(arr2, n);
	end = chrono::steady_clock::now();
	elapsed_ms = chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout<< "Время сортировки выбором: " << elapsed_ms.count() << " ms\n";

	begin = std::chrono::steady_clock::now();
	insertSort(arr3, n);
	end = chrono::steady_clock::now();
	elapsed_ms = chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout << "Время сортировки вставками: " << elapsed_ms.count() << " ms\n";


	system("pause");
	delarr(arr);
	delarr(arr2);
	delarr(arr3);
	return 0;
}

void fillrandarr(int* arr, int n)
{
		for (int i = 0; i < n; i++)
			arr[i]=rand() %1001; // от 0 до 1000
}

int* createmptyarr(int n)
{
	int* arr = new int [n];
	return arr;
}

void showarr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
			cout << arr[i] << ' ';
	}
	cout << endl;
}

void delarr(int *arr)
{
	delete[] arr;
}

int * copyarr(int * A, int n)
{   
	int *B = createmptyarr(n);
	for (int i = 0; i < n; i++)
		B[i] = A[i];
	return B;
}

void selectSort(int* arr, int size)
{
	int tmp, i, j, pos;
	for (i = 0; i < size; ++i) // i - номер текущего шага
	{
		pos = i;
		tmp = arr[i];
		for (j = i + 1; j < size; ++j) // цикл выбора наименьшего элемента
		{
			if (arr[j] < tmp)
			{
				pos = j;
				tmp = arr[j];
			}
		}
		arr[pos] = arr[i];
		arr[i] = tmp; // меняем местами наименьший с a[i]
	}
}

void bubbleSort(int* arr, int size)
{
	int tmp, i, j;

	for (i = 0; i < size - 1; ++i) // i - номер прохода
	{
		for (j = 0; j < size - 1; ++j) // внутренний цикл прохода
		{
			if (arr[j + 1] < arr[j])
			{
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	cout << 's' << endl;
}

void insertSort(int* arr, int size)
{
	int i, j, tmp;
	for (i = 1; i < size; ++i) // цикл проходов, i - номер прохода
	{
		tmp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > tmp; --j) // поиск места элемента в готовой последовательности 
			arr[j + 1] = arr[j];    // сдвигаем элемент направо, пока не дошли
		arr[j + 1] = tmp; // место найдено, вставить элемент    
	}
}