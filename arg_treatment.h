/*
 * arg_treatment.h
 *
 *  Created on: 2 nov. 2012
 *      Author: Hugo
 */

#ifndef ARG_TREATMENT_H_
#define ARG_TREATMENT_H_


#ifdef __APPLE__//maybe use this __MACH__
  // Mac Mod Here
#define NULLSYSFILE "/dev/null"
#endif

#ifdef __linux__
  // Linux Mod Here
#define NULLSYSFILE "/dev/null"
#endif

#ifdef _WIN32// || _WIN64
  // Windows Mod Here
#define NULLSYSFILE "NUL"
#endif


struct arguments
{
   char *pattern;
   char **file_paths;
   size_t file_pathsc;

   /*Options Definitions*/

   short opt_E; //--extended-regexp MOTIF est une expression reguliere etendue
   short opt_F; //--fixed-regexp MOTIF est un ensemble chaines fixes separees par des retours chariot
   short opt_G; //--basic-regexp MOTIF est une expression reguliere de base
   short opt_P; //--perl-regexp MOTIF est une expression reguliere en Perl
   short opt_e; //--regexp=MOTIF utiliser MOTIF comme expression reguliere
   short opt_f; //--file=FICHIER charger le MOTIF depuis ce FICHIER
   char *opt_f_file;
   short opt_i; //--ignore-case ignorer la distinction de la casse
   short opt_w; //--word-regexp forcer la concordance du MOTIF a des mots entiers
   short opt_x; //--line-regexp forcer la concordance du MOTIF a des lignes entieres
   short opt_z; //--null-data ligne de donnees finissant par 0 et pas par un retour chariot
   short opt_s; //--no-messages supprimer les messages d'erreur
   short opt_v; //--invert-match selectionner les lignes sans concordance
   short opt_V; //--version afficher le nom et la version du logiciel
   short opt_help; //afficher l'aide et quitter

   short opt_m;//--max-count=NUM stop after NUM matches
   unsigned int opt_m_count;
   short opt_b;//--byte-offset print the byte offset with output lines
   short opt_n;//--line-number print line number with output lines
   //--line-buffered flush output on every line
   short opt_H;//--with-filename print the file name for each match
   short opt_h;//--no-filename suppress the file name prefix on output
   //--label=LABEL use LABEL as the standard input file name prefix
   short opt_o;//--only-matching affiche la partie de ligne seule concordant avec MOTIF
   short opt_q;//--quiet, --silent supprime toute la sortie standard
   //--binary-files=TYPE considere que les fichiers binaires sont de type "TYPE" : soit 'binary', soit 'text', soit 'without-match'
   short opt_a;//--text equivaut a --binary-files=text
   short opt_I;//equivaut a --binary-files=without-match
   short opt_d;//--directories=ACTION indique comment traiter les repertoires; ACTION vaut : 'read' ou 'recurse', ou 'skip'
   unsigned int opt_d_action;//1 for read, 2 for recurse, 3 for skip
   short opt_D;//--devices=ACTION indique comment traiter les peripheriques,les FIFOS, les sockets; ACTION vaut 'read' ou 'skip'
   short opt_R;//-r, --recursive equivaut a --directories=recurse
   //--include=MOTIF_FIC cherche dans les fichiers concordants avec MOTIF_FIC
   //--exclude=MOTIF_FIC ignore fichiers et rep. concordants avec MOTIF_FIC
   //--exclude-from=FIC ignore les fichiers concordants avec les motifs contenus dans FIC
   //--exclude-dir=MOTIF ignore les repertoires concordants avec MOTIF
   short opt_L;//--files-without-match affiche seulement les noms de fichiers sans concordances
   short opt_l;//--files-with-matches affiche seulement les noms de fichiers avec concordances
   short opt_c;//--count affiche seulement le compte des lignes concordantes par fichier
   short opt_T;//--initial-tab inserer des tabulations (si besoin)
   short opt_Z;//--null sort l'octet 0 apres le nom de fichier

   short opt_B;//--before-context=NUM affiche NUM lignes de contexte avant
   unsigned int opt_B_lines;//number of context line before
   short opt_A;//--after-context=NUM affiche NUM lignes de contexte apres
   unsigned int opt_A_lines;//number of context line after
   short opt_C;//--context=NUM affiche NUM lignes de contexte en sortie
   //-NUM comme --context=NUM
   //--color[=QUAND],met en evidence les concordances;
   //--colour[=QUAND] QUAND vaut "always" (toujours), "nevers" (jamais) ou "auto"
   short opt_U;//, --binary ne pas enlever les sauts de lignes a la fin (MSDOS)
   short opt_u;//, --unix-byte-offsets afficher les decalages sans tenir compte des sauts de ligne (MSDOS)


};

int arg_init(struct arguments *args);
int arg_treatment(int *argc,char **argv,struct arguments *args);
void arguments_delete(struct arguments *args);

#endif /* ARG_TREATMENT_H_ */
