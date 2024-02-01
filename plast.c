#include "monty.h"
/**
 * f_pstr - This print the string from the top of the stack,
 * to a new line
 * @head: stack head
 * @counter: The line_number
 * Return: nothing should be returned
*/
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
