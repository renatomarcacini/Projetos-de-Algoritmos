#include <iostream>
#include <algorithm>
#define N 1000
using namespace std;

struct JOB{
    char ID;
    int DeadLine;
    int Cost;
};

int main()
{
    int n;
    while(true){
        scanf("%i", &n);
        if(n == 0)
            break;

        JOB jobs[N];
        bool slot[N];
        char solution[N];
        int i;
        int j;

        //Leitura dos valores de JOBS
        for(i=0; i < n; i++){
            cin >> jobs[i].ID;
            cin >> jobs[i].DeadLine;
            cin >> jobs[i].Cost;
        }

        //Ordenação do JOBS por Custo
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(jobs[i].Cost >= jobs[j].Cost){
                    JOB auxJob = jobs[j];
                    jobs[j] = jobs[i];
                    jobs[i] = auxJob;
                }
            }
        }

        //Solução
        for(int i=0; i<n; i++){
            for(int j= min(n, jobs[i].DeadLine)-1; j>=0; j--){
                if(slot[j] == false){
                    slot[j] = true;
                    solution[j] = jobs[i].ID;
                    break;
                }
            }
        }

        for(int i=0; i < n; i++){
            cout << solution[i] << "|" << endl;
        }
    }
    return 0;
}

