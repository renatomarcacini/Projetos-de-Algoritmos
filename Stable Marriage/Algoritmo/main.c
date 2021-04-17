#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

//Tamanho N dos dados de entrada
int size = 0;

//Imprimi a matriz de dados de entrada
void PrintfMatrixPrefer(int prefer[N][N], char name[100]){

    printf("%s \n", name);
    printf("--------------- \n");
    int i, j;
    for(i = 0; i < size; i++){
        printf("%i|", (i+1));
        for(j = 0; j < size; j++){
            printf(" %i", (prefer[i][j]+1));
        }
        printf("\n");
    }
    printf("--------------- \n");
}

//Valida se a mulher prefere a nova proposta
int WomanPreferNewMan(int prefer[N][N], int woman, int newMan, int currentMan){
    int i;
    for (i = 0; i < size; i++)
    {
        if (prefer[woman][i] == newMan)
            return 1;

        if (prefer[woman][i] == currentMan)
           return 0;
    }
}

//Verifica se possui homens solteiros
int AllManIsFree(int free[N]){
    int result = 0;

    int i;
    for(i = 0; i < size; i++){
        if(free[i] == -1){
            result = 1;
            break;
        }
        else{
            result = 0;
        }
    }

    return result;
}

//Algoritmo Gale-Shapley
void FindingMatch(int manPrefers[N][N], int womanPrefers[N][N]){
    int manFree[N];
    int womanFree[N];
    int womanPartner[N];
    int manPartner[N];
    int freeCount = N;

    memset(manFree, -1, N* sizeof(manFree[0]));
    memset(womanFree, -1, N* sizeof(womanFree[0]));
    memset(womanPartner, -1, N* sizeof(womanPartner[0]));
    memset(manPartner, -1, N* sizeof(manPartner[0]));

    //Enquanto houver homens solteiros encontrar uma solução
    while(AllManIsFree(manFree) == 1){
        //Captura um homem solteiro
        int man;
        for(man = 0; man < size; man++){
            if(manFree[man] == -1)
                break;
        }

        int i;
        for(i = 0; i < size && manFree[man] == -1; i++){
            //Seleciona a primeira preferência de mulher
            int woman = manPrefers[man][i];

            //Se a mulher está solteira forma um casal
            if(womanFree[woman] == -1){
                womanFree[woman] = man;
                manFree[man] = 1;
                manPartner[man] = woman;
                freeCount--;
            }
            else{
                int newMan = womanFree[woman];
                //Se a mulher preferir a nova proposta, é desfeito o casal atual e formado um novo
                if(WomanPreferNewMan(womanPrefers, woman, newMan, man) == 0){
                    womanFree[woman] = man;
                    manFree[man] = 1;
                    manFree[newMan] = -1;
                    manPartner[man] = woman;
                    manPartner[newMan] = -1;
                }
            }
        }
    }

    int i;
    for(i = 0; i < size; i++){
        printf("MATCH: %i, %i \n", (i+1), (manPartner[i]+1));
    }
}

int main()
{
    size = 4;
    //Inputs começando do ZERO para facilitar operação com matriz e vetor
    int womanPrefers[N][N] = {
        {3, 2, 0, 1},
        {1, 0, 2, 3},
        {0, 2, 3, 1},
        {3, 2, 0, 1}
    };

    int manPrefers[N][N] = {
        {2, 1, 3, 0},
        {1, 2, 0, 3},
        {2, 0, 1, 3},
        {2, 1, 3, 0}
    };
    printf("\nCASE 1 \n");
    PrintfMatrixPrefer(womanPrefers, "Woman Ranking");
    PrintfMatrixPrefer(manPrefers, "Man Ranking");

    FindingMatch(manPrefers, womanPrefers);

    size = 7;
    int case2womanPrefers[N][N] = {
        {2, 3, 1, 0, 5, 6, 4},
        {5, 3, 1, 2, 4, 0, 6},
        {5, 2, 4, 6, 1, 3, 0},
        {0, 5, 2, 1, 3, 6, 4},
        {0, 5, 4, 2, 3, 6, 1},
        {0, 6, 2, 3, 4, 5, 1},
        {4, 5, 1, 3, 2, 6, 0}
    };

    int case2manPrefers[N][N] = {
        {3, 4, 2, 6, 1, 5, 0},
        {4, 5, 3, 6, 2, 1, 0},
        {0, 5, 4, 3, 2, 6, 1},
        {2, 4, 5, 6, 1, 3, 0},
        {0, 6, 5, 3, 2, 4, 1},
        {5, 2, 6, 4, 1, 3, 0},
        {0, 6, 3, 1, 5, 4, 2}
    };
    printf("\nCASE 2 \n");
    PrintfMatrixPrefer(case2womanPrefers, "Woman Ranking");
    PrintfMatrixPrefer(case2manPrefers, "Man Ranking");
    FindingMatch(case2manPrefers, case2womanPrefers);

    return 0;
}
