#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[])
{
	if(argc < 2)
		return 1;
	unsigned int seed = time(NULL) + atoi(argv[2]);
    int total = atoi(argv[1]);
	double x,y,distancia;
	int dentro = 0;
	while(total>0)
	{
		x = (double) rand_r(&seed)/RAND_MAX;
		y = (double) rand_r(&seed)/RAND_MAX;
		distancia = x*x + y*y;
		if (distancia <= 1)
		{
			dentro++;
		}
		total--;
	}
	printf("%d", dentro);
	return 0;
}
