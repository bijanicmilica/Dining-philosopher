#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define N 5
#define RAZMISLJA 2
#define GLADAN 1
#define JELO 0
#define LEVO (filozof + 4) % N
#define DESNO (filozof + 1) % N

int stanje[N];
int filozofi[N] = { 0, 1, 2, 3, 4 };

sem_t mutex;
sem_t S[N];

void test(int filozof)
{


	if (stanje[filozof] == GLADAN
		&& stanje[LEVO] != JELO
		&& stanje[DESNO] != JELO) {
		stanje[filozof] = JELO;

		sleep(2);

		printf("Filozof %d uzima viljuške %d i %d\n",
					filozof + 1, LEVO + 1, filozof + 1);

		printf("Filozof %d jede\n", filozof + 1);

		sem_post(&S[filozof]);
	}
}

void uzmi_viljuske(int filozof)
{
	sem_wait(&mutex);

	stanje[filozof] = GLADAN;

	printf("Filozof %d je gladan\n", filozof + 1);

	test(filozof);

	sem_post(&mutex);

	sem_wait(&S[filozof]);

	sleep(1);
}

void vrati_viljuske(int filozof)
{
	sem_wait(&mutex);

	stanje[filozof] = RAZMISLJA;

	printf("Filozof %d vraća viljuške %d i %d\n",
		filozof + 1, LEVO + 1, filozof + 1);
	printf("Filozof %d razmišlja\n", filozof + 1);

	test(LEVO);
	test(DESNO);

	sem_post(&mutex);
}

void* filozof(void* num)
{
	while (1) {
		int* i = num;

		sleep(1);

		uzmi_viljuske(*i);

		sleep(0);

		vrati_viljuske(*i);
	}
}

int main()
{
	int i;
	pthread_t thread_id[N];

	sem_init(&mutex, 0, 1);

	for (i = 0; i < N; i++)

		sem_init(&S[i], 0, 0);

	for (i = 0; i < N; i++) {

		pthread_create(&thread_id[i], NULL,
					filozof, &filozofi[i]);

		printf("Filozof %d razmišlja\n", i + 1);
	}

	for (i = 0; i < N; i++)

		pthread_join(thread_id[i], NULL);

	return 0;
}
