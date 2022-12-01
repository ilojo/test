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
void lisenssi()
{
       tiedot s;
       ofstream tiedosto("C:/testi/testi2.txt", ios::app);

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


}
       tiedosto.close();
}

void haku(){

       char line[500];
       char haku1[20];
       int i;

       ifstream tiedosto;

       tiedosto.open("C:/testi/testi2.txt");
       cout<<"Haku: ";
       cin>>haku1;

        if (tiedosto.is_open() ){
        while ( !tiedosto.eof() ){
            tiedosto.getline(line, 500, ',');
            for (i = 0;line[i] == haku1[i];i++)
{
                if (haku1[i] == 0)
{
                    cout << "Osuma!!" << endl;
                    cout << line << endl;
}
}
            for (int j = 0;j < 3;j++) tiedosto.getline(line, 500, ',');
            tiedosto.getline(line, 500, '\n');
}
                    cout << "Ei osumaa!!" << endl;
}
    else
{
                     cout << "Ei aukee!!" << endl;
}
            tiedosto.close();
}

void lista()
{
       ifstream tiedosto("C:/testi/testi2.txt");

       if(!tiedosto){

       cout << "Ei aukea!!!" << endl;
       exit(1);

}
       string line;
       list<string> listani;

           while (getline(tiedosto,line)){
           listani.push_back(line);


           cout << listani.back()  << endl;
}
           tiedosto.close();


}

void tyhjennys()
{
        ifstream tiedosto;
        string tiedosto2 = "C:/testi/testi2.txt";

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
            cout << "0. Lopeta" <<endl <<"1. Hanki lisenssi\n" <<"2. Lista\n"<<"3. Listan tyhjennys\n" << "4. Haku\n";
            cin >> valinta;
            switch(valinta){
                case 0:
                cout <<"Kiva kun koitit!\n";
                return 0;
                case 1:
                lisenssi();
                return main();
                case 2:
                lista();
                return main();
                case 3:
                tyhjennys();
                return main();
                case 4:
                haku();
                return main();
}

}
        while(valinta != 0);
}
