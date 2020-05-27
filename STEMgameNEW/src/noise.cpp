#include "noise.h"


int perlinNoise::floor(double x) { return(x > 0 ? (int)x : (int)x - 1); };
double perlinNoise::mix(double x, double y, double t) { return((1 - t)*x + t * y); };
double perlinNoise::fadeFunction(double x) { return(x*x*x*(x*(x * 6 - 15) + 10)); };
double perlinNoise::dotProduct(int x1, int y1, double x2, double y2) { return((x1*x2) + (y1 * y2)); };


double perlinNoise::getValue(double x, double y) {
	{
		//finds which cell the point occupies
		int VectorCoordinateX = floor(x);
		int VectorCoordinateY = floor(y);

		//calculates the position of the point in the cell
		double PixelCoordinateX = x - (double)VectorCoordinateX;
		double PixelCoordinateY = y - (double)VectorCoordinateY;

		//caps the cells to a certain value
		VectorCoordinateX = VectorCoordinateX & 255;
		VectorCoordinateY = VectorCoordinateY & 255;

		int VectorIndexes[4];
		double DotProducts[4];

		//uses the permutation table to get the index of the surrounding vectors in the possible vectors array
		VectorIndexes[0] = PermutationTable[(VectorCoordinateX + PermutationTable[VectorCoordinateY]) & 255] % 8;
		VectorIndexes[1] = PermutationTable[(VectorCoordinateX + PermutationTable[(VectorCoordinateY + 1) & 255]) & 255] % 8;
		VectorIndexes[2] = PermutationTable[(VectorCoordinateX + 1 + PermutationTable[VectorCoordinateY]) & 255] % 8;
		VectorIndexes[3] = PermutationTable[(VectorCoordinateX + 1 + PermutationTable[(VectorCoordinateY + 1) & 255]) & 255] % 8;

		//finds how much each vector will influence the value
		DotProducts[0] = dotProduct(Vectors[VectorIndexes[0]][0], Vectors[VectorIndexes[0]][1], PixelCoordinateX, PixelCoordinateY);
		DotProducts[1] = dotProduct(Vectors[VectorIndexes[2]][0], Vectors[VectorIndexes[2]][1], PixelCoordinateX - 1, PixelCoordinateY);
		DotProducts[2] = dotProduct(Vectors[VectorIndexes[1]][0], Vectors[VectorIndexes[1]][1], PixelCoordinateX, PixelCoordinateY - 1);
		DotProducts[3] = dotProduct(Vectors[VectorIndexes[3]][0], Vectors[VectorIndexes[3]][1], PixelCoordinateX - 1, PixelCoordinateY - 1);

		double FadedX = fadeFunction(PixelCoordinateX);
		double FadedY = fadeFunction(PixelCoordinateY);

		//interpolates the values
		double Interpolation1 = mix(DotProducts[0], DotProducts[1], FadedX);
		double Interpolation2 = mix(DotProducts[2], DotProducts[3], FadedX);

		double Interpolation3 = mix(Interpolation1, Interpolation2, FadedY);

		return((Interpolation3 + 1.0) / 2.0);
	};
};