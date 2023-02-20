#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


static char* plmed[] =
{
	"erorr",
	"Gold",
	"Silver",
	"Bronze"
};
enum place
{
	GOLD = 1, SILVER, BRONZE
};
typedef enum place med;

struct FigureSkater
{
	char* name;
	char* surname;
};

struct FigureSkating_Olympics
{
	struct FigureSkater fs;
	med medal;
	int year;
};

typedef struct FigureSkating_Olympics fsk;

int check_n();
int check_s();
fsk* create_mas(int n);
void input(fsk* mas, int n);
void output(fsk* mas, int n);
int check_s();
void insertionSort_n(fsk* mas, int n);
void insertionSort_s(fsk* mas, int n);
void insertionSort_m(fsk* mas, int n);
void insertionSort_y(fsk* mas, int n);
int check_del(int n);
void delete_struct(fsk* mas, int *n, int del);
void choose_sort(fsk* mas, int n, int sr, int sr2);

void name_surname(fsk* mas, int n);
void name_medal (fsk* mas, int n);
void name_year(fsk* mas, int n);

void surname_name(fsk* mas, int n);
void surname_medal(fsk* mas, int n);
void surname_year(fsk* mas, int n);

void medal_name(fsk* mas, int n);
void medal_surname(fsk* mas, int n);
void medal_year(fsk* mas, int n);

void year_name(fsk* mas, int n);
void year_surname(fsk* mas, int n);
void year_medal(fsk* mas, int n);

void free_mas(fsk** mas, int n);