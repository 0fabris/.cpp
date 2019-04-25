/*
        Codifica di Hamming
        19/12/18
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
        //Dichiarazione Costanti e Variabili
        const int N_BITS = 8;
        int pot = (log(N_BITS)/log(2))+1,dimen = N_BITS+pot ,potdue[pot],bitcc[pot];
        int i,j,ind,cont,tmp,cont1;
        bool bits[dimen],flag;
        string inp,caso;
        //Inizio Programma

        //Input scelta
        do
        {
                //Inizializzo Contatori e Variabili
                caso = "";
                cont1 = pot;
                cont = 0;
                flag = 0;

                for(i=0;i<pot;i++)
                {
                        potdue[i]=pow(2,i); //trovo le potenze di 2 comprese nell'intervallo
                        bitcc[i]=0; //Inizializzo elementi di bitcc a 0
                }

                for(i=0;i<dimen;i++)
                        bits[i]=0;//Inizializzo elementi di bits a 0

                do
                {
                        cout << "\nInserire la funzione scelta\n1: Input "<<N_BITS<<" bit e calcolo bit controllo\n2: Input "<<dimen<<" bit e verifica bit controllo immessi\n0: Esci\n---->";
                        cin >> caso;
                }while(caso[0]!='0' && caso[0]!='1'  && caso[0]!='2' || caso[1]!='\0');

                switch(caso[0]){

                        case '1':
                                //Input 8bit e calcolo bit di controllo + visualizza messaggio completo
                                for(i=0;i<dimen;i++)
                                {
                                        ind = dimen-i;
                                        for(j=0;j<pot;j++)
                                                if(ind == potdue[j]) //Guardo se l'indice e' potenza di due
                                                        flag = 1;

                                        if(!flag)//Se indice potenza di due salto l'input
                                        {

                                                do
                                                {
                                                        cout << "Inserire "<<ind-cont1<<"\370 bit\n---->";
                                                        cin >> inp;
                                                }while(inp[0]!='0' && inp[0]!='1' || inp[1]!='\0'); //Convalida dell'input

                                                if(inp[0] == '1')
                                                        bits[i]=1;
                                                else
                                                        bits[i]=0;

                                                //Trovo potenze di due che formano i vari indici
                                                for(j=pot-1;j>=0;j--)
                                                        if(ind-pow(2,j)>=0)
                                                        {
                                                                ind -= pow(2,j);
                                                                bitcc[pot-1-j]+=bits[i];//Sommo in bitcc il valore del bit che e' formato dalla somma delle potenze di due ricercate
                                                        }

                                        }
                                        else
                                        {

                                                flag = 0;
                                                cont1--;
                                        }
                                }

                                for(i=0;i<pot;i++)
                                {
                                        ind = dimen-potdue[pot-1-i];
                                        //cout << bitcc[pot-1-i]<<endl;
                                        bitcc[i]%=2; //Resto della divisione delle somme per due
                                        bits[ind]=bitcc[i];//Cambio il bit sul messaggio finale

                                        cout <<"\nBit di controllo "<<potdue[pot-1-i]<<": "<<bitcc[i]<<endl; //Output bit di controllo calcolati
                                }

                                cout << "\nMessaggio: \n";

                                for(i=0;i<dimen;i++)
                                        cout << bits[i]<<" "; //Output messaggio corretto
                                break;

                        case '2':
                                //Input 12bit e verifica bit controllo

                                for(i=0;i<dimen;i++)
                                {
                                        //INSERIMENTO VALORI
                                        ind = dimen-i;
                                        do
                                        {
                                                cout << "Inserire "<<ind<<"\370 bit\n---->";
                                                cin >> inp;
                                        }while(inp[0]!='0' && inp[0]!='1'|| inp[1]!='\0');//Convalida dell'input

                                        if(inp[0] == '1')
                                                bits[i]=1;
                                        else
                                                bits[i]=0;
                                }

                                for(i=0;i<dimen;i++)
                                {
                                        ind = dimen-i;
                                        for(j=0;j<pot;j++)
                                                if(ind == potdue[j]) //Cerco se indice e' potenza di due 
                                                        flag = 1;
                                        if(!flag)
                                        {
                                                //Trovo potenze di due che formano i vari indici
                                                for(j=pot-1;j>=0;j--)
                                                        if(ind+1-pow(2,j)>0)
                                                        {
                                                                ind -= pow(2,j);
                                                                bitcc[pot-1-j]+=bits[i]; //Sommo in bitcc il valore del bit che e' formato dalla somma delle potenze di due ricercate
                                                        }
                                        }
                                        else
                                                flag = 0;
                                }


                                for(i=0;i<pot;i++)
                                {
                                        bitcc[i]%=2;
                                        ind = dimen-potdue[pot-1-i];

                                        if(bits[ind]!=bitcc[i]) //Se il bit di controllo calcolato != da quello immesso
                                        {
                                                cout <<"\nErrore sul bit di controllo "<<potdue[pot-1-i]<<"\n\tCorretto: "<<bitcc[i]<<"\n\tImmesso: "<<bits[ind]<<endl;
                                                cont += potdue[pot-1-i];//Conto per trovare la possibile posizione del bit sbagliato
                                        }
                                        else
                                                cout <<"\nBit di controllo "<<potdue[pot-1-i]<<": "<<bitcc[i]<<endl; //Output bit di controllo
                                }

                                if(cont>0 && cont <= dimen) //Posizione del possibile errore 
                                {
                                        cout << "\n\nPossibile errore sul bit "<< cont;
                                        bits[dimen-cont] = !bits[dimen-cont]; //Correzione errore
                                }
                                else
                                        cout << "\n\nFalso errore in posizione "<<cont;

                                cout << "\nMessaggio corretto: \n";

                                for(i=0;i<dimen;i++)
                                        cout << bits[i]<<" ";//Output messaggio corretto

                                break;

                        default:
                                //Caso alternativo
                                break;
                }
                cout << endl;
        }while(caso[0]!='0');


        //system("PAUSE");
        return 0;
}
