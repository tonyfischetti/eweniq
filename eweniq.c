/* eweniq - filters unsorted duplicated lines
   Copyright (C) 2015-2019, 2004 Tony Fischetti and the FSF

   This uses libavl by Ben Pfaff (also under GPL)

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
   See the GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
   02111-1307, USA.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "avl.h"


char *line = NULL;
size_t length = 0u;
ssize_t n;

int item_compare(const void* first, const void* second, void* param){
    char* f_d = (char*)(first);
    char* s_d = (char*)(second);
    return strcmp(f_d, s_d);
}
int (*cmp_fn)(const void*, const void*, void*) = &item_compare;


int main(void){
    struct avl_table* table = avl_create(cmp_fn, NULL, NULL);

    while((n = getline(&line, &length, stdin)) >= 0){
        char* the_string = malloc(n * sizeof(char) + 1);
        strcpy(the_string, line);
        the_string[n-1] = '\0';
        if(n < 2){
            printf("\n");
        }
        else{
            if(avl_insert(table, (void*)(the_string)) == NULL){
                printf("%s", line);
                fflush(stdout);
            }
        }
    }
    free(line);
    return 0;
}
