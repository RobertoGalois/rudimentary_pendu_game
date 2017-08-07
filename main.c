#include	<stdio.h>
#include	"show.h"
#include	"game.h"

int		main(void)
{
		show_welcome();
		do
		{
			game();
		} while (game_check_continue());

		return (0);
}
