struct community
{
	char name[20];
	char description[100];
	int members;
};
void create(struct community** arr, int* n);
void write(struct community* arr, int n, char name[20]);
void read(struct community** arr, int* n, char name[20]);