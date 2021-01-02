/***********************************************************************************************
 * @file main.c
 * @author MATTHEY-VINTAR Alexis (28605054 - DM Meca/EEA), PETARD Adrien (3809346 - DM Meca/EEA)
 * @brief 
 * @version 1.0
 * @date 14-12-2020;
 * 
 * @copyright Copyright (c) 2020;
 * 
*************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "safeinput.h"
#include "partie.h"
#include "SaveAndSettings.h"

int main()
{
	int settingsChoice = 6;
    puiss4 partie ;
	while( 1 )
	{
        system("clear");

        int choix_menu = menu_principal();

		switch( choix_menu )
        {
			case 0:
				puts("Merci et au revoir !");
				return EXIT_SUCCESS;

			case 1:
                system("clear"); //Le programme est destine a etre utilise sur linux, donc on peut utiliser cette commande

				couleur( ROUGE );
				printf( "Regles du jeu: \n\n" );
				couleur( RESET );
				printf("Le but du jeu est d'aligner une suite de 4 pions de meme couleur sur une grille\n"\
						"comptant 6 rangees et 7 colonnes ( reglables dans le mode libre ). Chaque joueur dispose de 21 pions, soit des croix soit des ronds.\n"\
						"Tour a tour, les deux joueurs placent un pion dans la colonne de leur choix, le pion coulisse alors\n"\
						"jusqu'a la position la plus basse possible dans la dite colonne à la suite de quoi c'est à l'adversaire de jouer.\n"\
						"Le vainqueur est le joueur qui realise le premier un alignement (horizontal, vertical ou diagonal) consecutif d'au moins quatre pions.\n"\
						"Si, alors que toutes les cases de la grille de jeu sont remplies, aucun des deux joueurs n'a realise un tel alignement, la partie est declaree nulle.\n\n"\
                        "Appuyer sur la touche 'entrer' pour continuer...");
                flushbuff();
				break;
				
			case 2:		
				system("clear");

				set_default_settings();

				player_name_change();

                system("clear");

    			initialisation( &partie );
				
				affiche_jeu( partie );

    			for( tour = 0; tour < (nbCol*nbLignes); tour++ )
    			{        
                    
        			ajoute_pion( &partie, ( (tour) % 2 ) );

					if( partie.resetPartie )
					{	
						system("clear");
						affiche_jeu( partie );
						ajoute_pion( &partie, tour%2 );
						partie.resetPartie = 0;
					}

					if ( partie.quitPartie ) break; // Check si l'option 'quitter' du menu pause a ete choisi
                    
                    system("clear");
        			affiche_jeu( partie );

                    if ( gagne( partie, tour % 2) )
					{	
						if ( tour % 2 ) printf("\n%s a gagne !", nomJoueurDeux);
						else printf ("\n%s a gagne !", nomJoueurUn);
						printf("\n\nAppuyer sur entree pour continuer...");
						flushbuff();
						break;
					}
    			}
    			break;
				
			case 5:

				while( settingsChoice != 5)
				{	
					system("clear");
					settingsChoice = settings_menu();
					settings( settingsChoice );
				}

				system("clear");

    			initialisation( &partie );
				
				affiche_jeu( partie );

    			for( tour = 0; tour < (nbCol*nbLignes); tour++ )
    			{        
                    
        			ajoute_pion( &partie, ( (tour) % 2 ) );

					if( partie.resetPartie )
					{
						system("clear");
						affiche_jeu( partie );
						ajoute_pion( &partie, tour%2 );
						partie.resetPartie = 0;
					}

					if ( partie.quitPartie ) break;
                    
                    system("clear");
        			affiche_jeu( partie );

                    if ( gagne( partie, tour % 2) )
					{	
						if ( tour % 2 ) printf("\n%s a gagne !", nomJoueurDeux);
						else printf ("\n%s a gagne !", nomJoueurUn);
						printf("\n\nAppuyer sur entree pour continuer...");
						flushbuff();
						break;
					}
    			}

                break;

				
         	default:
            	exit( EXIT_FAILURE );
		}
	}
	return EXIT_SUCCESS;
}