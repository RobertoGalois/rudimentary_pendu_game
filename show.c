#include	<stdio.h>
#include	"show.h"
#include	"system.h"

void	show_welcome(void)
{
		printf("Bienvenue dans le jeu du pendu!\n");
}

void	show_try(signed short* p_player_tries, char* p_showed_secret_word, char* p_choice_letter)
{
		printf("\n");
		printf("Vous avez encore droit a %hd erreurs \n", *p_player_tries);
		printf("Quel est le mot secret ? ");
		printf("%s\n", p_showed_secret_word);
		printf("Proposez une lettre: ");
		*p_choice_letter = getchar();
		system_clear_buffer();
}
