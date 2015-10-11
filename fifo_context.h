/*
 * fifo_context.h
 *
 *  Created on: 16 dec. 2012
 *      Author: Hugo
 */

#ifndef FIFO_CONTEXT_H_
#define FIFO_CONTEXT_H_

typedef struct fifo_linecontext
{
	fpos_t *data;
    struct fifo_linecontext *next;
} Fifo_linecontext;

void fifo_savenextline(Fifo_linecontext **p_file, FILE * file,unsigned int max_size);

Fifo_linecontext* fifo_deletefirst(Fifo_linecontext **p_file);

void fifo_clear(Fifo_linecontext **p_file);


#endif /* FIFO_CONTEXT_H_ */
