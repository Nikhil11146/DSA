#include "ulist.h"

int insert(struct list *l, int element) {
	if ((l->n) == CAP) return 0;
    (l->arr)[(l->n)] = element;
	(l->n)++;
	return 1;
}

int search(struct list *l, int element, int *position) {
	int i = 0;
    while((l->arr)[i] != element) {
		i++;
	}
	*position = i;
}

int deleteByElement(struct list *l, int element, int *position) {
    if(search(l, element, position) == 0) return 0;
	for (int i = *position; i < (l->n)-1 ; i++)
	{
		(l->arr)[i] = (l->arr)[i+1];
	}
	(l->n)--;
	return 1;
}

int deleteByPosition(struct list *l, int position, int *element) {
    if (position >= (l->n)) return 0;
	*element = (l->arr)[position];
	for (int i = position; i < (l->n)-1 ; i++)
	{
		(l->arr)[i] = (l->arr)[i+1];
	}
	(l->n)--;
	return 1;
}

int findMin(struct list *l, int *min) {
	*min = (l->arr)[0];
    for (int i = 1; i < (l->n)-1 ; i++)
	{
		if(*min > (l->arr)[i]) *min = (l->arr)[i];
	}
	return 1;
}

int findMax(struct list *l, int *max) {
    *max = (l->arr)[0];
    for (int i = 1; i < (l->n); i++)
	{
		if(*max < (l->arr)[i]) *max = (l->arr)[i];
	}
	return 1;
}

int inplaceSort(struct list *l) {
	int temp;
	// int *array = (l->arr);
	for (int i = 0; i < (l->n)-1; i++){
		for (int j = 0; j < (l->n)-i-1; j++)
		{
			if((l->arr)[j+1] <= (l->arr)[j]){
				temp = (l->arr)[j];
				(l->arr)[j] = (l->arr)[j+1];
				(l->arr)[j+1] = temp;
			}
		}
	}		
}

int notAnInplaceSort(struct list *l, struct list *outputList) {
	for (int i = 0; i < (l->n); i++)
	{
		(outputList->arr)[i] = (l->arr)[i];
		(outputList->n)++;
	}
	int temp;
	// int *array = (l->arr);
	for (int i = 0; i < (l->n)-1; i++){
		for (int j = 0; j < (l->n)-i-1; j++)
		{
			if((l->arr)[j+1] <= (l->arr)[j]){
				temp = (l->arr)[j];
				(l->arr)[j] = (l->arr)[j+1];
				(l->arr)[j+1] = temp;
			}
		}
	}	
	
}

int print(struct list *l) {
	for (int i = 0; i < (l->n); i++)
	{
		printf("%d ", (l->arr)[i]);
	}
	printf("\n");
}

void init(struct list *l) {
	(*l).n = 0;
}

void destroy(struct list *l) {
	(*l).n = 0;
}