#include<stdio.h>
#include<stdlib.h>
#include"func.h"

void create(struct community** arr, int* n)
{
	retry:
	printf("n= ");
	if(scanf("%i",n)==1)
	{
		if(*n<=0)
		{
			printf("Error: n less or equal 0");
			return;
		}
		*arr = (struct community*)calloc(*n,sizeof(struct community));
		for(int i=0;i<*n;i++)
		{
			printf("community name: ");
			scanf("%s", (*arr)[i].name);
			printf("community description: ");
			scanf("%s", (*arr)[i].description);
			printf("community members: ");
			scanf("%i", &(*arr)[i].members);
		}
	}
	else
	{
		printf("WHAT ARE YOU DO...X_X\n");
		printf("Please, write n once again. CORRECTLY. PLEASE.\n");
		while((*n = getchar()) != '\n');
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
		printf("Error: %s not found\n", name);
		return;
	}
	if (fscanf(f, "%d", n) != 1)
	{
		fclose(f);
		return;
	}
	*arr = (struct community*)calloc(*n, sizeof(struct community));
	for (int i = 0;i < *n;i++)
	{
		if(fscanf(f, "%s %s %d", (*arr)[i].name, (*arr)[i].description, &(*arr)[i].members)!=3);
	}
	fclose(f);
}
void found(struct community* arr, int* n, int found_ind)
{
	int key1;
	char key2[50];
	switch(found_ind)
	{
		case 1:
			printf("enter name: ");
			scanf("%s",key2);
			break;
		case 2:
			printf("enter description: ");
			scanf("%s",key2);
			break;
		case 3:
			printf("enter members:");
			scanf("%i",&key1);
			break;
	}
	printf("\n");
	for(int i=0;i<*n;i++)
	{
		if(arr[i].members==key1||(arr[i].name==key2&&found_ind==1)||(arr[i].description==key2&&found_ind==2))
		{
			printf("name: %s\ndescription: %s\nmembers: %i\n\n", arr[i].name, arr[i].description, arr[i].members);
		}
	}
}