//kure Dominykas Rakunas, nusivyles po egzamino
#include <bits/stdc++.h> // visos bibliotekos

using namespace std;

struct indas{ //indo info
    int turimi;
    int liko;
    int prireike = 0;
    int kaina;
};

void skaiciuoti(
    indas & indai_1,
    indas & indai_3,
    indas & indai_5,
    int & aliejus_turimas,
    int & aliejus_likes);

int main()
{
    ifstream in("U1.txt");
    ofstream out("U1rez.txt");
    indas indai_1; // 1 litro indo info
    indas indai_3;
    indas indai_5;
    int aliejus_turimas;
    int aliejus_likes;
    int aliejus_islaidos;
    int pelnas = 0;

    in>>indai_1.turimi; // surasomi duomenys
    in>>indai_3.turimi;
    in>>indai_5.turimi;
    in>>aliejus_turimas;
    in>>aliejus_islaidos;
    in>>indai_1.kaina;
    in>>indai_3.kaina;
    in>>indai_5.kaina;

    indai_1.liko = indai_1.turimi; // sulyginami, kad veliau butu galima rasti skirtuma panaudotu indu
    indai_3.liko = indai_3.turimi;
    indai_5.liko = indai_5.turimi;

    skaiciuoti(indai_1, // apskaiciuoja likucius
               indai_3,
               indai_5,
               aliejus_turimas,
               aliejus_likes);

    while(aliejus_turimas>0){ // skaiciuoja kiek prireikia likusiam aliejui indu
        if(aliejus_turimas>=5){
            aliejus_turimas-=5;
            indai_5.prireike ++;
        }else if(aliejus_turimas>=3){
            aliejus_turimas-=3;
            indai_3.prireike ++;
        }else{
            aliejus_turimas-=1;
            indai_1.prireike++;
        }
    }

    pelnas -=aliejus_islaidos; // skaiciuojamas pelnas
    pelnas += ( indai_1.turimi - indai_1.liko ) * indai_1.kaina;
    pelnas += ( indai_3.turimi - indai_3.liko ) * indai_3.kaina;
    pelnas += ( indai_5.turimi - indai_5.liko ) * indai_5.kaina;
    pelnas += indai_1.prireike * indai_1.kaina;
    pelnas += indai_3.prireike * indai_3.kaina;
    pelnas += indai_5.prireike * indai_5.kaina;

    out<<indai_1.turimi - indai_1.liko<<" "; // surasoma i tekstini faila
    out<<indai_3.turimi - indai_3.liko<<" ";
    out<<indai_5.turimi - indai_5.liko<<" ";
    out<<aliejus_likes<<endl;

    out<<indai_1.liko<<" ";
    out<<indai_3.liko<<" ";
    out<<indai_5.liko<<endl;

    out<<indai_1.prireike<<" ";
    out<<indai_3.prireike<<" ";
    out<<indai_5.prireike<<endl;

    out<<pelnas;

    in.close(); // uzdoroma
    out.close();
    return 0;
}
void skaiciuoti(
    indas & indai_1,
    indas & indai_3,
    indas & indai_5,
    int & aliejus_turimas,
    int & aliejus_likes){

    for(int i=0; i<indai_5.turimi; i++){ // prasuka cikla kol uzpildo visus po 5 litrus indus
        if(aliejus_turimas-5>0){
            aliejus_turimas-=5;
            indai_5.liko--;
        }
    }
    for(int i=0; i<indai_3.turimi; i++){ // tada prasuka, kol uzpildo po 3
        if(aliejus_turimas-3>0){
            aliejus_turimas-=3;
            indai_3.liko--;
        }
    }
    for(int i=0; i<indai_1.turimi; i++){ // tada prasuka, kol uzpildo po 1
        if(aliejus_turimas-1>0){
            aliejus_turimas-=1;
            indai_1.liko--;
        }
    }

    aliejus_likes = aliejus_turimas; // issisaugoja likuti
}
