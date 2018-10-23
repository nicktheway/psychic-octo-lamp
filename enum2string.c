#include <stdio.h>
#include <stdlib.h>

/* declare items of the enum */
#define ITEMS \
X(apple) \
X(pineapple) \
X(pen) \
/* end of list */

/**
 * define the enum 
 */
#define X(id) EI_ ## id,
enum EItem { ITEMS };
#undef X

/**
 * define the toString function for the enum. 
 */
const char* EItem2string(int enumValue)
{
	const char* stringValue = 0;
	#define X(id) if (enumValue == EI_ ## id) stringValue = #id;
	ITEMS
	#undef X
	return stringValue;
}
#undef ITEMS

int main(void)
{
	enum EItem myItem = EI_apple;
	printf("myItem is a/an %s.\n", EItem2string(myItem));
	
	myItem = EI_pineapple;
	printf("myItem is now a/an %s.\n", EItem2string(myItem));

	myItem = EI_pen;
	printf("myItem is now a/an %s.\n", EItem2string(myItem));	

	return EXIT_SUCCESS;
}

