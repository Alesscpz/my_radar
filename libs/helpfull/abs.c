/*
** EPITECH PROJECT, 2024
** B-MUL-100-PAR-1-1-myradar-alessandro.capozzi
** File description:
** abs.c
*/

float absolue(float nb)
{
    if (nb < 0)
        return (int)(0 - nb);
    return nb;
}
