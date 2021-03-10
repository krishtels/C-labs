  
#ifndef MAIN_H
#define MAIN_H

void PasteParameters(int** planets, int planetNumber);
float CalculateYearLength(int** planets, int planetNumber);
float CalculateDistance(int planet1, int planet2, int time, int** planets);
float CalculatePower(int planet1, int planet2, int time, int** planets);
float YearLength(int radius, int speed);
float Distance(int time, int radius1, int speed1, int radius2, int speed2);
float Power(int mass1, float distance, int mass2);
void FreeMatrix(int** matrix);

#endif