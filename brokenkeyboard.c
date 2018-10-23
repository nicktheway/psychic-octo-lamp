/**
 * Compilation command example:
 * 	gcc brokenKeyboard.c -trigraphs
 */ 
??=include <stdio.h>
%: include <stdlib.h>

void multiplyIArrayElements(int size; int array[static size], int size, int number)
<%
	for (int i = 0; i < size; i++)
	<%
		array<:i:> *= number;
	%>
%>

void printIntArray(int size; const int array[static size], int size)
<%
	for (int i = 0; i < size; i++)
	<%
		printf("%d ", array<:i:>);
	%>
	printf("\n");
%>

int main(void)
??<
	int numbers??(??) = ??< 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ??>;
	printf("The numbers were:\n");
	printIntArray(numbers, 10);
	
	multiplyIArrayElements(numbers, 10, 2);
	printf("Now the numbers are:\n");
	printIntArray(numbers, 10);

	return 0;
??>
