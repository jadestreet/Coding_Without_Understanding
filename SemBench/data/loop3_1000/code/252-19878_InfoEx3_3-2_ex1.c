#include <stdio.h>
#define N 2
int main()
{
    double train_x[4][3] = {{0, 0, 0}, {0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
    double v1[2][3] = {{0.8, 1.0, -0.3}, {1.3, 0.6, -1.5}};
    double v2[2][3] = {{-6.0, 3.0, 1.5}, {-0.3, -1.2, 0.4}};
    double w[3] = {1.1, -1.2, -0.5};
    double z[4][2];
    double y[4];
    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j != 2)
                {
                    z[i][k] += v1[k][j] * train_x[i][j];
                }
                else
                {
                    z[i][k] += v1[k][j];
                    if (z[i][k] >= 0)
                    {
                        z[i][k] = 1.0;
                    }
                    else
                    {
                        z[i][k] = 0.0;
                    }
                    printf("%d.z%d = %f\n", i + 1, k + 1, z[i][k]);
                }
            }
        }
    }
    for (int j = 0; j < 4; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (k != 2)
            {
                y[j] += w[k] * z[j][k];
            }
            else
            {
                y[j] += w[k];
                if (y[j] >= 0)
                {
                    y[j] = 1;
                }
                else
                {
                    y[j] = 0;
                }
                printf("y%d = %f\n", j + 1, y[j]);
            }
        }
    }
    return 0;
}