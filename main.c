#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int str_search(char *string, char *pattern, int startIndex) {
    int res=-1;
    int lgtS=strlen(string), lgtP=strlen(pattern), i=0;

    if (startIndex>=0 && startIndex<lgtS) {
        for (i=startIndex; i<lgtS; i++) {
            int j=0;
            for (j=0; j<lgtP; j++) {
                if (pattern[j]!=string[i+j]) {
                    j=-1;
                    break;
                }
            }
            if (j>=0) {
                res=i;
                break;
            }
        }
    }

    return res;
}

short fileExists(char* path) {
    short res=0;
    FILE* my_file = NULL;
    res = (NULL != (my_file = fopen(path,"r")));
    fclose(my_file);
    return res;
}



int main(int argc, char** argv) {
    /*
    if (argc < 3)
    {
        printf("Nombre de parametres insuffisants\n");
        return 1;
    }

    char* Pattern=argv[1];
    char* Filepath=argv[2];

    int PatternLGT=strlen(Pattern);
    int FilepathLGT=strlen(Filepath);
    printf("%d %d\n", PatternLGT, FilepathLGT);
    */

    char* Pattern="test";
    char* Filepath1="test.txt";

    if (fileExists(Filepath1)) {
        FILE* FileToSearch1=NULL;
        FileToSearch1 = fopen(Filepath1, "r");

        fseek(FileToSearch1, 0L, SEEK_END);
        long filelength = ftell(FileToSearch1);
        rewind(FileToSearch1);



        int i=0;
        char* content=NULL;
        content = malloc(filelength+1 * sizeof(char*));
        for (i=0; i<filelength; i++) {
            content[i]=0;
        }
        i=0;

        char c;
        c=fgetc(FileToSearch1);
        while (c != EOF) {
            content[i]=c;
            i++;
            c = fgetc(FileToSearch1);
        }

        printf("%s\n\n", content);

        int index=str_search(content, Pattern, 0);
        while (index>-1) {
            printf("Resultat de la recherche '%s' : %d\n", Pattern, index);
            index=str_search(content, Pattern, index+1);
        }

    } else {
        printf("%s: Aucun fichier ou dossier de ce type", Filepath1);
    }



    printf("\n\n");
    system("pause");
    return 0;
}
