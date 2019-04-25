#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void aspetta(long m) 
{ 
time_t adesso = time(NULL);
while(difftime(time(NULL), adesso) < m);
}
void barra(int perc)
{
        char pieno = 178, vuoto = 176;
        int max = 30, mul=6,tmp;
        int maxlarg = 120;
        int delay;
        while(perc < max+1)
        {
                system("CLS");
                delay = rand()%2+1;
                cout<<endl;
                for(int i = 0;i<(120-(max*mul))/2;i++)
                        cout << " ";
                //mul = rand()%4 +1;
                for(int i=0;i<perc*mul;i++)
                        cout << pieno;
                for(int i = 0;i<(max-perc)*mul;i++)
                        cout << vuoto;
                tmp=maxlarg-3;
                if (perc*10==100)
                        tmp--;
                if(perc== 0)
                        tmp++;
                for(int i = 0;i<(tmp);i++)
                {
                        cout <<" ";
                }
                cout << (perc*100/max)<< "%";
                aspetta(delay);
                perc++;
        }
        cout << endl;
}
int main()
{
        srand(time(NULL));
        barra(1);
        system("PAUSE");
        return 0;
}
