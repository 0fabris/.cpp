//Convertitore da base 2-36 a base 10. - Ultima Modifica 27/01/19 - V1.1b1

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

//Dichiarazioni Costanti 
const int BASEMAX = 36, NON_ACC=-1;

//Funzioni

int convString(string str1,int base1)
{
        int res=0,x,lng=0,temp;
        for(x=0;str1[x]!='\0';x++)
                lng++; //Trovo Lunghezza Stringa

        for(x=0;x<lng;x++)
        {
                //Verifico se il carattere e' corretto, cioe' superiore a '0' e inferiore al valore della base
                if(str1[x] >= 'A' && str1[x]< ('A'+base1-10)) //Se str1[x]olo � maggiore del carattere 9 converte il rispettivo valore da 'A'=10 ad oltranza
                temp = str1[x] - 'A' +10;
            else if(str1[x] >= '0' && str1[x] <='9')
                temp = str1[x] - '0';
                else
                        return NON_ACC;
                res += temp*pow(base1,lng-x-1);
        }
        return res;
}


//Main
int main()
{
    //Dichiarazione Variabili
        int nsimb,base,i,risultato;
    char input;
    string tmp;
    
    do
    {
            //Inizializzo Variabili
                risultato = 0;
                //Inserimento Base + convalida input
            do{
               cout << "Inserire una base compresa tra 2 e "<<BASEMAX<<"\n---->";
               cin >> tmp;
               base = convString(tmp,10);
            }while(base<2 || base > BASEMAX); 
             
            //Inserimento numero simboli + convalida input
            do{
               cout << "Inserire il Numero di simboli da immettere\n---->";
               cin >> tmp;
               nsimb = convString(tmp,10);
            }while(nsimb<1);
            
            //Inserimento cifre del numero da convertire
            cout << "\nInserire le cifre dalla piu' significativa alla meno.\n\n";
            
            for(i=0;i<nsimb;i++)
            {
                        //Convalida dell'input
                        do{
                                cout << "Inserire il "<<nsimb-i << " simbolo\n---->";
                                cin >> tmp;
                                if(tmp[1]=='\0') //Se stringa lunga un carattere
                                        input = convString(tmp,base);
                                else
                                        input = NON_ACC;
                        }while(int(input) == NON_ACC);
                        risultato += (input)*pow(base,nsimb-i-1);
            }
            
            if(risultato >= 0 && risultato < 29298687 )// Valore max Possibile
                cout << "\n\nIl risultato in base 10 \212 "<<risultato<<endl<<endl;
            else
                cout << "\nValore Troppo grande per il tipo INT";
            do
            {
                cout << "Rieseguo il programma? \n\t1: SI\n\t0: NO\n---->";
                cin >>tmp;
                }while((tmp[0]!='1' && tmp[0]!='0')|| tmp[1]!='\0');
            
        }while(tmp[0] == '1');

        cout << "\nArrivederci!";

    //system("PAUSE");
    return 0;
    
}
