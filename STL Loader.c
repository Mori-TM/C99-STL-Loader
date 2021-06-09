#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	unsigned char Header[80];
	unsigned int Triangles;
} Description;


typedef struct
{
	float Normal[3];
	float Vertex1[3];
	float Vertex2[3];
	float Vertex3[3];
	short int ByteCount;
} Vertex;

int main()
{
	FILE* File = fopen("Cube.stl", "rb");
	if (!File)
		return 0;
		
	Vertex* VertexArray;
	Description Desc;
	
	fread(&Desc, sizeof(Description), 1, File);
	VertexArray = malloc(Desc.Triangles * sizeof(Vertex));
	
	for (unsigned int i = 0; i < Desc.Triangles; i++)
	{
		fread(&VertexArray[i], 50, 1, File);
		printf("Normal: %f %f %f\n", VertexArray[i].Normal[0], VertexArray[i].Normal[1], VertexArray[i].Normal[2]);
		printf("Vertex1: %f %f %f\n", VertexArray[i].Vertex1[0], VertexArray[i].Vertex1[1], VertexArray[i].Vertex1[2]);
		printf("Vertex2: %f %f %f\n", VertexArray[i].Vertex2[0], VertexArray[i].Vertex2[1], VertexArray[i].Vertex2[2]);
		printf("Vertex3: %f %f %f\n", VertexArray[i].Vertex3[0], VertexArray[i].Vertex3[1], VertexArray[i].Vertex3[2]);
	}
}
