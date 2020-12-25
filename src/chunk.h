#include "cube.h"
#define CHUNK_MAX_SIZE 32
#ifndef CHUNK_H
#define CHUNK_H

#define CHUNK_MAX_HEIGHT 256
#define CHUNK_HEIGHT 64

typedef struct Chunk
{
	unsigned int blockMap[CHUNK_MAX_HEIGHT][CHUNK_MAX_SIZE][CHUNK_MAX_SIZE];
	int *vertices;
	vector3dInt worldPosition;
} Chunk;
void chunk_init(Chunk *chunk, int x, int y, int z);
void chunk_create_blockMap(Chunk *chunk);
void chunk_create_vertices(Chunk *chunk, cubeCalculation *cc);

#endif