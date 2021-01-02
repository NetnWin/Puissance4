/***********************************************************************************************
 * @file SaveAndSettings.h
 * @author MATTHEY-VINTAR Alexis (28605054 - DM Meca/EEA), PETARD Adrien (3809346 - DM Meca/EEA)
 * @brief 
 * @version 0.1
 * @date 22 - 12 - 2020
 * 
 * @copyright Copyright (c) 2020
 * 
 ************************************************************************************************/

#ifndef SAVEANDSETTINGS_H
#define SAVEANDSETTINGS_H

#include "partie.h"


#define NB_LIGNE_MAX 20
#define NB_COL_MAX 20
#define NB_LIGNE_MIN 3
#define NB_COL_MIN 3

#define NB_PIONS_WIN_MIN 3

#define NOM_J1_DEFAUT "Joueur1"
#define NOM_J2_DEFAUT "Joueur2"

#define NB_LIGNE_DEFAUT 6
#define NB_COL_DEFAUT 7
#define NB_PIONS_WIN_DEFAULT 4

#define PLAYER_NAME_SIZE 15

#define SAVE_SLOT_ONE "savefiles/save1.SAV"
#define SAVE_SLOT_TWO "savefiles/save2.SAV"
#define SAVE_SLOT_THREE "savefiles/save3.SAV"

#include "puiss4struct.h"

// Definition variables globales

extern int nbCol;
extern int nbLignes;
extern int nbPionsGagnant;
extern int tour;
extern char nomJoueurUn[PLAYER_NAME_SIZE], nomJoueurDeux[PLAYER_NAME_SIZE];

// Definition fonctions

/**
 * @brief permet a l'utilisateur de confirmer sa reponse. Renvoie 1 si l'utilisateur a bien confirme, 0 sinon.
 * 
 * @return int 
 */
int confirm_answer();



/**
 * @brief Renvoie le plus petit nombre entre a et b.
 * 
 * @param a un entier quelconque
 * @param b un entier quelconque
 * @return int 
 */
int min(int a, int b);

struct tm get_date();

/**
 * @brief Permet aux utilisateurs d'entrer leurs prenoms dans les variables globales nomJoueurUn et nomJoueurDeux.
 * 
 */
void player_name_change();

/**
 * @brief Affiche de menu des reglages d'une partie libre et renvoie le nombre correspondant a ce que l'utilisateur a choisi 
 * 
 * @return int 
 */
int settings_menu();

/**
 * @brief effectue l'action demandee par l'utilisateur dans le menu des reglages de partie libre
 * * note : Modifie les variables globales
 * 
 * @param settingsChoice is the value that the user chose in settings_menu()
 */
void settings( int settingsChoice);

/**
 * @brief Set the default settings for the game
 * * note : Modifies the global variables
 * 
 */
void set_default_settings();

/**
 * @brief Display the details of the chosen savefile
 * 
 * @param saveNumber selects the savefile number (from 1 to 3)
 */
void savefile_display(int saveNumber);

int savefile_menu();

int write_savefile(FILE *destFile, puiss4 savedGame);

int overwrite_file(const char *fileName, puiss4 currentGame);

/**
 * @brief selectionne la sauvegarde que l'utilisateur a choisi pour pour pouvoir sauvegarder ou non. Renvoie 1 si une sauvegarde a ete effectuee, renvoie 0 sinon.
 * 
 * @param game 
 * @param saveSlot
 * @return int 
 */
int save(puiss4 game, int saveSlot);

#endif