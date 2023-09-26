// RiosRodriguezDaniel 372800
// 11-sep-23
/*
PARTE 1
1.- Leer una cadena y desplegarla de la siguiente manera
(Realizar una funcién para cada salida)
*/
// R.R.D_act6_2_932
#include <stdio.h>
#include <string.h>
char *validarletras(char mensaje[], char cadena[]);
int validarnumero(char mensaje[], int ri, int rf);
void salida1(char mensaje[]);
void salida2(char mensaje[]);
void salida3(char mensaje[]);
void salida4(char mensaje[]);
void salida5(char mensaje[]);
void salida6(char mensaje[]);
void salida7(char mensaje[]);
void salida8(char mensaje[]);
void salida9(char mensaje[]);
void salida10(char mensaje[]);

int main()
{
    char cadena[30];
    int salida;
    validarletras("Escriba algo\n",cadena);
    salida = validarnumero("Que numero de salida quieres? \n1.Mayuscula\n2.Al reves\n3.Letra por letra\n4.Letra por letra y alreves\n5.Columna\n6.Columna al reves\n7.Columna y eliminar la primera letra\n8.Columan al reves y eliminar la primera letra\n9.Eliminar Vocales\n10.Eliminar Consonantes\n", 1, 10);
    switch (salida)
    {
    case 1:
        printf("%s",cadena);
        break;
    case 2:
        salida2(cadena);
        break;
    case 3:
        salida3(cadena);
        break;
    case 4:
        salida4(cadena);
        break;
    case 5:
        salida5(cadena);
        break;
    case 6:
        salida6(cadena);
        break;
    case 7:
        salida7(cadena);
        break;
    case 8:
        salida8(cadena);
        break;
    case 9:
        salida9(cadena);
        break;
    case 10:
        salida10(cadena);
        break;
    default:
        printf("NO SE ENCONTRO RESULTADO\n");
        break;
    }
    return 0;
}
char *validarletras(char mensaje[], char cadena[])
{
    int x, i, salida;
    printf("%s", mensaje);
    do
    {
        salida = 0;
        fgets(cadena, 256, stdin);
        cadena[strcspn(cadena, "\n")] = 0;
        x = strlen(cadena);
        for (i = 0; i < x; i++)
        {
            if (cadena[i] == ' ' && cadena[i + 1] == ' ')
            {
                printf("HAY DOBLE ESPACIO\n");
                salida = 1;
                break;
            }
            if (cadena[i] >= '0' && cadena[i] <= '9')
            {
                printf("HAY NUMEROS\n");
                salida = 1;
                break;
            }
        }
    } while (salida == 1);
    for (i = 0; i < x; i++)
    {
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            cadena[i] = cadena[i] - 32;
        }
    }
    return cadena;
}
int validarnumero(char mensaje[], int ri, int rf)
{
    char calificacion[100];
    int num;
    do
    {
        printf("%s ", mensaje);
        fflush(stdin);
        gets(calificacion);
        num = atoi(calificacion);
        if (num < ri || num > rf)
        {
            printf("INGRESE EL NUMERO OTRA VEZ PORFAVOR\n");
        }
    } while (num < ri || num > rf);
    return num;
}

void salida2(char mensaje[])
{
    int i, x;

    x = strlen(mensaje);
    for (i = x; i >= 0; i--)
    {
        printf("%c", mensaje[i]);
    }
}
void salida3(char mensaje[])
{
    int i, x;
    printf("SALIDA 3\n");
    x = strlen(mensaje);
    for (i = 0; i < x; i++)
    {
        printf("%c\n", mensaje[i]);
    }
}
void salida4(char mensaje[])
{
    int i, x;
    printf("SALIDA 4");
    x = strlen(mensaje);
    for (i = x; i >= 0; i--)
    {
        printf("%c\n", mensaje[i]);
    }
}
void salida5(char mensaje[])
{
    int i, j, x;
    printf("SALIDA 5\n");
    x = strlen(mensaje);
    for (j = x; j > 0; j--)
    {
        for (i = 0; i < j; i++)
        {
            printf("%c", mensaje[i]);
        }
        printf("\n");
    }
}
void salida6(char mensaje[])
{
    int i, j, x;
    printf("SALIDA 6\n");
    x = strlen(mensaje);
    for (j = 0; j < x; j++)
    {
        for (i = x; i >= j; i--)
        {
            printf("%c", mensaje[i]);
        }
        printf("\n");
    }
}
void salida7(char mensaje[])
{
    int i, j, x;
    printf("SALIDA 7\n");
    x = strlen(mensaje);
    x = x - 1;
    for (j = 0; j <= x; j++)
    {
        for (i = j; i <= x; i++)
        {
            printf("%c", mensaje[i]);
        }
        printf("\n");
    }
}
void salida8(char mensaje[])
{
    int i, j, x;
    printf("SALIDA 8\n");
    x = strlen(mensaje);
    x = x - 1;
    for (j = x; j >= 0; j--)
    {
        for (i = j; i >= 0; i--)
        {
            printf("%c", mensaje[i]);
        }
        printf("\n");
    }
}
void salida9(char mensaje[])
{
    char vocales[] = "aeiouAEIOU";
    int i, x, j;
    printf("SALIDA 9\n");
    x = strlen(mensaje);
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (mensaje[i] == vocales[j])
            {
                mensaje[i] = ' ';
            }
        }
        printf("%c", mensaje[i]);
    }
    printf("\n");
}
void salida10(char mensaje[])
{
    char vocales[] = "aeiouAEIOU";
    int i, x, j, vocal;
    printf("SALIDA 10\n");
    x = strlen(mensaje);
    for (i = 0; i < x; i++)
    {
        vocal = 0;
        for (j = 0; j < 10; j++)
        {
            if (mensaje[i] == vocales[j])
            {
                vocal = 1;
                break;
            }
        }
        if (vocal == 0)
        {
            mensaje[i] = ' ';
        }
        printf("%c", mensaje[i]);
    }
}
