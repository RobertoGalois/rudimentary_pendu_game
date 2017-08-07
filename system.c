#include	<stdio.h>

void	system_clear_buffer(void)
{
		int c;
		while((c=getchar()) != EOF && c != '\n');
}