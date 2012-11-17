#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
	
    FILE* fichier = NULL;
    fichier = fopen(argv[2], "r");
    int TAILLE_MAX = 1000;
     char chaine[TAILLE_MAX];
     char *ptr; 
    
    if (fichier != NULL)
    {
        // On peut lire et écrire dans le fichier
        
       while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
       
        {
        	//fgets(chaine, TAILLE_MAX, fichier);
        	  ptr = strstr(chaine, argv[1]);
        	  if(ptr!=NULL)
        	  printf("%s",chaine);
     
        
        		
        	
           // printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
        }
 
        fclose(fichier);
      //  printf("%s",argv[1]);
    }
    else
    {
        // On affiche 1 message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }
}	
