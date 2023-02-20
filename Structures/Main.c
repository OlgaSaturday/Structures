#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	int n = 0, sr = 0, sr2 = 0, del = 0;
	printf("Введите количество спортсменов ");
	n = check_n();
	fsk* mas;
	mas = create_mas(n);
	input(mas, n);
	printf("\n");
	output(mas, n);
	printf("\n");

	if (n > 1)
	{
		//for (int i = 0; i < 5; i++)
		//{
			printf("Выберите критерий для сравнения\n1 - по именам\n2 - по фамилиям\n3 - по занятому месту\n4 - по году проведения Олимпийских игр\n");
			sr = check_s();
			switch (sr)
			{
			case 1: insertionSort_n(mas, n);
				break;
			case 2: insertionSort_s(mas, n);
				break;
			case 3: insertionSort_m(mas, n);
				break;
			case 4: insertionSort_y(mas, n);
				break;
			}
			printf("\n");
			output(mas, n);
		//}
		if (n > 2)
		{
			printf("Выберите критерий для повторного сравнения\n1 - по именам\n2 - по фамилиям\n3 - по занятому месту\n4 - по году проведения Олимпийских игр\n");
			sr2 = check_s();
			choose_sort(mas, n, sr, sr2);
			output(mas, n);
		}

		printf("Введите номер структуры, которую нужно удалить: ");
		del = check_del(n);
		delete_struct(mas, &n, del);
		output(mas, n);
	}

	//free_mas(mas, n);
	getchar();
	return 0;
}