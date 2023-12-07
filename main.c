#include<stdio.h>
#include<stdlib.h>
#include"func.h"

int main()
{
	struct community* arr = NULL;
	int n = 0;
	int stop = 0;
	while(stop!=1)
	{
		printf("1-read from file, 2-create new database, 3-print current database, 4-find in current database ");
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
					printf("Do you want to save this on file?\n\ty-yes\n\tn or other-no\nenter: ");
					if(scanf("%s",&key2)==1)
					{
						if(key2=="y")
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
					printf("\nname: %s\ndescription: %s\nmembers: %i\n", arr[i].name, arr[i].description, arr[i].members);
				printf("\n");
				break;
			case 4:
				int key2;
				printf("enter the number of the field you want to search for\n\t1-name\n\t2-description\n\t3-members\nenter: ");
				if(scanf("%i",&key2)!=1)
				{
					printf("error: writed wrong value\n");
					while((key2 = getchar()) != '\n');
				}
				else if(key2>0&&key2<=3)
				{
					found(arr,&n,key2);
				}
				else
				{
					printf("error: entered number is wrong");
				}
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