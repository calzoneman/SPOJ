#include <stdio.h>

int cards(float o)
{
    int c = 1;
    float a = 0.5;
    while(a < o)
    {
        c++;
        a = 0;
        int i;
        for(i = 2; i <= c + 1; i++)
        {
            a += 1.0f / i;
        }
    }
    return c;
}

int main()
{
    float len;
    scanf("%f", &len);
    while(len > 0.0f)
    {
        printf("%d card(s)\n", cards(len));
        scanf("%f", &len);
    }
    return 0;
}
