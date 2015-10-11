/*
 * fifo_context.c
 *
 *  Created on: 16 dec. 2012
 *      Author: Hugo
 */

#include <stdio.h>
#include <stdlib.h>

#include "fifo_context.h"



void fifo_savenextline(Fifo_linecontext **p_file, FILE * file,unsigned int max_size)
{
	Fifo_linecontext *p_nouveau = malloc(sizeof *p_nouveau);
    if (p_nouveau != NULL)
    {
        p_nouveau->next = NULL;
        p_nouveau->data = malloc(sizeof (fpos_t));
        fgetpos(file,p_nouveau->data);
        if (*p_file == NULL)
        {
            *p_file = p_nouveau;
        }
        else
        {
        	unsigned int size=1;
        	Fifo_linecontext *p_tmp = *p_file;
            while (p_tmp->next != NULL)
            {
            	size++;
                p_tmp = p_tmp->next;
            }
            p_tmp->next = p_nouveau;
            if(size > max_size){
            	fifo_deletefirst(p_file);
            }

        }
    }
}

Fifo_linecontext* fifo_deletefirst(Fifo_linecontext **p_file)
{
    /* On teste si la file n'est pas vide. */
    if (*p_file != NULL)
    {
        /* Creation d'un element temporaire pointant vers le deuxieme element de la file. */
    	Fifo_linecontext *p_tmp = (*p_file)->next;
        /* Free the data */
        free((*p_file)->data),(*p_file)->data = NULL;
        /* Effacement du premier element. */
        free(*p_file), *p_file = NULL;
        /* On fait pointer la file vers le deuxieme element. */
        *p_file = p_tmp;
    }
    return *p_file;
}

void fifo_clear(Fifo_linecontext **p_file)
{
    /* Tant que la file n'est pas vide. */
    while (*p_file != NULL)
    {
        /* On enleve l'element courant. */
    	fifo_deletefirst(p_file);
    }
}
