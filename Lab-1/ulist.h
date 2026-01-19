#include <stdio.h>
#define CAP 1000

struct list {
	int n;
	int arr[CAP];
};

int insert(struct list *l, int element);
int deleteByElement(struct list *l, int element, int *position);
int deleteByPosition(struct list *l, int position, int *element);
int search(struct list *l, int element, int *position);
int findMin(struct list *l, int *min);
int findMax(struct list *l, int *max);
int inplaceSort(struct list *l);
int notAnInplaceSort(struct list *l, struct list *outputList);
int print(struct list *l);
void init(struct list *l);
void destroy(struct list *l);