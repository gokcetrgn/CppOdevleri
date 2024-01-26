// 413606 Gökçenaz Torgan & 413140 Hatice Çeçen


#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void diziElemanlariToplama(int dizi[], int dizi2[], int dizininBoyutu, ofstream &outFile) {
    int toplamDizisi[5];

    for(int i = 0; i < dizininBoyutu; i++) {
        toplamDizisi[i] = dizi[i] + dizi2[i];
    }

    outFile << "Toplama isleminin sonucu: ";
    for(int k = 0; k < dizininBoyutu; k++) {
        outFile << toplamDizisi[k] << " ";
    }
    outFile << endl;
}

void diziElemanlariCarpma(int dizi[], int dizi2[], int dizininBoyutu, ofstream &outFile) {
    int carpimDizisi[5];

    for(int i = 0; i < dizininBoyutu; i++) {
        carpimDizisi[i] = dizi[i] * dizi2[i];
    }

    outFile << "Carpma isleminin sonucu:: ";
    for(int k = 0; k < dizininBoyutu; k++) {
        outFile << carpimDizisi[k] << " ";
    }
    outFile << endl;
}

void tekCiftDiziler(int dizi[], int boyut, ofstream &outFile) {
    outFile << "Tek sayilari tutan dizi: ";
    for(int k = 0; k < boyut; k++) {
        if(dizi[k] % 2 != 0) {
            outFile << dizi[k] << " ";
        }
    }
    outFile << endl;

    outFile << "Cift sayilari tutan dizi: ";
    for(int k = 0; k < boyut; k++) {
        if(dizi[k] % 2 == 0) {
            outFile << dizi[k] << " ";
        }
    }
    outFile << endl;
}

int main() {
    int eleman;

    cout << "Dizinin eleman sayisini giriniz: " << endl;
    cin >> eleman;

    int dizi[eleman];

    // Kullanıcıdan bir dizi (dizinin ismi dizi1 olarak adlandırılmalıdır) girişi istenmelidir. dizi1'in boyutu ve elemanları kullanıcıdan alınmalıdır

    cout << "Birinci diziye ait " << eleman <<  " eleman girin: " << endl;
    for(int i = 0; i < eleman; i++) {
        cin >> dizi[i];
    }

    ifstream inFile; // input file stream değişkeni

    ofstream outFile; // output file stream değişkeni

    int dizininBoyutu; // dizi2'nin boyutu ve elemanları için değişkenler

    inFile.open("input.txt");
    outFile.open("output.txt");


    inFile >> dizininBoyutu; // input dosyasından dizi için boyut alıyoruz

    int dizi2[dizininBoyutu]; // ikinci diziyi oluşturduk

    for(int j = 0; j < dizininBoyutu; j++) {
        inFile >> dizi2[j];
    }
    // ikinci dizinin elemanlarını aldık.

    //aşağıda da iki dizi ile ilgili işlemleri yaptık


    // sacma degerler cıkmaması icin böyle bir if else yazdık
    if(eleman > dizininBoyutu || eleman == dizininBoyutu){
        diziElemanlariToplama(dizi, dizi2, dizininBoyutu, outFile); // dizi elemanlarını toplayan fonksiyon
        diziElemanlariCarpma(dizi, dizi2, dizininBoyutu, outFile); // dizi elemanlarını çarpan fonksiyon
    }else{
        diziElemanlariToplama(dizi, dizi2, eleman, outFile); 
        diziElemanlariCarpma(dizi, dizi2, eleman, outFile); 
    }


    tekCiftDiziler(dizi, eleman, outFile); // tek ve çift diziler için fonksiyon
    
    inFile.close();
    outFile.close();

    return 0;
}