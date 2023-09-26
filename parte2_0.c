// RiosRodriguezDaniel 372800
// 11-sep-23
/*
PARTE 2
1.-Función que reciba como parámetro una cadena y la convierta a MAYUSCULAS
2.-Función Que reciba como parámetro una cadena y la convierta a MINUSCULAS
3.-Función que reciba como parámetro una cadena y la convierta a CAPITAL
4.-Función que reciba como parámetro una cadena y retorne la cantidad de caracteres que tiene la cadena.
5.-Función que reciba como parámetro una cadena y retorne una cadena con sus caracteres acomodados de forma inversa (al reves)
6.-Función que reciba como parámetro una cadena y genere una nueva cadena basada en la origina pero sin espacios.
7.-Función que sirva para leer una cadena y solo permita caracteres alfabéticos (A...Z) y el espacio, donde una cadena no puede comenzar o terminar con espacio, no debe tener dos espacios seguidos. retornar la cadena ya sea como parámetro o variable.
8.-Función que reciba como parámetro una cadena, y utilizando las funciones anteriores, imprima en MAYUSCULAS, MINUSCULAS , CAPITAL, SIN ESPACIOS, ALREVES la cadena original.
9.-Función que reciba como parámetro una cadena, y desplegar la leyenda si la cadena es un palíndromo SI o NO
 (VALIDADA AL 100% NO NUMEROS, NO DOBLES ESPACIOS Y SOLO MAYUSCULAS ENLA CADENA)
*/
// R.R.D_act7_2_932
#include <stdio.h>
#include <string.h>
int validarnumeros(char mensaje[], int ri, int rf);
char *validarletras(char mensaje[], char cadena[]);
char *minuscula(char cadena[]);
char *capital(char cadena[]);
int contador(char cadena[]);
char *rever(char cadena[]);
char *sinespacios(char cadena[]);
char *iniciofinalsinespacio(char mensaje[], char cadena[]);
void palindromo(char cadena[]);

int main()
{
    int act, cont;
    char cade[250];
    act = validarnumeros("INGRESE QUE ACTIVIDAD QUIERE HACER\n1.\n2.\n3.\n4.\n5.\n6.\n7.\n8.\n9.\n", 1, 9);
    switch (act)
    {
    case 1:
        validarletras("INGRESE LA PALABRA A PASAR A MAYUSCULAS\n", cade);
        printf("%s", cade);
        return 0;
        break;
    case 2:
        validarletras("INGRESE LA PALABRA A PASAR A MINUSCULAS\n", cade);
        minuscula(cade);
        printf("%s", cade);
        return 0;
        break;
    case 3:
        validarletras("INGRESE LA PALABRA A PASAR A CAPITAL\n", cade);
        printf("%s", capital(cade));
        return 0;
        break;
    case 4:
        validarletras("INGRESE LA PALABRA PARA VER CUANTOS CARACTERES TIENE\n", cade);
        cont = contador(cade);
        printf("%d", cont);
        return 0;
        break;
    case 5:
        validarletras("INGRESE LA PALABRA PARA PONERLA ARREVEZ\n", cade);
        printf("%s", rever(cade));
        return 0;
        break;
    case 6:
        validarletras("INGRESE LA PALABRA PARA PONERLA SIN ESPACIOS\n", cade);
        printf("%s", sinespacios(cade));
        return 0;
        break;
    case 7:
        iniciofinalsinespacio("INGRESE LA PALABRA \n", cade);
        printf("%s", cade);
        return 0;
        break;
    case 8:
        /*
         MAYUSCULAS, MINUSCULAS , CAPITAL, SIN ESPACIOS, ALREVES la cadena original.
        */
        printf("%s\n", validarletras("ESCRIBE ALGO PARA HACERLO MAYUSCULAS,CAPITAL,SIN ESPACIOS,ALREVEZ\n", cade));
        printf("%s\n", minuscula(cade));
        printf("%s\n", capital(cade));
        printf("%s\n", sinespacios(cade));
        printf("%s\n", rever(cade));
        break;
    case 9:
        validarletras("INGRESE LA PALABRA PARA VEER SI ES UN POLINDROMO\n", cade);
        palindromo(cade);
        return 0;
        break;
    }
}
void palindromo(char cadena[])
{
    char cadena2[100];
    strcpy(cadena2, cadena);
    rever(cadena2);

    if (strcmp(cadena, cadena2) == 0)
    {
        printf("LA CADENA SI ES PALINDROMO ");
    }
    else
    {
        printf("LA CADENA NO ES PALINDROMO\n ");
    }
}
char *capital(char cadena[])
{
    int i, x;
    x = contador(cadena);
    minuscula(cadena);
    for (i = 0; i < x; i++)
    {
        if (cadena[i] == cadena[0])
        {
            if (cadena[i] >= 'a' && cadena[i] <= 'z')
            {
                cadena[i] = cadena[i] - 32;
            }
        }
        if (cadena[i] == ' ')
        {
            if (cadena[i + 1] >= 'a' && cadena[i + 1] <= 'z')
            {
                cadena[i + 1] = cadena[i + 1] - 32;
            }
        }
    }
    return cadena;
}
char *rever(char cadena[])
{
    int i, con;
    con = strlen(cadena) - 1;
    for (i = 0; i < con; i++, con--)
    {
        char temp = cadena[i];
        cadena[i] = cadena[con];
        cadena[con] = temp;
    }
    return cadena;
}
int contador(char cadena[])
{
    int i;
    i = 0;
    while (cadena[i] != 0)
    {
        i++;
    }
    return i;
}
char *minuscula(char cadena[])
{
    int i, x;
    x = strlen(cadena);

    for (i = 0; i < x; i++)
    {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z')
        {
            cadena[i] = cadena[i] + 32;
        }
    }
    return cadena;
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
int validarnumeros(char mensaje[], int ri, int rf)
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
char *sinespacios(char cadena[])
{
    int i, con, j;
    con = contador(cadena);
    for (i = 0; i < con; i++)
    {
        if (cadena[i] == ' ')
        {
            for (j = i; j < con; j++)
            {
                cadena[j] = cadena[j + 1];
            }
        }
    }
    return cadena;
}
char *iniciofinalsinespacio(char mensaje[], char cadena[])
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
            if (cadena[i] == cadena[0])
            {
                if (cadena[i] == ' ')
                {
                    printf("HAY UN ESPACIO AL PRINCIPIO\n");
                    salida = 1;
                    break;
                }
            }
            if (cadena[i] == cadena[x - 1])
            {
                if (cadena[i] == ' ')
                {
                    printf("HAY UN ESPACIO AL FINAL\n");
                    salida = 1;
                    break;
                }
            }
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
    strupr(cadena);
    return cadena;
}
