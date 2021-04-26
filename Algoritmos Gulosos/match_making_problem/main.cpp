#include <iostream>
#define N 10005
using namespace std;

void SolveMatchMakingProblem(int event, int n, int m, int bachelorsAge[N]){
    if(n == 0 && m == 0)
        return;

    int minimumAge = 60;

    //Verifica a menor idade entre os Solteiros
    for(int i = 0; i < n; i++)
        if(bachelorsAge[i] < minimumAge)
            minimumAge = bachelorsAge[i];

    //Se a quantidade de solteiros for menor ou igual a quantidade de solteira, não haverá nenhum homem solteiro no final
    if(n <= m)
        printf("Case %d: 0\n", event);
    else
        printf("Case %d: %d %d\n", event, n-m, minimumAge);
}

int main()
{
    int case1BachelorsAge[4] = {26,25,2,21};
    int case2BachelorsAge[1] = {20};
    int case3BachelorsAge[4] = {5,5,10,15};
    SolveMatchMakingProblem(1, 4,4, case1BachelorsAge);
    SolveMatchMakingProblem(2, 1,2, case2BachelorsAge);
    SolveMatchMakingProblem(3, 4,2, case3BachelorsAge);

    return 0;
}
