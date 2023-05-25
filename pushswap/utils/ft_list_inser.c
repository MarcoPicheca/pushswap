#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void    printList(struct node *p);
void list_insert(struct node **head, int new_data);
int list_search(struct node **head, int cercato);
void list_delete(struct node** head, int key);

int main()
{
    struct node *head = NULL;
    int nodoCercato, nodoCancellato;
    int new_data;
    
    list_insert(&head, new_data = 43);
    list_insert(&head, new_data = 6);
    list_insert(&head, new_data = 12);
    list_insert(&head, new_data = 22);
    list_insert(&head, new_data = 98);

    // Ricerca nodo
    nodoCercato = 22;
    if (list_search(&head, nodoCercato) == 1)
        printf("trovato!\n");
    else
        printf("Non trovato :(\n");
    printList(head);
}

void    printList(struct node *p)
{
    while (p != NULL)
    {
        if (p->next != NULL)
            printf(" %d ->", p->data);
        else
            printf("%d\n", p->data);
        p = p->next;
    }
}

void list_insert(struct node **head, int new_data) 
{
    // Alloco la memoria necessaria per il nuovo nodo
    struct node *nuovo = (struct node *)malloc(sizeof(struct node));
    if (nuovo == NULL)
    {
        printf("Errore nell'allocazione della memoria");
        exit(0);
    }

    nuovo->data = new_data;
    nuovo->next = (*head);
    (*head) = nuovo; 
}

int list_search(struct node **head, int cercato)
{
    struct node *corrente = *head;

    while (corrente != NULL)
    {
        if (corrente->data == cercato)
        {
            return (1);
        }
        corrente = corrente->next;
    }
    return(0); 
}


void list_delete(struct node** head, int key){
  struct node *tmp = *head;
  struct node *prev = NULL;

  // Sto eliminando la testa
  if (tmp != NULL && tmp->data == key) {
    *head = tmp->next; // Cambio testa della lista
    free(tmp);
    return;
  }
 
  // Ricerco il nodo da eliminare, tenendo traccia del precedente (per poter modificare prev->next)
  while (tmp != NULL && tmp->data != key) {
    prev = tmp;
    tmp = tmp->next;
  }
 
  // Nessun nodo ha come "dato" la "chiave"
  if (tmp == NULL)
    return;
 
  // Modifico il next del nodo precedente a quello eliminato
  prev->next = tmp->next;
 
  free(tmp);
}
