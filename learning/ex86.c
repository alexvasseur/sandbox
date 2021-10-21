#include <assert.h>
#include <stdlib.h>  //assert

typedef struct {
  int *counter1, *counter2;
} counter_s;

void check_counter(int *ctr) { assert(*ctr != 0); }

double ratio(counter_s const *in) {
  check_counter(in->counter2);
  return *in->counter1 / (*in->counter2 + 0.0);
}

int main() {
  counter_s cc = {.counter1 = malloc(sizeof(int)),
                  .counter2 = malloc(sizeof(int))};
  *cc.counter1 = *cc.counter2 = 1;
  ratio(&cc);
}