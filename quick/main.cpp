#include<ctime>
#include"process.hh"
#include"quick_srt.hh"

#define ROZMIAR_X 100
#define ROZMIAR_Y_1 10000
#define ROZMIAR_Y_2 50000
#define ROZMIAR_Y_3 100000
#define ROZMIAR_Y_4 500000
#define ROZMIAR_Y_5 1000000
#define PERCENT 100

using namespace std;

int main()
{
    srand(time(NULL));

    int **table=new int *[ROZMIAR_X];
    for(int j=0; j<ROZMIAR_X; j++)
        table[j]=new int[ROZMIAR_Y_1];

    from_file(table,ROZMIAR_X,ROZMIAR_Y_1,"dane.txt");

    clock_t Start=clock();
    for (int i=0; i<ROZMIAR_X; i++)
    {
        quick_srt(table[i], 0, ROZMIAR_Y_1, PERCENT);    
    }
    clock_t Stop=clock();
    
    // reverse(table,ROZMIAR_X,ROZMIAR_Y_1);
    to_file(table,ROZMIAR_X,ROZMIAR_Y_1,"dane_posortowane.txt");

    for(int j=0; j<ROZMIAR_X; j++)
        delete[] table[j];
    delete[] table;

    double time = static_cast<double>(Stop-Start)/CLOCKS_PER_SEC;
    cout<<"Czas sortowania: "<<time<<" s"<<endl;
}