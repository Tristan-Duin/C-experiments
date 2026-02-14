	#include <stdio.h>

	int main() {
		int grades[2][5][2];
		float average;
		int i;
		int j;
        int k;

		grades[0][0][0] = 80;
		grades[0][1][0] = 70;
		grades[0][2][0] = 65;
		grades[0][3][0] = 89;
		grades[0][4][0] = 90;

		grades[1][0][0] = 85;
		grades[1][1][0] = 80;
		grades[1][2][0] = 80;
		grades[1][3][0] = 82;
		grades[1][4][0] = 87;

        grades[0][0][1] = 80;
		grades[0][1][1] = 70;
		grades[0][2][1] = 65;
		grades[0][3][1] = 89;
		grades[0][4][1] = 90;

		grades[1][0][1] = 52;
		grades[1][1][1] = 99;
		grades[1][2][1] = 66;
		grades[1][3][1] = 53;
		grades[1][4][1] = 24;

		for (i = 0; i < 2; i++) {
			average = 0;
			for (j = 0; j < 5; j++) {
                for (k = 0; k < 2; k++){
                    average += grades[i][j][k];
                }
			}

			average /= 10.0;
			printf("The average marks obtained in subject %d is: %.2f\n", i, average);
		}

		return 0;
	}