#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int counter = argc;
	FILE *arq;
	int num;
	int n_f = atoi(argv[1]);
	int medias=0;
	while(counter > 2)
	{
		arq = fopen(argv[counter-1],"r");
		fscanf(arq,"%d",&num);
		medias += num;
		fclose(arq);
		counter--;
	}
	printf("%f",4.0*medias/n_f);
	return 0;
}
