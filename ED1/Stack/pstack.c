#include "pstack.h"

/*Função que cria e inicializa uma pilha de tamanho {size}.*/
Stack *create (int size) {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->peek = 0;
  s->size = size;
  s->array = (point *)malloc(size * sizeof(point));
  return s;
}

/*Função para empilhar {elem} na pilha {s}.*/
void push (Stack *s, point elem) {
  if (full(s)) {
    printf ("error: stack overflow!\n");
    exit(1);
  }	  
  s->array[s->peek] = elem;
  s->peek++;
}

/*Função para desempilhar o elemento no topo da pilha {s}.*/
point pop (Stack *s) {
  if (empty(s)) {
    printf ("error: stack underflow!\n");
    exit(1);
  }	  
  s->peek--;
  return s->array[s->peek];
}

/*Função que retorna mas não remove o primeiro elemento de {s}.*/
point get_peek (Stack *s) {
  if (!empty(s)) 
    return s->array[s->peek-1];	  
}

/*Função que verifica se a pilha {q} está vazia (true) ou não {false}.*/
int empty (Stack *s) {
  return (s->peek == 0);	
}

/*Função que verifica se a pilha {q} está cheia (true) ou não {false}.*/
int full (Stack *s) {
  return (s->peek == s->size);	
}

/*Função que desaloca as estruturas de uma pilha {s}.*/
void destroy (Stack *s) {
  free (s->array);
  free (s);
}

/*Função que retorna o número de elementos alocados no array*/
int get_size (Stack *s) {
  return s->size;
}

/*Função que imprime uma pilha {s}.*/
void print (Stack *s) {
  int i;
  printf("Stack: ");
  for (i = s->peek-1; i >= 0; i--) {
    printf ("(%d,%d) ", s->array[i].x, s->array[i].y);
  }
  printf("\n");
}
