#include <unistd.h>
#include <pthread.h>
#include <stdio.h>



void    *ThreadFunc(void *args)
{
    int i;
    for(i = 0; i < 25;i++)
    {
        printf("This is from thread i = %d\n",i);
        sleep(1);
    }
    return 0;
}

int     main()
{
    pthread_t mythread;
    void    *thread_result;
    pthread_create(&mythread,NULL,ThreadFunc,NULL);
    int i;
    for(i = 0; i < 25;i++)
    {
        printf("This is from thread j = %d\n",i);
        sleep(1);
    }
    pthread_join(mythread,thread_result);
    return 0;
}