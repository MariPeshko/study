/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foef.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:51:18 by mpeshko           #+#    #+#             */
/*   Updated: 2024/12/16 17:51:59 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if 0
The C library int feof(FILE *stream) function tests the end-of-file indicator 
#endif

#include <stdio.h>

int main() {
   FILE *file = fopen("example1.txt", "r");
   if (file == NULL) {
       perror("Failed to open file");
       return 1;
   }

   while (!feof(file)) {
       char c = fgetc(file);
       if (feof(file)) break;
       putchar(c);
   }

   fclose(file);
   return 0;
}
