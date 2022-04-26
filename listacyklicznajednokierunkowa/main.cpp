#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
struct element{
int nr;
element *next;
};

void Dodajnaprawo(element *biezacy,int nr){
    element *el;
if(biezacy->next==nullptr){
        cout<<"Lista jest pusta tworzenie nowego elementu bierzacego"<<endl;
        biezacy->nr=nr;
        biezacy->next=biezacy;
}
else if(biezacy->next==biezacy){

    el=new element;
    el->nr=nr;
    el->next=biezacy;
    biezacy->next=el;
}
else{
    el=new element;
    el->nr=nr;
    el->next=biezacy->next;
    biezacy->next=el;
}

};

void DodajnaPozycje(element *biezacy,int nr){
int licznik=1;
int pozycja;
if(biezacy->next==nullptr){
    cout<<"Lista jest pusta mozna dodac tylko pierwszy element"<<endl;
    cout<<"Wpisz 1 jesli chcesz dodac"<<endl;
    cin>>pozycja;
    if(pozycja==1){
    Dodajnalewo(biezacy,nr);
    }
}
else {

    cout<<"Podaj pozycje na jaka chcesz dodac element"<<endl;
    cin>>pozycja;
    element *pom;
    pom=biezacy;
    if(pozycja==1){
        Dodajnalewo(biezacy,nr);
    }
    else{
    while(licznik<(pozycja-1) && pom->next!=biezacy){
        pom=pom->next;
        licznik++;
    }
    if(licznik==pozycja-1){
        Dodajnaprawo(pom,nr);
    }
    else{
        cout<<"Nie mozna dodac na ta pozycje !"<<endl;
    }

}
}
};
void Usunnaprawo(element *biezacy){
    element *pom;
if(biezacy->next==nullptr){
    cout<<"Lista jest pusta nie ma co usunac !"<<endl;
}
else if(biezacy->next==biezacy){
    cout<<"Jest jeden element nie ma nic na prawo !"<<endl;
}
else {
    pom=biezacy->next;
    biezacy->next=pom->next;
    delete pom;

}
};


void Usunzpozycji(element *biezacy){
int pozycja;
if(biezacy->next==nullptr){
    cout<<"Lista jest pusta nie ma co usunac !"<<endl;
}
else if(biezacy->prev==biezacy){
    cout<<"Jest jeden element wpisz 1 jesli chcesz go usunac "<<endl;
    cin>>pozycja;
    if(pozycja==1){
        biezacy->next=nullptr;
        biezacy->prev=nullptr;
    }
}
else{
  cout<<"Podaj z jakiej pozycji chcesz usunac element"<<endl;
  cin>>pozycja;
   element *pom;
    pom=biezacy;
  if(pozycja==1){
    biezacy=biezacy->next;
    biezacy->prev=pom->prev;
    pom->prev->next=biezacy;
    delete pom;
  }
  else{
    int i=1;
    while(i<(pozycja-1) && pom->next!=biezacy){
        pom=pom->next;
        i++;
    }
    if(i==pozycja-1){
        element *pom2;
        pom2=pom->next;
        pom->next=pom2->next;
        delete pom2;
    }
    else {
        cout<<"Nie da sie usunac elementu z tej pozycji"<<endl;
    }
  }
}

};
void WyswietlodPoczatku(element *biezacy){
if(biezacy->next==nullptr){
    cout<<"Lista jest pusta !"<<endl;
}
else{
element *pom=biezacy;
do{
    cout<<pom->nr<<endl;
    pom=pom->next;
}while(pom!=biezacy);
}
};

void Usunwszystkie(element *biezacy){
while(biezacy->next!=nullptr){
    if(biezacy->next==biezacy){
        biezacy->next=nullptr;
    }
    else{
        Usunnaprawo(biezacy);
    }
}
cout<<"Lista jest teraz pusta"<<endl;
};
int WyswietlMin(element *biezacy){
if(biezacy->next==nullptr){
    return 0;
}
else {
    element *pom=biezacy;
    int Min;
    Min=biezacy->nr;
    do{
    pom=pom->next;
    if(pom->nr<Min){
        Min=pom->nr;
    }

    }while(pom!=biezacy);
    return Min;
}
};
void ZnajdzMin(element *biezacy){
if(biezacy->next==nullptr){
        cout<<"Lista jest pusta"<<endl;
}
else{
int Min,ile;
ile=1;
Min=51;
int i1=1;
element*pom=biezacy;
int *poz;
poz=new int[ile];
if(biezacy->next==biezacy){
    Min=biezacy->nr;
    poz[0]=1;
}
else{
do{
    if(Min>pom->nr){
        Min=pom->nr;
        ile=1;
        poz[0]=i1;
    }
    else if(Min==pom->nr){
        ile++;
        poz[ile-1]=i1;
    }
    pom=pom->next;
    i1++;
}while(pom!=biezacy);
}
cout<<"Wartosc minimalnego elementu wynosi : "<<Min<<endl;
cout<<"I pojawia sie on na pozycji/ach: ";
int i=0;
while(i<ile){
    cout<<poz[i]<<", ";
    i++;
}
cout<<endl;
}
};


int Ileelementow(element*biezacy){
element *pom=biezacy;
int licznik=0;
do{
pom=pom->next;
licznik++;

}while(pom!=biezacy)

};



int main()
{
srand(time(NULL));

        cout<<"Zadanie 11.1"<<endl;
        element *lista;
        lista->next=nullptr;
        int wybor1,numer;


        do{
                do{
                cout<<"Wybierz co chcesz zrobic :"<<endl
                <<"1-Sprawdzenie czy lista jest pusta"<<endl
                <<"2-Dodanie elementu na koniec listy"<<endl
                <<"3-Dodanie elementu na okreslona pozycje"<<endl
                <<"4-Usuniecie elementu z konca listy"<<endl
                <<"-Usuniecie elementu z poczatku listy"<<endl
                <<"7-Usuniecie elementu znajdujacego sie na okreslonej pozycji "<<endl
                <<"8-Pobranie pierwszego elementu z listy"<<endl
                <<"9-Pobranie ostatniego elementu z listy"<<endl
                <<"10-Policzenie sredniej arytmetycznej elementow na liscie"<<endl
                <<"11-Znalezienie maksymalnego elementu na liscie"<<endl
                <<"12-Wyswietlenie calej listy"<<endl
                <<"13-Usuniecie calej listy wraz ze zwolnieniem pamieci"<<endl
                <<"14-Wyjscie z programu"<<endl;

                cin>>wybor1;
                cout<<endl;
                }while(wybor1<1 || wybor1 >14);
                switch(wybor1){
            case 1:
                {
                if(l.counter==0) cout<<"Lista jest pusta"<<endl;

                else cout<<"Lista nie jest pusta"<<endl;
                }break;
            case 2:
                {
                    numer=(rand()%50)+1;
                  DodajOgon(l,numer);
                }break;
            case 3:
                {
                  numer=(rand()%50)+1;
                  DodajGlowe(l,numer);

                }break;
            case 4:
                {
                    if(l.counter==0){
                        cout<<"Lista jest pusta wiec nie mozna wybrac pozycji "<<endl;
                    }
                    else{
                    int pozycja;
                    cout<<"Podaj pozycje na jaka chcesz dodac element "<<endl;
                 cin>>pozycja;
                    if(pozycja<1 || pozycja>(l.counter+1)){
                            cout<<"Nie mozna dodac elementu na ta pozycje !"<<endl;
                    }
                    else if(pozycja==1){
                           numer=(rand()%50)+1;
                        DodajGlowe(l,numer);
                   }
                    else if(pozycja==(l.counter+1)){
                        numer=(rand()%50)+1;
                        DodajOgon(l,numer);
                    }
                    else{
                 numer=(rand()%50)+1;
                 DodajNaPozycje(l,numer,pozycja);
                    }
                }
                }break;
            case 5:
                {
                 if(l.counter==0){
                    cout<<"Lista jest pusta nie mozna nic usunac!"<<endl;
                 }
                 else{
                    UsunOgon(l);
                 }


                }break;
            case 6:
                {
                  if(l.counter==0){
                    cout<<"Lista jest pusta nie mozna nic usunac!"<<endl;
                 }
                 else{
                    UsunGlowe(l);
                 }

                }break;
            case 7:
                {   int pozycja;
                    if(l.counter==0){
                        cout<<"Lista jest pusta nie mozna nic usunac !"<<endl;
                    }
                    else{
                        cout<<"Podaj pozycje z jakiej chcesz usunac element"<<endl;
                        cin>>pozycja;
                        if(pozycja<1 || pozycja>l.counter){
                            cout<<"Nie ma takiej pozycji na liscie !"<<endl;
                        }
                        else if(pozycja==1){
                            UsunGlowe(l);
                        }
                        else if(pozycja==l.counter){
                            UsunOgon(l);
                        }
                        else{
                            UsunPozycje(l,pozycja);
                        }

                    }

                }break;
            case 8:
                {
                    if(l.counter==0){
                        cout<<"Lista jest pusta !"<<endl;
                    }
                    else{
                        cout<<l.head->nr<<endl;
                    }


                }break;
            case 9:
                {
                 if(l.counter==0){
                        cout<<"Lista jest pusta !"<<endl;
                    }
                    else{
                        cout<<l.tail->nr<<endl;
                    }


                }break;
            case 10:
                {   int suma,srednia;
                if(l.counter==0){
                    cout<<"Lista jest pusta !"<<endl;
                }
                else{
                        int nr;
                element*pom=l.head;
                int i=1;
                suma=0;
                while(i<=l.counter){
                    nr=pom->nr;
                    suma=suma+nr;
                    pom=pom->next;
                    i++;
                }
                srednia=suma/(l.counter);
                cout<<"Srednia arytmetyczna wynosi: "<<srednia<<endl;
                }
                }break;
            case 11:
                {
                    int maks;
                if(l.counter==0){
                    cout<<"Lista jest pusta !"<<endl;
                }
                else{
                  element*pom=l.head;
                  maks=0;
                  int i=1;
                  int poz;
                  while(i<=l.counter){
                    if(pom->nr>=maks){
                        maks=pom->nr;
                        poz=i;
                    }
                     pom=pom->next;
                    i++;
                  }
                  cout<<"Wartosc maksymalnego elementu wynosi: "<<maks<<endl;
                  cout<<"I znajduje sie na pozycji :  "<<poz<<endl;
                }
                }break;
            case 12:
                {
                    if(l.counter==0){
                        cout<<"Lista jest pusta "<<endl;
                    }
                    else{
                        PokarzWszystkie(l);
                    }

                }break;
                case 13:
                    {
                     while(l.counter>0){
                        UsunGlowe(l);
                     }
                     cout<<"Lista jest pusta"<<endl;



                    }break;
                default:
                    {
                        cout<<"Do widzenia !"<<endl;
                    }break;


                }
cout<<endl;
        }while(wybor1!=14);

    return 0;
}
