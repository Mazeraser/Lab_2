#include<stdio.h>
#include<stdlib.h>
#include"func.h"

/*
1-Добавить поиск структур
2-Добавить поиск по полям
3-Добавить поиск файлов DONE
4-Добавить makefile DONE
*/
int main()
{
	struct community* arr = NULL;
	int n = 0;
	int stop = 0;
	while(stop!=1)
	{
		printf("1-read from file, 2-create new database, 3-print current database ");
		int key;
		scanf("%d", &key);
		char name[20];
		switch(key)
		{
			case 1:
				printf("enter file name(with extension): ");
				scanf("%s", name);
				read(&arr, &n, name);
				break;
			case 2:
				create(&arr, &n);
				if(n>0)
				{
					char key2[20];
					printf("Do you want to save this on file?\ny-yes\nn or other-no\nenter: ");
					if(scanf("%s",&key2)==1)
					{
						if(*key2=='y')
						{
							printf("enter file name(with extension): ");
							scanf("%s", name);
							write(arr, n, name);
						}
						break;
					}
				}
				break;
			case 3:
				for (int i = 0;i < n;i++)
					printf("name: %s\ndescription: %s\nmembers: %i\n", arr[i].name, arr[i].description, arr[i].members);
				break;
			default:
			 	stop = 1;
			 	break;
		}
	}
	if (arr)
		free(arr);
	return 0;
}