#include "ulist.h"

int main() {
	struct list l;
	struct list l2;
	int position, element, min, max;

	init(&l);
	init(&l2);
	printf("%d \n", insert(&l, 10));
	printf("%d \n", insert(&l, 23));
	printf("%d \n", insert(&l, 38));
	printf("%d \n", insert(&l, 17));
	printf("%d \n", insert(&l, 7));
	printf("%d \n", insert(&l, 80));
	printf("%d \n", insert(&l, 60));
	print(&l);

	printf("%d ", deleteByElement(&l, 17, &position));
	printf("%d \n", position);
	printf("%d ", deleteByPosition(&l, 0, &element));
	printf("%d \n", element);
	print(&l);
	printf("%d ", findMax(&l, &max));
	printf("%d \n", max);
	printf("%d ", findMin(&l, &min));
	printf("%d \n", min);
	
	inplaceSort(&l);
	notAnInplaceSort(&l, &l2);
	print(&l);
	print(&l2);
}
