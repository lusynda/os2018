#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define BUFFER_SIZE 10


typedef struct{
	char *type;
	int amount;
	char *unit;
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i){
	while((first + 1) % BUFFER_SIZE == last){
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
}


item *consume(){
	item *i = malloc(sizeof(item));
	while (first == last){
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	return i;
}

void *pthread_produce(void *param){
	item chicken, fries, beef;

        chicken.type = "fried";
        chicken.amount = 5;
        chicken.unit = "kg";

        fries.type = "grill";
        fries.amount = 10;
        fries.unit = "gram";

        beef.type = "grill";
        beef.amount = 1;
        beef.unit = "kg";

	produce(&chicken);
        produce(&fries);
        produce(&beef);
}

void display(item *i){
	printf("%s %d %s\n", i->type, i->amount, i->unit);
}

void *pthread_consume(void *param){
	display(consume());
	display(consume());
}

int main(){
	pthread_t tid1, tid2;

	pthread_create(&tid1, NULL, pthread_produce, NULL);

	pthread_create(&tid2, NULL, pthread_consume, NULL);

	pthread_join(tid1, NULL);

	pthread_join(tid2, NULL);
}
