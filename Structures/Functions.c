#include "Header.h"

int check_n()
{
	int n;
	while (scanf_s("%d", &n) != 1 || n < 1 || getchar() != '\n')
	{
		printf("Неверный ввод\n");
		rewind(stdin);
	}
	return n;
}

int check_p()
{
	int p;
	while (scanf_s("%d", &p) != 1 || p < 1 || p > 3|| getchar() != '\n')
	{
		printf("Неверный ввод\n");
		rewind(stdin);
	}
	return p;
}

fsk* create_mas(int n)
{
	fsk* mas;
	mas = (fsk*)calloc(n, sizeof(fsk));
	for (int i = 0; i < n; i++)
	{
		mas[i].fs.name = (char*)calloc(20, sizeof(char));
		mas[i].fs.surname = (char*)calloc(20, sizeof(char));
	}
	return mas;
}

void input(fsk* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Введите имя %d спортсмена: ", i + 1);
		fflush(stdin);
		fgets(mas[i].fs.name, 20, stdin);

		printf("Введите фамилию %d спортсмена: ", i + 1);
		fflush(stdin);
		fgets(mas[i].fs.surname, 20, stdin);

		printf("Введите место, которое занял %d спортсмен: ", i + 1);
		int p;
		p = check_p();
		mas[i].medal = p;

		printf("Введите год, когда проходили Олимпийские игры: ");
		int y;
		y = check_n();
		mas[i].year = y;
	}
}

void output(fsk* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s", mas[i].fs.name);
		printf("%s", mas[i].fs.surname);
		printf("%s", plmed[mas[i].medal]);
		printf("\n");
		printf("%d", mas[i].year);
		printf("\n\n");
	}
}

int check_s()
{
	int s;
	while (scanf_s("%d", &s) != 1 || s < 1 || s > 5 || getchar() != '\n')
	{
		printf("Неверный ввод\n");
		rewind(stdin);
	}
	return s;
}

void insertionSort_n(fsk* mas, int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0 && (strcmp(mas[j].fs.name, mas[j + 1].fs.name) > 0))
		{
			fsk temp = mas[j];
			mas[j] = mas[j + 1];
			mas[j + 1] = temp;

			j--;
		}
	}
}

void insertionSort_s(fsk* mas, int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0 && (strcmp(mas[j].fs.surname, mas[j + 1].fs.surname) > 0))
		{
			fsk temp = mas[j];
			mas[j] = mas[j + 1];
			mas[j + 1] = temp;

			j--;
		}
	}
}

void insertionSort_m(fsk* mas, int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0 && mas[j].medal > mas[j + 1].medal)
		{
			fsk temp = mas[j];
			mas[j] = mas[j + 1];
			mas[j + 1] = temp;

			j--;
		}
	}
}

void insertionSort_y(fsk* mas, int n)
{
	for (int i = 1; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0 && mas[j].year > mas[j + 1].year)
		{
			fsk temp = mas[j];
			mas[j] = mas[j + 1];
			mas[j + 1] = temp;

			j--;
		}
	}
}

int check_del(int n)
{
	int del;
	while (scanf_s("%d", &del) != 1 || del < 1 || del > n || getchar() != '\n')
	{
		printf("Неверный ввод\n");
		rewind(stdin);
	}
	return del;
}

void delete_struct(fsk* mas, int *n, int del)
{
	int ind = del - 1;
	for (int i = ind; i < *n - 1; i++)
	{
		mas[i] = mas[i + 1];
	}
	*n = *n -1;
	mas = (fsk*)realloc(mas, *n * sizeof(fsk));
}

void choose_sort(fsk* mas, int n, int sr, int sr2)
{
	if (sr == sr2)
	{
		printf("Указаны одинаковые поля для сортировки");
		return;
	}
	if (sr == 1)
	{
		switch (sr2)
		{
		case 2: name_surname(mas, n);
			break;
		case 3: name_medal(mas, n);
			break;
		case 4: name_year(mas, n);
			break;
		}
	}
	if (sr == 2)
	{
		switch (sr2)
		{
		case 1: surname_name(mas, n);
			break;
		case 3: surname_medal(mas, n);
			break;
		case 4: surname_year(mas, n);
			break;
		}
	}
	if (sr == 3)
	{
		switch (sr2)
		{
		case 1: medal_name(mas, n);
			break;
		case 2: medal_surname(mas, n);
			break;
		case 4: medal_year(mas, n);
			break;
		}
	}
	if (sr == 4)
	{
		switch (sr2)
		{
		case 1: year_name(mas, n);
			break;
		case 2: year_surname(mas, n);
			break;
		case 3: year_medal(mas, n);
			break;
		}
	}
}

void name_surname(fsk* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0 && (strcmp(mas[j].fs.name, mas[j + 1].fs.name) == 0) && (strcmp(mas[j].fs.surname, mas[j + 1].fs.surname) > 0))
		{
			fsk temp = mas[j];
			mas[j] = mas[j + 1];
			mas[j + 1] = temp;

			j--;
		}

	}
}
void name_medal(fsk* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0 && (strcmp(mas[j].fs.name, mas[j + 1].fs.name) == 0) && (mas[j].medal > mas[j + 1].medal))
		{
			fsk temp = mas[j];
			mas[j] = mas[j + 1];
			mas[j + 1] = temp;

			j--;
		}
	}
}
void name_year(fsk* mas, int n)
{
	
	for (int i = 0; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0 && (strcmp(mas[j].fs.name, mas[j + 1].fs.name) == 0) && (mas[j].year > mas[j + 1].year))
		{
			fsk temp = mas[j];
			mas[j] = mas[j + 1];
			mas[j + 1] = temp;

			j--;
		}
	}
}

void surname_name(fsk* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0 && (strcmp(mas[j].fs.surname, mas[j + 1].fs.surname) == 0) && (strcmp(mas[j].fs.name, mas[j + 1].fs.name) > 0))
		{
			fsk temp = mas[j];
			mas[j] = mas[j + 1];
			mas[j + 1] = temp;

			j--;
		}

	}
}
void surname_medal(fsk* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0 && (strcmp(mas[j].fs.surname, mas[j + 1].fs.surname) == 0) && (mas[j].medal > mas[j + 1].medal))
		{
			fsk temp = mas[j];
			mas[j] = mas[j + 1];
			mas[j + 1] = temp;

			j--;
		}
	}
}
void surname_year(fsk* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0 && (strcmp(mas[j].fs.surname, mas[j + 1].fs.surname) == 0) && (mas[j].year > mas[j + 1].year))
		{
			fsk temp = mas[j];
			mas[j] = mas[j + 1];
			mas[j + 1] = temp;

			j--;
		}
	}
}

void medal_name(fsk* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0 && (mas[j].medal == mas[j + 1].medal) && (strcmp(mas[j].fs.name, mas[j + 1].fs.name) > 0))
		{
			fsk temp = mas[j];
			mas[j] = mas[j + 1];
			mas[j + 1] = temp;

			j--;
		}
	}
}
void medal_surname(fsk* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0 && (mas[j].medal == mas[j + 1].medal) && (strcmp(mas[j].fs.surname, mas[j + 1].fs.surname) > 0))
		{
			fsk temp = mas[j];
			mas[j] = mas[j + 1];
			mas[j + 1] = temp;

			j--;
		}
	}
}
void medal_year(fsk* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0 && (mas[j].medal == mas[j + 1].medal) && (mas[j].year > mas[j + 1].year))
		{
			fsk temp = mas[j];
			mas[j] = mas[j + 1];
			mas[j + 1] = temp;

			j--;
		}
	}
}

void year_name(fsk* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0 && (mas[j].year == mas[j + 1].year) && (strcmp(mas[j].fs.name, mas[j + 1].fs.name) > 0))
		{
			fsk temp = mas[j];
			mas[j] = mas[j + 1];
			mas[j + 1] = temp;

			j--;
		}
	}
}
void year_surname(fsk* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0 && (mas[j].year == mas[j + 1].year) && (strcmp(mas[j].fs.surname, mas[j + 1].fs.surname) > 0))
		{
			fsk temp = mas[j];
			mas[j] = mas[j + 1];
			mas[j + 1] = temp;

			j--;
		}
	}
}
void year_medal(fsk* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i - 1;
		while (j >= 0 && (mas[j].year == mas[j + 1].year) && (mas[j].medal > mas[j + 1].medal))
		{
			fsk temp = mas[j];
			mas[j] = mas[j + 1];
			mas[j + 1] = temp;

			j--;
		}
	}
}








void free_mas(fsk** mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		free((*mas)[i].fs.name);
		free((*mas)[i].fs.surname);
	}
	free(*mas);
}
