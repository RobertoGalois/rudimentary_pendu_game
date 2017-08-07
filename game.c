#include	<stdio.h>
#include	"system.h"
#include	"show.h"

void	game_check_win_loose(signed short p_nb_found_letters, signed short p_secret_word_length, char* p_secret_word)
{
		if (p_nb_found_letters == p_secret_word_length)
		{
			printf("BRAVO ! Vous avez trouve !\n");
			printf("Le mot secret etait %s !\n", p_secret_word);
		}
		else
			printf("PERDU ! Le mot secret etait %s !\n", p_secret_word);
}

void	game(void)
{	
		signed short	nb_tries;				/* limit tries */
		signed short	player_tries;			/* tries used by the player */
		char*			secret_word = "chatelet";
		signed short	secret_word_length;
		char			showed_secret_word[] = "********";
		signed short	nb_found_letters;
		char			choice_letter;
		signed short	founded_letter;

		nb_tries = 10;
		player_tries = nb_tries;
		secret_word_length = 8;
		nb_found_letters = 0;

		while ((nb_found_letters < secret_word_length) && (player_tries > 0))
		{
			show_try(&player_tries, showed_secret_word, &choice_letter);
			founded_letter = 0;
			for (signed short i = 0; secret_word[i] != '\0'; i++)
			{
				if (secret_word[i] == choice_letter 
					&& showed_secret_word[i] != choice_letter)
				{
					showed_secret_word[i] = choice_letter;
					nb_found_letters++;
					founded_letter = 1;
				}
			}

			if (founded_letter == 0)
				player_tries--;
		}

		game_check_win_loose(nb_found_letters, secret_word_length, secret_word);
}

signed short game_check_continue(void)
{
	char c;

	printf("\nRefaire une partie ? o/n: ");
	c = getchar();
	system_clear_buffer();
	printf("\n");

	if (c == 'o')
		return 1;
	else
		return 0;
}
