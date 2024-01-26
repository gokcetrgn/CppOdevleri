// 413606 Gökçenaz Torgan & 413140 Hatice Çeçen


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
const int candidates = 4;

void dizi_elemanlari_al(string dizi[], int boyut, ifstream &inFile)
{
    for (int i = 0; i < boyut; i++)
    {
        inFile >> dizi[i];
    }
}

void dizi_elemanlarini_sirala(string dizi[], int boyut)
{
    // alfabetik olarak sıralandı
    for (int i = 0; i < boyut; i++)
    {
        for (int j = i + 1; j < boyut; j++)
        {
            if (dizi[i] > dizi[j])
            {
                string temp = dizi[i];
                dizi[i] = dizi[j];
                dizi[j] = temp;
            }
        }
    }
}
// overloading kullanıldı
void dizileri_ilkle(int dizi[], int boyut){
    for (int i = 0; i < boyut; i++)
    {
        dizi[i] = 0;
    }

}
void dizileri_ilkle(int dizi[][candidates], int boyut){
    for (int i = 0; i < boyut; i++)
    {
        for (int j = 0; j < candidates; j++)
        {
            dizi[i][j] = 0;
        }
    }

}
void oylari_al(int dizi[][candidates], int boyut, ifstream &inFile)
{
    // dosyadan oylar alındı ama her ad'a ayrı ayrı işlem yapıldı
    string ad;
    int bolge, oylar;

    for (int i = 0; i < boyut; i++)
    {
        for (int j = 0; j < candidates; j++)
        {
            inFile >> ad >> bolge >> oylar;
            if (ad == "Balto")
            {
                dizi[0][bolge - 1] = oylar;
            }
            else if (ad == ("Doc"))
            {
                dizi[1][bolge - 1] = oylar;
            }
            else if (ad == ("Donald"))
            {
                dizi[2][bolge - 1] = oylar;
            }
            else if (ad == ("Goofy"))
            {
                dizi[3][bolge - 1] = oylar;
            }
            else if (ad == ("Mickey"))
            {
                dizi[4][bolge - 1] = oylar;
            }
            else if (ad == ("Pluto"))
            {
                dizi[5][bolge - 1] = oylar;
            }
        }
    }
}
void oylari_topla(int dizi[][candidates], int boyut, int dizi2[], int &totalVotes)
{
    int toplam = 0;
    for (int i = 0; i < boyut; i++)
    {
        toplam = 0;
        for (int j = 0; j < candidates; j++)
        {
            toplam += dizi[i][j];
        }
        dizi2[i] = toplam;
        totalVotes += toplam;
    }
}

void konsolda_goster(int dizi[][candidates], int boyut, string dizi2[], int dizi3[])
{
    cout << "   --------------Election Results--------------   " << endl;
    cout << "Candidate" << setw(25) <<  "Votes" << endl;
    cout << "  Name" << setw(12) << "  Region1" << setw(12) << "  Region2" << setw(12) << "  Region3" << setw(12) << "  Region4" << setw(15) << "Total" << endl;
    cout << "------" << setw(12) << "------" << setw(12) << "------" << setw(12) << "------" << setw(12) << "------" << setw(15) << "------" << endl;

    cout.fill(' ');
    cout.precision(2);

    for (int i = 0; i < boyut; i++)
    {
        cout << setw(7) << dizi2[i] << setw(10) << dizi[i][0] << setw(10) << dizi[i][1] << setw(10) << dizi[i][2] << setw(15) << dizi[i][3] << setw(15) << dizi3[i] << endl;
    }
}
void whoisWinner(int dizi2[], int boyut, string dizi3[])
{
    int maxNumber = dizi2[0];
    int index = 0;
    for (int i = 0; i < boyut; i++)
    {
        if (maxNumber < dizi2[i])
        {
            maxNumber = dizi2[i];
            index = i;
        }
    }
    cout << "Winner:" << dizi3[index] << ", Votes Received:" << maxNumber << endl;
}

int main()
{

    string candidatesName[6];
    int votesTotal = 0;

    // dosya işlemleri
    ifstream candidateName;
    ifstream votes;

    // dosyalar açıldı
    candidateName.open("candDat.txt");
    votes.open("voteData.txt");

    // fonksiyonlar
    dizi_elemanlari_al(candidatesName, 6, candidateName);
    dizi_elemanlarini_sirala(candidatesName, 6);

    // dizileri oluşturdum
    int votesByRegion[6][4];
    int totalVotes[6];

    // dizileri ilkledik
    dizileri_ilkle(votesByRegion,6);
    dizileri_ilkle(totalVotes,6);
    
    // dosyadan oylar alındı
    oylari_al(votesByRegion, 6, votes);
    // oylar toplanıp bir diziye konuldu
    oylari_topla(votesByRegion, 6, totalVotes, votesTotal);
    // konsolda gösterebilmek için
    konsolda_goster(votesByRegion, 6, candidatesName, totalVotes);
    // kimin kazandığını belirlemek için
    whoisWinner(totalVotes, 6, candidatesName);
    cout << "Total votes polled: " << votesTotal << endl;


    // dosyalar kapatıldı
    candidateName.close();
    votes.close();

    return 0;
}