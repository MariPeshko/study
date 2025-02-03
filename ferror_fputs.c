/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ferror_fputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:07:34 by mpeshko           #+#    #+#             */
/*   Updated: 2024/12/16 19:11:40 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// tutorialspoint.com

#include <stdio.h>

#include <stdio.h>

int main() {
   FILE *file = fopen("example3.txt", "w");
   if (file == NULL) {
       perror("Error opening file");
       return 1;
   }

   fputs("Hello, World!", file);

   if (ferror(file)) {
       printf("An error occurred while writing to the file.\n");
   } else {
       printf("Writing to the file was successful.\n");
   }

   fclose(file);
   return 0;
}

// int main() {
//    FILE *file = fopen("example3.txt", "w");
//    if (file == NULL) {
//        perror("Error opening file");
//        return 1;
//    }

//    fputs("This is a test.", file);

//    fclose(file);

//    // Attempt to write to the closed file
//    fputs("This will cause an error.", file);

//    if (ferror(file)) {
//        printf("An error occurred because the file was already closed.\n");
//    } else {
//        printf("Writing to the file was successful.\n");
//    }

//    return 0;
// }