#include <iostream>
#include <string.h>
#include <fstream>  // libreria necessaria a richiamare file esterni
#include <stdlib.h> // libreria usata per richiamare la funzione system e la cls
#define NMAX 100

using namespace std;

// dichiarazione variabili

string Cifra;
string Lettera_str;
string CifraCercata;
string ValoriPari_str;
string ValoriDispari_str;
string sceltafrase;
string comune;
string codiceCatastale;

char sigla [NMAX];
char frase [NMAX];
char cognome[NMAX];
char nome[NMAX];
char codice [NMAX];
char giorno [NMAX];
char mese [NMAX];
char anno [NMAX];
char giornoF [NMAX];
char luogo[NMAX];
char comuneScelto [NMAX];
char CifrePari [NMAX];
char CifreDispari [NMAX];
char scelta ;
char sesso [1];

int SommaPari=0;
int SommaDispari =0;
int Somma=0;
int ValoriPari;
int ValoriDispari;
int resto=0;
int Cifra_Controllo =0;
int n=0;
int Lettera=0;

int posizione=0;
int j=0,i=0,k=0,l=0;
int cons=0;
int c1,somma=0;
int data[5];
int conta=0;
int cifra =0;

int IntGiorno = 0;
int IntMese = 0;
int IntAnno = 0;


char *Maiuscolo(char *stringa)          // funzione che trasforma in maiuscolo i caratteri delle stringhe inserite dall'utente
{
    int i=0;
    while (i<NMAX && stringa[i]!='\0')
    {
        if (stringa[i]>='a' && stringa[i]<='z')
        stringa[i] -= 32;
        i++;
    }
    return stringa;
}

char *CodificaCognome(char *cognome)    // funzione che seleziona le lettere del cognome necessarie al codice fiscale e le copia nelle rispettive posizioni
{
    int j = 0;

    l=strlen(cognome);
    Maiuscolo(cognome);

    for(int i=0; i<l; i++)
    {
        if(cognome[i]!='A' && cognome[i]!='E' && cognome[i]!='I' && cognome[i]!='O' && cognome[i]!='U')
        {
            codice[j] = cognome[i];
            j++;
            posizione++;
        }
        if(posizione == 3)
        {
            break;
        }
    }

    for(int i=0; i<l; i++)
    {
        if(cognome[i]=='A' || cognome[i] == 'E' || cognome[i] == 'I' || cognome[i] == 'O' || cognome[i] == 'U')
        {
            codice[j] = cognome[i];
            j++;
            posizione++;
        }
        if( posizione == 3 )
        {
            break;
        }
    }

    if(posizione != 3)
    {
        while( posizione != 3 )
        {
            codice[ j ] = 'X';
            j++;
            posizione++;
        }
    }
}

char *CodificaNome(char *nome)          // funzione che seleziona le lettere del nome necessarie al codice fiscale e le copia nelle rispettive posizioni
{
    Maiuscolo(nome);
    l=strlen(nome);
    //somma+=l; serve?

    for(int i=0; i<l; i++)
    {
        if(nome[i]!= 'A' && nome[i]!= 'E' && nome[i]!= 'I' && nome[i]!= 'O' && nome[i]!= 'U')
        {
            cons++;
        }
    }
    if(cons>= 4)
    {
        for(int i=0; i<l; i++)
        {
            if(nome[i]!= 'A' && nome[i]!= 'E' && nome[i]!= 'I' && nome[i]!= 'O' && nome[i]!= 'U')
            {
                codice[j] = nome[i];
                j++;
                conta++;
                c1 = i;
            }
            if(conta == 2)
            {
                break;
            }
        }
        conta-=1;
        j-=1;
        c1+=1;

        for(int i=c1; i<l; i++)
        {
            if(nome[i]!= 'A' && nome[i]!= 'E' && nome[i]!= 'I' && nome[i]!= 'O' && nome[i]!= 'U')
            {
                codice[j] = nome[i];
                j++;
                conta++;
            }
            if(conta == 3)
            {
                break;
            }
        }
    }

    if(cons==3)
    {
        for(int i=0; i<l; i++)
        {
            if(nome[i]!='A' && nome[i]!='E' && nome[i]!='I' && nome[i]!= 'O' && nome[i]!= 'U')
            {
                codice[j] = nome[i];
                j++;
                conta++;
            }
            if(conta==3)
            {
                break;
            }
        }
    }

    if(cons==2)
    {
        for(int i=0; i<l; i++)
        {
            if(nome[i]!= 'A' && nome[i]!= 'E' && nome[i]!= 'I' && nome[i]!= 'O' && nome[i]!= 'U')
            {
                codice[j] = nome[i];
                j++;
                conta++;
            }
        }

        for(int i=0; i<l; i++)
        {
            if(nome[i]== 'A' && nome[i]== 'E' && nome[i]== 'I' && nome[i]== 'O' && nome[i]== 'U')
            {
                codice[j] = nome[i];
                j++;
                conta++;
            }
            if(conta == 3)
            {
                break;
            }
        }
    }
    if(cons == 1)
    {
        for(int i=0; i<l; i++)
        {
            if(nome[i]!='A' && nome[i]!='E' && nome[i]!= 'I' && nome[i]!= 'O' && nome[i]!= 'U')
            {
                codice[j]=nome[i];
                j++;
                conta++;
            }
        }

        for(int i=0; i<l; i++)
        {
            if(nome[i]=='A'||nome[i]=='E'||nome[i]=='I'||nome[i]=='O'||nome[i]=='U')
            {
                codice[j] = nome[i];
                j++;
                conta++;
            }
            if(conta==3)
            {
                break;
            }

         }
    }
    if(cons == 0)
    {
        for(int i=0; i<l; i++)
        {
             codice[j] = nome[i];
             cout<<codice[j];
             j++;
             conta++;

             if(conta == 2)
             {
                break;
             }
        }
        cout<<"x";
    }
    while(conta != 3)
    {
        codice[j]='x';
    }

    return 0;
}

char *CalcolaCodice (char *codice)      // funzione che calcola il codice fiscale
{
    CodificaCognome(cognome);
    j=3;
    CodificaNome(nome);
    j=6;

    // dichiarazione variabili con dimensione atta ad evitare overflow della const NMAX
    char giorno [NMAX + sizeof(char)];
    char mese [NMAX + sizeof(char)];
    char anno [NMAX + sizeof(char)];
    // conversione INTtoCHAR
    sprintf(giorno, "%d", IntGiorno);
    sprintf (mese, "%d", IntMese);
    sprintf(anno, "%d", IntAnno);
    //selezione cifre anno per codice fiscale
    if(strlen(anno)== 4){
            codice[ 6 ] = anno[ 2 ];
            codice[ 7 ] = anno[ 3 ];
            posizione=8;
    }


    // selezione in file esterno della lettera corrispondente al numero del mese inserito e la copia nel codice
    string NumeroMese ;
    string LetteraMese;
    ifstream leggi4("LETTERA-MESE.txt");
        if(!leggi4)
        {
            cout << "Impossibile aprire il file..." << '\n';
        }
        Maiuscolo(luogo);

        while(leggi4.good())
        {
            getline(leggi4,NumeroMese,';');
            getline(leggi4,LetteraMese,'\n');

            if (mese== NumeroMese)
            {
                codice[8] = LetteraMese [0];
            }
        }
        leggi4.close();

    //algoritmo per il calcolo codice fiscale differenziato per sesso e giorno di nascita (+40 per le donne)
     l=strlen(giorno);
     Maiuscolo(sesso);

    if (sesso [0] == 'M')
    {
        if( l == 1)
        {
            codice[ 9 ] = '0';
            codice[ 10 ] = giorno[0];
        }
        else
        {
            codice[ 9 ] = giorno[ 0 ];
            codice[ 10 ] = giorno[ 1 ];
        }
    }
    if (sesso [0] == 'F')
    {
        if( l == 1)
        {
            codice[ 9 ] = '4';
            codice[ 10 ] = giorno[0];
        }
        else
        {
            giornoF [0] = giorno [0] + 4 ;
            codice[ 9 ] = giornoF [ 0 ];
            codice[ 10 ] = giorno[ 1 ];
        }
    }

// selezione in file esterno del codice catastale corrispondente al comune del luogo di nascita inserito inserito e la copia nel codice
// se il luogo di nascita non corrisponde ad alcun comune nel file, il codice mancherà di quella porzione

    ifstream leggi1("COMUNI.csv");
    if(!leggi1)
    {
        cout << "Impossibile aprire il file..." << '\n';
    }
    Maiuscolo(luogo);

    while(leggi1.good())
    {
        getline(leggi1,comune,';');
        getline(leggi1,codiceCatastale,'\n');

        if (luogo == comune)
        {
            codice[11] = codiceCatastale [0];
            codice[12] = codiceCatastale [1];
            codice[13] = codiceCatastale [2];
            codice[14] = codiceCatastale [3];
        }
    }
    leggi1.close();

//Calcolo ultima cifra codice fiscale (CIFRA DI CONTROLLO)

    ifstream leggi2("VALORE-CIFRE-PARI-DISPARI.txt");
    if (!leggi2)
    {
        cout << "Impossibile aprire il file...";
    }
    else
    {
        while ( leggi2.good())                  // sommiamo le cifre pari e le cifre dispari che serviranno poi ad ottenere la cifra di controllo
        {
            getline(leggi2, Cifra, ';');
            getline(leggi2, ValoriPari_str, ';');
            getline(leggi2, ValoriDispari_str,'\n');

            ValoriPari = stoi(ValoriPari_str);
            ValoriDispari = stoi(ValoriDispari_str);

            CifraCercata=codice[0];
            if (CifraCercata == Cifra)
                    SommaDispari= SommaDispari + ValoriDispari;
            CifraCercata=codice[1];
            if (CifraCercata == Cifra)
                    SommaPari= SommaPari + ValoriPari;
            CifraCercata=codice[2];
            if (CifraCercata == Cifra)
                    SommaDispari= SommaDispari + ValoriDispari;
                    CifraCercata=codice[3];
            if (CifraCercata == Cifra)
                    SommaPari= SommaPari + ValoriPari;
            CifraCercata=codice[4];
            if (CifraCercata == Cifra)
                    SommaDispari= SommaDispari + ValoriDispari;
                    CifraCercata=codice[5];
            if (CifraCercata == Cifra)
                    SommaPari= SommaPari + ValoriPari;
            CifraCercata=codice[6];
            if (CifraCercata == Cifra)
                    SommaDispari= SommaDispari + ValoriDispari;
                    CifraCercata=codice[7];
            if (CifraCercata == Cifra)
                    SommaPari= SommaPari + ValoriPari;
            CifraCercata=codice[8];
            if (CifraCercata == Cifra)
                    SommaDispari= SommaDispari + ValoriDispari;
                    CifraCercata=codice[9];
            if (CifraCercata == Cifra)
                    SommaPari= SommaPari + ValoriPari;
            CifraCercata=codice[10];
            if (CifraCercata == Cifra)
                    SommaDispari= SommaDispari + ValoriDispari;
                    CifraCercata=codice[11];
            if (CifraCercata == Cifra)
                    SommaPari= SommaPari + ValoriPari;
            CifraCercata=codice[12];
            if (CifraCercata == Cifra)
                    SommaDispari= SommaDispari + ValoriDispari;
                    CifraCercata=codice[13];
            if (CifraCercata == Cifra)
                    SommaPari= SommaPari + ValoriPari;
            CifraCercata=codice[14];
            if (CifraCercata == Cifra)
                    SommaDispari= SommaDispari + ValoriDispari;
                    CifraCercata=codice[15];
            if (CifraCercata == Cifra)
                    SommaPari= SommaPari + ValoriPari;

/* /////////////////////////////////////////////////////////////////////Ciclo for non funzionante
                for (int i=0; i<15; i++)
                {
                    CifraCercata=codice[i];
                    if(i%2==0)//controlla se é divisibile per 2
                    {
                        if (CifraCercata == Cifra)
                        {
                            SommaPari= SommaPari + ValoriPari;
                        }
                    }
                    else
                    {
                        if (CifraCercata == Cifra)
                        {
                            SommaDispari= SommaDispari + ValoriDispari;
                        }
                    }
                }
*/
        }
    }

    leggi2.close();

    Somma= SommaPari + SommaDispari;
    resto = Somma%26;

    ifstream leggi3( "Cifra-Controllo.txt");
    if (!leggi3)
    {
        cout << "Impossibile aprire il file...";
    }
    else
    {
        while ( leggi3.good())
        {
            getline(leggi3, Cifra, ';');
            getline(leggi3, Lettera_str, '\n');
            CifraCercata = to_string(resto);

            if (CifraCercata == Cifra)
            {
               codice[15] = Lettera_str.at(0);
               break;
            }
        }
    }
    leggi3.close();
}


char *StampaCodice(char *codice)                       // funzione che stampa a schermo il codice fiscale completo
{
    l=strlen(codice);

    for(j=0 ; j<16 ;j++)
    {
    cout << codice[ j ] << " ";
    }
    cout << endl;

// easter egg

    if (strcmp (codice,"MRNGTN00D27L259B")==0)
    {
         cout<< "WINTER IS COMING"<<endl;
    }
     if (strcmp (codice, "NVOGNN00L28F912T")==0)
    {
         cout<< "E' il tempo che hai perduto per la tua rosa \nche ha reso la tua rosa cosi' importante"<<endl;
    }
     if (strcmp(codice, "MRACSM00R11F912A" )==0)
    {
         cout<< "Alcune persone non meritano il nostro sorriso, \nfiguriamoci le nostre lacrime."<<endl;
    }
}



bool bisestile(int aa)                                // funzione atta a verificare se l'anno inserito è bisestile, al fine di abilitare il 29 febbraio
{/* bisestile: se l'anno è divisibile x 400 oppure divisibile x 4 ma non x 100 */

     if(aa%400==0 || (aa%4==0 && aa%100!=0))
     {return true;}
     else
     {return false;}
}



int giornimese(int aa,int mm)                         // funzione atta a definire quanti giorni ci sono in ogni mese
{
    switch (mm)
    {
        case 2:
        if (bisestile(aa)==true)
        {return 29;}
        else
        {return 28;}
        case 4:
        case 6:
        case 9:
        case 11:
        {return 30;}
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        {return 31;}
    }
}

bool datavalida(int gg,int mm,int aa)                 // funzione atta a verificare la validità della data di nascita inserita
{
    if (aa>=1800 && aa<9999 && mm>0 && mm<13 && gg>0 && gg<=giornimese(aa,mm))
    {return true;}
    else
    {return false;}
}


bool sessovalido(string sex)                         // funzione atta a verificare la validità del sesso biologico inserito
{
    if (sex == "M" || sex=="F" || sex == "m" || sex == "f" ){
        return true;}
    else {return false;}
}

bool sceltavalida(string sceltafrase)                // funzione che consente all'utente di decidere se inserire o meno la frase nell'anagrafica
{
    if (sceltafrase == "Si" || sceltafrase =="si" || sceltafrase =="SI" || sceltafrase =="sI" ){
        return true;}
    else {return false;}
}


void inseriscidata(int &gg ,int &mm,int &aa)         // funzione che consente l'inserimento della data di nascita
{
     cout<<"Giorno di nascita:";
     cin>>IntGiorno;
     cout<<"Mese di nascita:";
     cin>>IntMese;
     cout<<"Anno di nascita:";
     cin>>IntAnno;
    }


void Immisione_dati(char *nome,char *cognome,char *luogo,char *sigla,char* sesso, char* frase) // funzione che permette l'input dei dati per l'anagrafica dell'utente
{
    cout<<"L'inserimento dei dati deve essere seguito da un invio."<<endl;
    cout<< endl;
    cout<<"Nome: ";
    cin>>nome;
    cout<<"Cognome: ";
    cin>> cognome;
    cout<< endl;
    inseriscidata(IntGiorno,IntMese,IntAnno);
    if(datavalida(IntGiorno,IntMese,IntAnno)==true)
    {
        cout<<endl;
    }
    else if(datavalida(IntGiorno,IntMese,IntAnno)==false)
    {
        cout<<"La data di nascita inserita non e' corretta, ripetiamo l'inserimento dei dati " <<endl;
        return;
    }

        cout<<"Luogo di nascita (senza spazi, apostrofi o accenti): ";
        cin>>luogo;
        cout<<"Sigla provincia di nascita: ";
        cin>>sigla;
        cout<<endl;

        cout<<"inserire il proprio sesso tra 'M' e 'F': ";
        cin>>sesso;
        sessovalido(sesso);
        if (sessovalido(sesso)== true){
            cout<<endl;
            }
        else if (sessovalido(sesso)== false){
            cout<<"Il sesso inserito non é valido, ripetiamo l'inserimento dei dati "<<endl;
            return;
        }

        cout<<"Vuoi inserire una nota personale? (Inserire SI per SI e una qualsiasi lettera per NO) "<< endl;
        cin>> sceltafrase;
        sceltavalida(sceltafrase);
        if (sceltavalida(sceltafrase)== true)
        {
            cout<<"Inserire una nota personale senza spazi: "<<endl;
            cin>>frase;
        }

    return;
    }

void anagrafica (char *nome,char *cognome,char *luogo,char *sigla,char* sesso)             // funzione atta alla stampa dell'anagrafica inserita in input
{
    cout<<endl;
    cout<<"lettura anagrafica inserita:"<<endl;
    cout<<"Nome: "<<nome<<endl;
    cout<<"Cognome: "<<cognome<<endl;
    cout<<"Data di nascita:"<<IntGiorno<<"/"<<IntMese<<"/"<<IntAnno<<endl;
    cout<<"Luogo di nascita:"<<luogo<<endl;
    cout<<"Sigla provincia di nascita: "<<sigla<<endl;
    cout<<"Sesso: "<<sesso<<endl;
    if(sceltavalida(sceltafrase)==true)
    {cout<<"Frase personale: "<<frase<<endl;
    }
    cout<<endl;
}

 void menu()                                          // funzione menù
{
     system("cls");                                  // cls che ripulisce di volta in volta la schermata
     cout<<"-----INTERFACCIA MENU'-----"<<endl;
     cout<<"1)Inserimento/modifica anagrafica"<<endl;
     cout<<"2)Calcola Codice Fiscale"<<endl;
     cout<<"3)Sola lettura anagrafica"<<endl;
     cout<<"4)Esci"<<endl;
     return;
}
    //////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    //presentazione del dispositivo//
    cout<<"Benvenuto nuovo utente nel Calcolatore di Codice Fiscale. "<< endl;
    cout<<"Preghiamo l'utente di memorizzare i suoi dati per generare un profilo."<<endl;
    system("pause");    // chiede un input da tastiera all'utente per proseguire

    do
    {
        menu();
        cout<<"inserisci una scelta[1-4]: ";
        cin>>scelta;
        cin.ignore(200,'\n'); // evito di avere problemi se l'utente inserisce un carattere non numerico o più di un carattere
        switch(scelta)
        {
            case '1':
            cout<<"inserisci/modifica:"<<endl;
            Immisione_dati (nome, cognome, luogo, sigla, sesso, frase);
            system("pause");
            break;

            case '2':
            cout<<"calcolo codice fiscale in corso"<<endl;
            CalcolaCodice(codice);
            StampaCodice(codice);
            system("pause");
            break;

            case '3':
            cout<<"sola lettura anagrafica:"<<endl;
             anagrafica(nome,cognome,luogo,sigla,sesso);
             system("pause");
            break;

            case '4':
            return 0;
            break;


            default:
            cout<<"Attenzione scelta sbagliata!"<<endl;
            system("pause");
        }
    }

    while(scelta!='4');
    return 0;

} /* chiude main()*/


