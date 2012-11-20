/*
 * arg_treatment.h
 *
 *  Created on: 2 nov. 2012
 *      Author: Hugo
 */

#ifndef ARG_TREATMENT_H_
#define ARG_TREATMENT_H_

struct arguments
{
   char *pattern;
   char *file_path;

   /*Options Definitions*/

   short opt_E; //--extended-regexp MOTIF est une expression regulière étendue
   short opt_F; //--fixed-regexp MOTIF est un ensemble chaînes fixes séparées par des retours chariot
   short opt_G; //--basic-regexp MOTIF est une expression régulière de base
   short opt_P; //--perl-regexp MOTIF est une expression régulière en Perl
   short opt_e; //--regexp=MOTIF utiliser MOTIF comme expression régulière
   short opt_f; //--file=FICHIER charger le MOTIF depuis ce FICHIER
   short opt_i; //--ignore-case ignorer la distinction de la casse
   short opt_w; //--word-regexp forcer la concordance du MOTIF à des mots entiers
   short opt_x; //--line-regexp forcer la concordance du MOTIF à des lignes entières
   short opt_z; //--null-data ligne de données finissant par 0 et pas par un retour chariot
   short opt_s; //--no-messages supprimer les messages d'erreur
   short opt_v; //--invert-match sélectionner les lignes sans concordance
   short opt_V; //--version afficher le nom et la version du logiciel
   short opt_help; //afficher l'aide et quitter

};

int arg_treatment(int *argc,char **argv,struct arguments *args);

#endif /* ARG_TREATMENT_H_ */
