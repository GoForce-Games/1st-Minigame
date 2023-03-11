#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tabla();
int resultado();
int puntuacion();
int reset();
int puntuacion1, puntuacion2;
int repeticion; // volver a jugar
int  i, jugada, jugada2; // variable iterador, cifra1ID, cifra2ID
int jugador = 1;
int j = 0;
int j1 = 0;
int j2 = 0;
char nullturn;
char simbolo, simbolo2;
char* cuadricula2[17] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1' };
char* cuadricula[17] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6' };

int main()
{
    printf("\tCUATRO EN RAYA\n\n");

    do
    {
        do
        {
            printf("Jugador 1 -> (X) \nJugador 2 -> (O)\n");

            tabla();

            jugador = (jugador % 2) ? 1 : 2;

            printf("Jugador %d, escoge la casilla (Digito 1, espacio, Digito 2):  ", jugador);
            scanf_s("%d %d", &jugada2, &jugada);
            printf("\n\n");
            printf("________________________________________________________________________________________________________________________");

            puntuacion();

            simbolo = (jugador == 1) ? 'X' : 'O';

            fichas();

            jugador++;

            i = resultado();

            system("cls");
        }

        while (i == -1);

        if (i == 1)
        {
            system("cls");

            printf("\n\n !!!Enhorabuena jugador %d, has ganado!!!\n", --jugador);

            if (jugador == 1)
            {

                j1++;
            }

            else if (jugador == 2)
            {

                j2++;
            }

            puntuacion();
        }

        else
        {
            printf("\n\n\t\t\tEmpate\n\n");
        }

        printf("\t\tQuieres continuar?\n\n");
        printf("Para continuar pulsa 1, para terminar pulsa 0\n\n\t");
        printf("\tEscoge tu opcion:\n\n\t\t\t");
        scanf_s(" %d", &repeticion);
        printf("\n\n");

        if (repeticion == 1)
        {
            printf("\t\t!!!Revancha!!!\n\n");

            reset();

            system("cls");
        }

        else if (repeticion == 0)
        {
            j++;
        }

        else
        {
            printf("\t\t  \n\n");
            j++;
        }
    }

    while (j == 0);
}

void tabla()  //Printea el tablero
{
    printf("\n\n\t");
    printf("      |      |      |     \n\t");
    printf("  %c%c  |  %c%c  |  %c%c  |  %c%c  \n\t", cuadricula2[1], cuadricula[1], cuadricula2[2], cuadricula[2], cuadricula2[3], cuadricula[3], cuadricula2[4], cuadricula[4]);
    printf("______|______|______|______      ---------------------------\n\t");
    printf("      |      |      |            |  Jugador 1 | Jugador 2  |\n\t");
    printf("  %c%c  |  %c%c  |  %c%c  |  %c%c        |------------|------------|\n\t", cuadricula2[5], cuadricula[5], cuadricula2[6], cuadricula[6], cuadricula2[7], cuadricula[7], cuadricula2[8], cuadricula[8]);
    printf("______|______|______|______      |      %d     |     %d      |\n\t", j1, j2);
    printf("      |      |      |            ---------------------------\n\t");
    printf("  %c%c  |  %c%c  |  %c%c  |  %c%c  \n\t", cuadricula2[9], cuadricula[9], cuadricula2[10], cuadricula[10], cuadricula2[11], cuadricula[11], cuadricula2[12], cuadricula[12]);
    printf("______|______|______|______\n\t");
    printf("      |      |      |       \n\t");
    printf("  %c%c  |  %c%c  |  %c%c  |  %c%c  \n\t", cuadricula2[13], cuadricula[13], cuadricula2[14], cuadricula[14], cuadricula2[15], cuadricula[15], cuadricula2[16], cuadricula[16]);
    printf("      |      |      |     \n\n\n");
}

// Coloca ficha
int fichas()
{
    if (jugada2 == 0)
    {
        if (jugada == 1 && cuadricula2[1] != cuadricula[1])
        {
            cuadricula2[1] = simbolo;
            cuadricula[1] = simbolo;
        }

        else if (jugada == 2 && cuadricula2[2] != cuadricula[2])
        {
            cuadricula2[2] = simbolo;
            cuadricula[2] = simbolo;
        }

        else if (jugada == 3 && cuadricula2[3] != cuadricula[3])
        {
            cuadricula2[3] = simbolo;
            cuadricula[3] = simbolo;
        }

        else if (jugada == 4 && cuadricula2[4] != cuadricula[4])
        {
            cuadricula2[4] = simbolo;
            cuadricula[4] = simbolo;
        }

        else if (jugada == 5 && cuadricula2[5] != cuadricula[5])
        {
            cuadricula2[5] = simbolo;
            cuadricula[5] = simbolo;
        }

        else if (jugada == 6 && cuadricula2[6] != cuadricula[6])
        {
            cuadricula2[6] = simbolo;
            cuadricula[6] = simbolo;
        }

        else if (jugada == 7 && cuadricula2[7] != cuadricula[7])
        {
            cuadricula2[7] = simbolo;
            cuadricula[7] = simbolo;
        }

        else if (jugada == 8 && cuadricula2[8] != cuadricula[8])
        {
            cuadricula2[8] = simbolo;
            cuadricula[8] = simbolo;
        }

        else if (jugada == 9 && cuadricula2[9] != cuadricula[9])
        {
            cuadricula2[9] = simbolo;
            cuadricula[9] = simbolo;
        }

        else //Movimiento nulo
        {
            printf("\n\n\t");
            printf("!!!No es posible ese movimiento!!!\n\n");
            printf("Pulsa cualquier tecla para volver a repetir el turno \n\n\t\t\t");
            scanf_s(" %c", &nullturn);
            jugador--;
        }
    }

    else if (jugada2 == 1)
    {
        if (jugada == 0 && cuadricula2[10] != cuadricula[10])
        {
            cuadricula2[10] = simbolo;
            cuadricula[10] = simbolo;
        }

        else if (jugada == 1 && cuadricula2[11] == cuadricula[11])
        {
            cuadricula2[11] = simbolo;
            cuadricula[11] = simbolo;
        }

        else if (jugada == 2 && cuadricula2[12] != cuadricula[12])
        {
            cuadricula2[12] = simbolo;
            cuadricula[12] = simbolo;
        }

        else if (jugada == 3 && cuadricula2[13] != cuadricula[13])
        {
            cuadricula2[13] = simbolo;
            cuadricula[13] = simbolo;
        }

        else if (jugada == 4 && cuadricula2[14] != cuadricula[14])
        {
            cuadricula2[14] = simbolo;
            cuadricula[14] = simbolo;
        }

        else if (jugada == 5 && cuadricula2[15] != cuadricula[15])
        {
            cuadricula2[15] = simbolo;
            cuadricula[15] = simbolo;
        }

        else if (jugada == 6 && cuadricula2[16] != cuadricula[16])
        {
            cuadricula2[16] = simbolo;
            cuadricula[16] = simbolo;
        }

        else
        {
            printf("\n\n\t");
            printf("!!!No es posible ese movimiento!!!\n\n");
            printf("Pulsa cualquier tecla para volver a repetir el turno \n\n\t\t\t");
            scanf_s(" %c", &nullturn);
            jugador--;
        }
    }

    else
    {
        printf("\n\n\t");
        printf("!!!No es posible ese movimiento!!!\n\n");
        printf("Pulsa cualquier tecla para volver a repetir el turno \n\n\t\t\t");
        scanf_s(" %c", &nullturn);
        jugador--;
    }
}

int resultado()  //Funcion que revisa en todo momento si se cumple un requisito de victoria
{
    // Revisa la primera fila
    if (cuadricula[1] == cuadricula[2] && cuadricula[2] == cuadricula[3] && cuadricula[3] == cuadricula[4] &&
        cuadricula2[1] == cuadricula2[2] && cuadricula2[2] == cuadricula2[3] && cuadricula2[3] == cuadricula2[4] &&
        cuadricula[1] == cuadricula2[1] && cuadricula[2] == cuadricula2[2] && cuadricula[3] == cuadricula2[3] &&
        cuadricula[4] == cuadricula2[4])
        return 1;

    // Revisa la segunda fila
    else if (cuadricula[5] == cuadricula[6] && cuadricula[6] == cuadricula[7] && cuadricula[7] == cuadricula[8] &&
        cuadricula2[5] == cuadricula2[6] && cuadricula2[6] == cuadricula2[7] && cuadricula2[7] == cuadricula2[8] &&
        cuadricula[5] == cuadricula2[5] && cuadricula[6] == cuadricula2[6] && cuadricula[7] == cuadricula2[7] &&
        cuadricula[8] == cuadricula2[8])
        return 1;

    // Revisa la tercera fila
    else if (cuadricula[9] == cuadricula[10] && cuadricula[10] == cuadricula[11] && cuadricula[11] == cuadricula[12] &&
        cuadricula2[9] != cuadricula2[10] && cuadricula2[10] == cuadricula2[11] && cuadricula2[11] == cuadricula2[12] &&
        cuadricula[9] == cuadricula2[9] && cuadricula[10] == cuadricula2[10] && cuadricula[11] == cuadricula2[11] &&
        cuadricula[12] == cuadricula2[12])
        return 1;

    // Revisa la cuarta fila
    else if (cuadricula[13] == cuadricula[14] && cuadricula[14] == cuadricula[15] && cuadricula[15] == cuadricula[16] &&
        cuadricula2[13] == cuadricula2[14] && cuadricula2[14] == cuadricula2[15] && cuadricula2[15] == cuadricula2[16] &&
        cuadricula[13] == cuadricula2[13] && cuadricula[14] == cuadricula2[14] && cuadricula[15] == cuadricula2[15] &&
        cuadricula[16] == cuadricula2[16])
        return 1;

    // Revisa la primera columna
    else if (cuadricula[1] == cuadricula[5] && cuadricula[5] == cuadricula[9] && cuadricula[9] == cuadricula[13] &&
        cuadricula2[1] == cuadricula2[5] && cuadricula2[5] == cuadricula2[9] && cuadricula2[9] == cuadricula2[13] &&
        cuadricula[1] == cuadricula2[1] && cuadricula[5] == cuadricula2[5] && cuadricula[9] == cuadricula2[9] &&
        cuadricula[13] == cuadricula2[13])
        return 1;

    // Revisa la segunda columna
    else if (cuadricula[2] == cuadricula[6] && cuadricula[6] == cuadricula[10] && cuadricula[10] == cuadricula[14] &&
        cuadricula2[2] == cuadricula2[6] && cuadricula2[6] == cuadricula2[10] && cuadricula2[10] == cuadricula2[14] &&
        cuadricula[2] == cuadricula2[2] && cuadricula[6] == cuadricula2[6] && cuadricula[10] == cuadricula2[10] &&
        cuadricula[14] == cuadricula2[14])
        return 1;

    // Revisa la tercera columna
    else if (cuadricula[3] == cuadricula[7] && cuadricula[7] == cuadricula[11] && cuadricula[11] == cuadricula[15] &&
        cuadricula2[3] == cuadricula2[7] && cuadricula2[7] == cuadricula[11] && cuadricula2[11] == cuadricula2[15] &&
        cuadricula[3] == cuadricula2[3] && cuadricula[7] == cuadricula2[7] && cuadricula[11] == cuadricula2[11] &&
        cuadricula[15] == cuadricula2[15])
        return 1;

    // Revisa la cuarta columna
    else if (cuadricula[4] == cuadricula[8] && cuadricula[8] == cuadricula[12] && cuadricula[12] == cuadricula[16] &&
        cuadricula2[4] == cuadricula2[8] && cuadricula2[8] == cuadricula2[12] && cuadricula2[12] == cuadricula2[16] &&
        cuadricula[4] == cuadricula2[4] && cuadricula[8] == cuadricula2[8] && cuadricula[12] == cuadricula2[12] &&
        cuadricula[16] == cuadricula2[16])
        return 1;

    // Revisa la diagonal de izquierda a derecha
    else if (cuadricula[1] == cuadricula[6] && cuadricula[6] == cuadricula[11] && cuadricula[11] == cuadricula[16] &&
        cuadricula2[1] == cuadricula2[6] && cuadricula2[6] == cuadricula2[11] && cuadricula2[11] == cuadricula2[16] &&
        cuadricula[1] == cuadricula2[1] && cuadricula[6] == cuadricula2[6] && cuadricula[11] == cuadricula2[11] &&
        cuadricula[16] == cuadricula2[16])
        return 1;

    // Revisa la diagonal de derecha a izquierda
    else if (cuadricula[4] == cuadricula[7] && cuadricula[7] == cuadricula[10] && cuadricula[10] == cuadricula[13] &&
        cuadricula2[4] == cuadricula2[7] && cuadricula2[7] == cuadricula2[10] && cuadricula2[10] == cuadricula2[13] &&
        cuadricula[4] == cuadricula2[4] && cuadricula[7] == cuadricula2[7] && cuadricula[10] == cuadricula2[10] &&
        cuadricula[13] == cuadricula2[13])
        return 1;

    else if (cuadricula[1] != '1' && cuadricula[2] != '2' && cuadricula[3] != '3' &&
        cuadricula[4] != '4' && cuadricula[5] != '5' && cuadricula[6] != '6' && cuadricula[7]
        != '7' && cuadricula[8] != '8' && cuadricula[9] != '9' && cuadricula[10] != '0' &&
        cuadricula[11] != '1' && cuadricula[12] != '2' && cuadricula[13] != '3' &&
        cuadricula[14] != '4' && cuadricula[15] != '5' && cuadricula[16] != '6' &&
        cuadricula2[1] != '0' && cuadricula2[2] != '0' && cuadricula2[3] != '0' &&
        cuadricula2[4] != '0' && cuadricula2[5] != '0' && cuadricula2[6] != '0' &&
        cuadricula2[7] != '0' && cuadricula2[8] != '0' && cuadricula2[9] != '0' && cuadricula2[10] != '1' &&
        cuadricula2[11] != '1' && cuadricula2[12] != '1' && cuadricula2[13] != '1' &&
        cuadricula2[14] != '1' && cuadricula2[15] != '1' && cuadricula2[16] != '1')
        return 0;

    else
    {
        return  -1;
    }
}

int reset()   //Funcion que resetea el tablero
{
    char cuadriculaa[17] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1' };
    char cuadriculab[17] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6' };

    for (int i = 0; i <= 17; i++)
    {
        cuadricula2[i] = cuadriculaa[i];
        cuadricula[i] = cuadriculab[i];
    }
}

int puntuacion()   //Tablero de puntuacion
{
    printf("\n\n\t");
    printf("    ---------------------------\n\t");
    printf("    |  Jugador 1 | Jugador 2  |\n\t");
    printf("    |------------|------------|\n\t");
    printf("    |      %d     |     %d      |\n\t", j1, j2);
    printf("    ---------------------------\n\n");
}

