#include <stdio.h>

int potencia(int a, int b, int *v) // a^b
{
    if(v == NULL) v = (int*) malloc(b * sizeof(int));
    if(b == 0) return 1;
    else if(b == 1) return v[b-1] = a;
    else return v[b-1] = potencia(a, b-1, v) * a; 
}

int main()
{
    int *v = NULL; // vetor que armazena os valores calculados
    int a, b;

    scanf("%d %d",&a,&b);
    printf("%d",potencia(a,b,v));
    free(v);

    return 0;
}