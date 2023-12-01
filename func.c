#include<stdio.h>
#include<stdlib.h>
#include"func.h"
/*
1-Попробовать запись и отображение полей в несколько строк DONE
2-Добавить поиск структур
3-Добавить поиск структур по полям
*/
void create(struct community** arr, int* n)
{
	retry:
	printf("n= ");
	if(scanf("%d", n)==1)
	{
		if(*n<=0)
		{
			printf("Error: n less or equal 0");
			return;
		}
		*arr = (struct community*)calloc(*n,sizeof(struct community*));
		for(int i=0;i<*n;i++)
		{
			printf("community name: ");
			scanf("%s", (*arr)[i].name);
			printf("community description: ");
			scanf("%s", (*arr)[i].description);
			printf("community members: ");
			scanf("%i", &(*arr)[i].members); //вылетает на этом моменте
		};
	}
	else
	{
		printf("WHAT ARE YOU DO...X_X\n");
		printf("Please, write n once again. CORRECTLY. PLEASE.\n");
		fflush(stdin);
		goto retry;
	}
}
void write(struct community* arr, int n, char name[20])
{
	FILE* f = fopen(name, "w");
	if (!f)
	{
		printf("Error: %s not found", *name);
		return;
	}
	fprintf(f, "%d\n", n);
	for (int i = 0;i < n;i++)
		fprintf(f, "%s %s %d\n", (arr)[i].name,(arr)[i].description,(arr)[i].members);
	fclose(f);
}
void read(struct community** arr, int* n, char name[20])
{
	FILE* f = fopen(name, "r");
	if (!f)
	{
		printf("Error: %s not found", *name);
		return;
	}
	if (fscanf(f, "%d", n) != 1)
	{
		fclose(f);
		return;
	}
	*arr = (struct community*)calloc(*n, sizeof(struct community*));
	for (int i = 0;i < *n;i++)
		if(fscanf(f, "%s %s %i", (*arr)[i].name, (*arr)[i].description, &(*arr)[i].members)!=3) break; //вылетает
	fclose(f);
}