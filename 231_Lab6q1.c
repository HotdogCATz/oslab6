//64050231

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int msum = 0;
int csum = 0;
int dif = 0;
void *runner(void *param);

int main(int argc, char *argv[])
{
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);

    pthread_join(tid, NULL);
    int upper = atoi(argv[1]);
    int i;
    if (upper > 0)
    {
        for (i = 0; i <= upper; i++)
        {
            msum += i;
        }
    }
    dif = csum - msum;
    printf("msum = %d   csum = %d\n", msum,csum);
    printf("difference = %d\n",dif);
    return 0;
}
void *runner(void *param)
{
    int upper = (atoi(param) * 2);
    int i;
    if (upper > 0)
    {
        for (i = 0; i <= upper; i++)
        {
            csum += i;
        }
        pthread_exit(0);
    }
}

//2.5 2 result
 //1  child finish before parent csum = 55, msum = 15 ans = 40 
 //2  prarent finish before child msum = 15  ans difference = -15