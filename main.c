#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_FILOSOFOS 5

sem_t hashis[NUM_FILOSOFOS]; // Semáforos para os garfos
sem_t mutex;

void *filosofo(void *num) {
    int i = *(int *)num;
    int hashi_esquerdo = i;
    int hashi_direito = (i + 1) % NUM_FILOSOFOS;
    
    while (1) {
        printf("Filosofo %d esta pensando.\n", i);
        sleep(rand() % 3);
        
        sem_wait(&mutex);   // Região crítica para pegar os hashis

        // Pegar os hashis
        sem_wait(&hashis[hashi_esquerdo]);
        sem_wait(&hashis[hashi_direito]);
        
        sem_post(&mutex);   // Sai da região crítica

        printf("Filosofo %d esta comendo.\n", i);
        sleep(rand() % 3);

        // Devolver os hashis
        sem_post(&hashis[hashi_esquerdo]);
        sem_post(&hashis[hashi_direito]);
    }
    return NULL;
}

int main() {
    pthread_t filosofos[NUM_FILOSOFOS];
    int i, indices[NUM_FILOSOFOS];

    // Inicializa os semáforos
    for (i = 0; i < NUM_FILOSOFOS; i++) {
        sem_init(&hashis[i], 0, 1);
    }
    sem_init(&mutex, 0, 1);  // Mutex para proteger o acesso ao semáforo de capacidade

    // Cria as threads dos filósofos
    for (i = 0; i < NUM_FILOSOFOS; i++) {
        indices[i] = i;
        pthread_create(&filosofos[i], NULL, filosofo, &indices[i]);
    }

    // Espera as threads terminarem
    for (i = 0; i < NUM_FILOSOFOS; i++) {
        pthread_join(filosofos[i], NULL);
    }

    // Destroi os semáforos
    for (i = 0; i < NUM_FILOSOFOS; i++) {
        sem_destroy(&hashis[i]);
    }
    sem_destroy(&mutex);

    return 0;
}
