#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main()
{
size_t size = 1048576;
int *array = (int*)malloc(sizeof(int)*size);
FILE *file;
clock_t start_c, end_c, start_p1, end_p1, start_pall, end_pall;
double time_c, time_p1, time_pall;
size_t loop = 9;


//Skapa element till array
for (int i =  0; i<size; i++)
	array[i] = (rand() % 100);


//Öppnar fil 
file = fopen("array_file.bin","wb");

if (file == NULL)
	{
	printf("Error, can not open file");
	return -1;
	}


//skriver in i filen
start_c = (double) clock();
for (int i = 0; i < size; i++)
	{
        fwrite(&array[i], sizeof(int), 1, file);
	fflush(file);
		}
end_c = (double) clock();
time_c = ((double)(end_c-start_c))/(CLOCKS_PER_SEC);
printf("Time for creating array in file: %f\n",time_c);

fclose(file);

//Öppnari filen igen för läsning
file = fopen("array_file.bin", "rb");
    if (file == NULL) 
    {
        printf("Error, can not open file");
        return -1;
    }

//läser filen, en åt gången
start_p1 = (double) clock();
for (size_t l = 0; l<loop; l++)
	{
	int *array_read = (int*)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
		{
		fread(&array_read[i], sizeof(int),1,file);
	//	printf("One int at the time: %d\n",array_read[i]);
		}
	free(array_read);
	}
end_p1 = (double) clock();
time_p1 = ((double)(end_p1-start_p1))/(CLOCKS_PER_SEC);
printf("Time for reading array in file, one at a time: %f\n",time_p1);



//Läser alla på en gång

start_pall = (double) clock();
for (size_t l = 0; l<loop; l++)
	{
	int *array_read_all = (int*)malloc(sizeof(int)*size);
	fread(&array_read_all, sizeof(int),size,file);
	//printf("All int at the time:");
	for (int i = 0; i < size; i++)
		{
	//	printf("%d\n",array_read_all[i]);
		}
	free(array_read_all);
	}
end_pall = (double) clock();
time_pall = ((double)(end_pall-start_pall))/(CLOCKS_PER_SEC);
printf("Time for reading all array in file: %f\n",time_pall);


fclose(file);
free(array);
}


