#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <exception>

using namespace std;

struct tiedot{
    int numero = rand() % 99999 + 10000;
    char etunimi[20];
    char sukunimi[20];
    int ika;
};
void lista()
{

    try{
        ifstream lista1("testi2.txt");

        if(!lista1){
        cerr << "Ei aukea!! 'testi2.txt'!" << endl;
        exit(1);
}
        string line;
        list<string> listani;

            while (getline(lista1,line)){
            listani.push_back(line);
            cout << listani.back() << endl;
}
}
        catch(const exception& ex){}
}

void lisenssi()
{
       tiedot s;
       ofstream tiedosto("testi2.txt", ios::app);

       if(tiedosto.is_open()){
      cout << "Kirjoita etunimesi:  ";
            cin>>s.etunimi;
            tiedosto<<s.etunimi<< ' ';
       cout << "Kirjoita sukunimesi: ";
            cin>>s.sukunimi;
            tiedosto<<s.sukunimi<< ' ';
       cout << "Kirjoita ikasi: ";
            cin>>s.ika;
            tiedosto<<s.ika<< ' ';
       cout << "Nimesi on " << s.etunimi << " " << s.sukunimi<<" " << s.ika<<'\n';

       cout <<"lisenssi numerosi on: ";
       cout << s.numero<<"\n";
            tiedosto<<s.numero<< endl;
            tiedosto.close();
}
}
void tyhjennys()
{
        ifstream tiedosto;
        string tiedosto2 = "testi2.txt";

        tiedosto.open(tiedosto2.c_str(), ifstream::out | ifstream::trunc );
        cout << "Tyhjennetty!"<< endl;

            if (!tiedosto.is_open() || tiedosto.fail()){
}
        tiedosto.close();
}

int main(){
srand(time(NULL));
        int valinta;
        do{
            cout << "0. Lopeta" <<endl <<"1. Hanki lisenssi\n" <<"2. Lista\n"<<"3. Listan tyhjennys\n";
            cin >> valinta;
            switch(valinta){
                case 0:
                cout <<"Kiva kun koitit!\n";
                return 0;
                case 1:
                lisenssi();
                return 0;
                case 2:
                lista();
                return 0;
                case 3:
                tyhjennys();
                return 0;
}

}
        while(valinta != 0);
}
