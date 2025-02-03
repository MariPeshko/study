/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fscanf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:16:00 by mpeshko           #+#    #+#             */
/*   Updated: 2024/12/16 19:18:08 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>

// fscanf input format conversion
// fcanf() reads input from the stream pointer FILE *stream

int main(void)
{
    FILE *fp;
    char name[1024];  // Big enough for any line this program will encounter
    float length;
    int mass;

    fp = fopen("whales.txt", "r");

    while (fscanf(fp, "%s %f %d", name, &length, &mass) != EOF)
        printf("%s whale, %d tonnes, %.1f meters\n", name, mass, length);

    fclose(fp);
}