#include <stdlib.h>
#include "chunk.h"

void chunk_init(Chunk *chunk, int x, int y, int z)
{
}
void chunk_create_blockMap(Chunk *chunk)
{
	for (int x = 0; x < CHUNK_MAX_SIZE; x++)
	{
		for (int z = 0; z < CHUNK_MAX_SIZE; z++)
		{
			chunk->blockMap[0][x][z] = 0;
		}
	}
}
void chunk_create_vertices(Chunk *chunk, cubeCalculation *cc)
{
	chunk->vertices = (int *)malloc(sizeof(int) * CHUNK_MAX_SIZE * CHUNK_MAX_SIZE * 4);
	unsigned int pos = 0;
	for (int x = 0; x < CHUNK_MAX_SIZE; x++)
	{
		for (int z = 0; z < CHUNK_MAX_SIZE; z++)
		{
			cube_set_pos(cc, x, 0, z);
			//cube_console_print(cc->ptr);
			for (int i = 0; i < 12; i++)
			{
				chunk->vertices[pos] = *cc->ptr[i];
				pos++;
			}
		}
	}
}