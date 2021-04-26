#include <iostream>
#include <algorithm>
#define N 1000

using namespace std;

void SolveBusDriverProblem(int driver, int distance, int routesMorning[N], int routesEvening[N], int overtimePay){
    //Ordenação das rotas de dia/noite dos motoristas
    sort(routesMorning, routesMorning + driver);
    sort(routesEvening, routesEvening + driver);

    int payment = 0;
    for(int i=0; i < driver; i++){
        //Verifica se a soma das menores rotas ultrapassa a distância que o motorista pode fazer
        if(routesMorning[i] + routesEvening[driver-1-i] > distance){
            //Calcula a quantidade de distância que foi percorrida a mais
            payment += routesMorning[i] + routesEvening[driver-1-i] - distance;
        }
    }
    cout << (payment * overtimePay) << endl;
}


int main()
{
    int n, d, r;
    while(scanf("%d %d %d", &n, &d, &r) == 3) {
        if(n == 0)
            break;
        int routesMorning[N], routesEvening[N], i;
        for(i = 0; i < n; i++)
            scanf("%d", routesMorning+i);
        for(i = 0; i < n; i++)
            scanf("%d", routesEvening+i);

        SolveBusDriverProblem(n, d, routesMorning, routesEvening, r);
    }
    return 0;
}



