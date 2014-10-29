#include<iostream>
#include<sys/time.h>
#include<cstdlib>
#include<cstdio>
#include<pthread.h>
using namespace std;
int total,n_threads;
int dentro=0;
pthread_mutex_t lock;
void *montecarlo(void* rank);
int main()
{
    struct timeval start,end;
    double pi;
    long i;
    pthread_t *thread_handle;
    do
        cin >> n_threads;
    while(n_threads<1);
    cin >> total;
    thread_handle = (pthread_t*) malloc(n_threads*sizeof(pthread_t));
    //dentro = (int*) malloc(n_threads*sizeof(int));
    gettimeofday(&start , NULL);
    pthread_mutex_init(&lock,NULL);
    for(i=0;i<n_threads;i++)
    {
        pthread_create(&thread_handle[i],NULL,&montecarlo,(void*)i);
    }
    for(i=0;i<n_threads;i++)
    {
        pthread_join(thread_handle[i], NULL);
    }
    free(thread_handle);
    pthread_mutex_destroy(&lock);
    //cout <<"Total_dentro : " << dentro << "\n";
    pi =  4*((double)dentro/total);
    gettimeofday(&end , NULL);
    cout << pi << ";";
    cout <<  ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)) << endl;
    return 0;
}
 
void* montecarlo(void* param)
{
    int lancamentos;
    long my_rank = (long) param;
    unsigned int seed = time(NULL)+my_rank;
    int _dentro=0;
    int total_l = total/n_threads;
    int my_first = my_rank*total_l;
    int my_last = my_first+total_l;
    double x,y,distancia;
    for ( lancamentos = my_first; lancamentos < my_last; lancamentos++)
    {
        x = (double)rand_r(&seed)/RAND_MAX;
        y = (double)rand_r(&seed)/RAND_MAX;
        distancia = x*x + y*y;
        if (distancia <= 1)
            _dentro++;
    }
    pthread_mutex_lock(&lock);
    dentro +=_dentro;
    //cout <<"Thread " << my_rank << " total_dentro : " << _dentro << "\n";
    pthread_mutex_unlock(&lock);
    return 0;
}

