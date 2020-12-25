#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cube.h"
void cube_init(cubeCalculation *cc)
{
    cc->ptr = (int **)malloc(sizeof(int *) * 72);
    cc->x = 0;
    cc->y = 0;
    cc->z = 0;
    cc->X = 1;
    cc->Y = 1;
    cc->Z = 1;
}
void cube_set_pos(cubeCalculation *cc, int x, int y, int z)
{
    cc->x = x;
    cc->y = y;
    cc->z = z;
    cc->X = x + 1;
    cc->Y = y + 1;
    cc->Z = z + 1;
}
int **cube_vertices_calc(int *x, int *y, int *z, int *X, int *Y, int *Z)
{
    int **ptr = (int **)malloc(sizeof(int *) * 72);
    int *positions[72] = {
        x, Y, Z, X, Y, Z, X, Y, z, x, Y, z,
        x, y, z, X, y, z, X, y, Z, x, y, Z,
        x, y, z, x, y, Z, x, Y, Z, x, Y, z,
        X, y, Z, X, y, z, X, Y, z, X, Y, Z,
        X, y, z, x, y, z, x, Y, z, X, Y, z,
        x, y, Z, x, y, Z, X, Y, Z, x, Y, Z};

    bcopy(positions, ptr, sizeof(positions));
    //print(positions);
    return ptr;
}
void cube_calc(cubeCalculation *cc)
{

    int *positions[72] = {
        cc->x, cc->Y, cc->Z, cc->X, cc->Y, cc->Z, cc->X, cc->Y, cc->z, cc->x, cc->Y, cc->z,
        cc->x, cc->y, cc->z, cc->X, cc->y, cc->z, cc->X, cc->y, cc->Z, cc->x, cc->y, cc->Z,
        cc->x, cc->y, cc->z, cc->x, cc->y, cc->Z, cc->x, cc->Y, cc->Z, cc->x, cc->Y, cc->z,
        cc->X, cc->y, cc->Z, cc->X, cc->y, cc->z, cc->X, cc->Y, cc->z, cc->X, cc->Y, cc->Z,
        cc->X, cc->y, cc->z, cc->x, cc->y, cc->z, cc->x, cc->Y, cc->z, cc->X, cc->Y, cc->z,
        cc->x, cc->y, cc->Z, cc->x, cc->y, cc->Z, cc->X, cc->Y, cc->Z, cc->x, cc->Y, cc->Z};

    bcopy(positions, cc->ptr, sizeof(positions));
}
void cube_console_print(int **ptr)
{
    printf("__1__|__2__|__3__|__4__|__5__|__6__|__7__|__8__|__9__|__10__|_11_|_12_|\n");
    for (int i = 1; i <= 6; i++)
    {
        for (int x = 0; x < 12; x++)
        {
            printf("  %d,  ", *ptr[(x * i)]);
        }
        printf("\n");
    }
}
void vector3dint_print(vector3dInt positon)
{
    printf("x = %d, y = %d, z = %d.\n", positon.x, positon.y, positon.z);
}