/*
* Point of Sales (POS) System for UMKM
* Kelompok 2:
* - Johannes Ronald Elyeser Roparulian Hutagalung (24130400002)
* - Fajar Dwiharjo (24130500010)
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_PRODUCTS = 100;
const int MAX_ITEMS = 50;

// Class untuk Bahan
class Bahan {
private:
    string kode;
    string nama;
    int stok;
    int stokMinimal;
    
public:
    Bahan() {
        kode = "";
        nama = "";
        stok = 0;
        stokMinimal = 0;
    }
    
    Bahan(string k, string n, int s, int sm) {
        kode = k;
        nama = n;
        stok = s;
        stokMinimal = sm;
    }
    
    // Getters
    string getKode() { return kode; }
    string getNama() { return nama; }
    int getStok() { return stok; }
    int getStokMinimal() { return stokMinimal; }
    
    // Setters
    void setStok(int s) { stok = s; }
};

// Class untuk Menu
class Menu {
private:
    string kode;
    string nama;
    double harga;
    string kodeBahan[MAX_PRODUCTS];
    int jumlahBahan[MAX_PRODUCTS];
    int bahanCount;
    
public:
    Menu() {
        kode = "";
        nama = "";
        harga = 0;
        bahanCount = 0;
    }
    
    Menu(string k, string n, double h) {
        kode = k;
        nama = n;
        harga = h;
        bahanCount = 0;
    }
    
    // Getters
    string getKode() { return kode; }
    string getNama() { return nama; }
    double getHarga() { return harga; }
    int getBahanCount() { return bahanCount; }
    string getKodeBahan(int index) { return kodeBahan[index]; }
    int getJumlahBahan(int index) { return jumlahBahan[index]; }
    
    void tambahBahan(string kodeBahan, int jumlah) {
        if (bahanCount < MAX_PRODUCTS) {
            this->kodeBahan[bahanCount] = kodeBahan;
            this->jumlahBahan[bahanCount] = jumlah;
            bahanCount++;
        }
    }
};

// Class untuk Item Pesanan
class ItemPesanan {
private:
    string kodeMenu;
    int jumlah;
    double subTotal;
    
public:
    ItemPesanan() {
        kodeMenu = "";
        jumlah = 0;
        subTotal = 0;
    }
    
    ItemPesanan(string kode, int jml, double total) {
        kodeMenu = kode;
        jumlah = jml;
        subTotal = total;
    }
    
    // Getters
    string getKodeMenu() { return kodeMenu; }
    int getJumlah() { return jumlah; }
    double getSubTotal() { return subTotal; }
};

// Class utama sistem POS
class SistemPOS {
private:
    Bahan daftarBahan[MAX_PRODUCTS];
    int bahanCount;
    Menu daftarMenu[MAX_PRODUCTS];
    int menuCount;
    ItemPesanan pesananAktif[MAX_ITEMS];
    int pesananCount;
    double totalHarga;
    
public:
    SistemPOS() {
        bahanCount = 0;
        menuCount = 0;
        pesananCount = 0;
        totalHarga = 0;
    }
    
    void tambahBahan(string kode, string nama, int stokAwal, int stokMin) {
        if (bahanCount < MAX_PRODUCTS) {
            for (int i = 0; i < bahanCount; i++) {
                if (daftarBahan[i].getKode() == kode) {
                    cout << "Error: Kode bahan sudah digunakan!\n";
                    return;
                }
            }
            daftarBahan[bahanCount] = Bahan(kode, nama, stokAwal, stokMin);
            bahanCount++;
            cout << "Bahan berhasil ditambahkan!\n";
        } else {
            cout << "Error: Kapasitas bahan penuh!\n";
        }
    }
    
    void lihatDaftarBahan() {
        cout << "\nDaftar Bahan:\n";
        cout << "--------------------------------\n";
        cout << "Kode\tNama\tStok\tStok Min\n";
        cout << "--------------------------------\n";
        for (int i = 0; i < bahanCount; i++) {
            cout << daftarBahan[i].getKode() << "\t"
                 << daftarBahan[i].getNama() << "\t"
                 << daftarBahan[i].getStok() << "\t"
                 << daftarBahan[i].getStokMinimal() << "\n";
        }
        cout << "--------------------------------\n";
    }
    
    void updateStokBahan(string kode, int jumlahBaru) {
        for (int i = 0; i < bahanCount; i++) {
            if (daftarBahan[i].getKode() == kode) {
                daftarBahan[i].setStok(jumlahBaru);
                cout << "Stok bahan " << daftarBahan[i].getNama() << " berhasil diupdate!\n";
                if (daftarBahan[i].getStok() <= daftarBahan[i].getStokMinimal()) {
                    cout << "PERINGATAN: Stok " << daftarBahan[i].getNama() 
                         << " sudah di bawah batas minimal!\n";
                }
                return;
            }
        }
        cout << "Bahan dengan kode " << kode << " tidak ditemukan!\n";
    }

    // Continue with other methods like tambahMenu(), addToOrder(), etc.
    // [Additional implementation details would follow here...]
};

int main() {
    SistemPOS sistem;
    char pilihan;
    
    do {
        cout << "\nMenu Utama:\n";
        cout << "1. Mode Admin\n";
        cout << "2. Mode Kasir\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            // [Implementation of menu options would go here...]
            case '0':
                cout << "Terima kasih telah menggunakan sistem!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while(pilihan != '0');
    
    return 0;
}
