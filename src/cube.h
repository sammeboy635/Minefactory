
typedef struct vector3dInt
{
    int x;
    int y;
    int z;
} vector3dInt;
typedef struct vector3dIntPointer
{
    int *x;
    int *y;
    int *z;
} vector3dIntPointer;
typedef struct quad
{
    vector3dInt vec3d_p1;
    vector3dInt vec3d_p2;
    vector3dInt vec3d_p3;
    vector3dInt vec3d_p4;
} quad;
typedef struct cube
{
    quad top;
    quad bottum;
    quad side_n;
    quad side_e;
    quad side_w;
    quad side_s;
} cube;
typedef struct cubeCalculation
{
    int x;
    int y;
    int z;
    int X;
    int Y;
    int Z;
    int **ptr;
} cubeCalculation;

void cube_init(cubeCalculation *cc);
void cube_set_pos(cubeCalculation *cc, int x, int y, int z);
int **cube_vertices_calc(int *x, int *y, int *z, int *X, int *Y, int *Z);
void cube_calc(cubeCalculation *cc);
void cube_console_print(int **position);
void vector3dint_print(vector3dInt positon);