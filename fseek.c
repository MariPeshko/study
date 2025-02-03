/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fseek.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:13:38 by mpeshko           #+#    #+#             */
/*   Updated: 2024/12/16 19:15:36 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// tutorialspoint

#include <stdio.h>

int main() {
   FILE *file = fopen("example1.txt", "r");
   if (file == NULL) {
       perror("Error opening file");
       return 1;
   }
   
   char ch = fgetc(file);
   if (ch != EOF) {
       printf("First character in the file: %c\n", ch);
   }
   
   fseek(file, 0, SEEK_SET);

   ch = fgetc(file);
   if (ch != EOF) {
       printf("First character in the file: %c\n", ch);
   }

   fclose(file);
   return 0;
}