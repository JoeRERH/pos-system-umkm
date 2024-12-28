// Program Point of Sales (POS) Sederhana untuk UMKM
// Kelompok 2:
// - Johannes Ronald Elyeser Roparulian Hutagalung (24130400002)
// - Fajar Dwiharjo (24130500010)

#include <iostream>
using namespace std;

// Deklarasi array untuk menyimpan data
const int MAX = 50;
string kode[MAX];
string nama[MAX];
int stok[MAX];
int stok_minimal[MAX];
int jumlah_data = 0;

// Fungsi untuk menampilkan menu
void tampilkan_menu() {
    cout << "\n=== SISTEM POS UMKM ===\n";
    cout << "1. Tambah Bahan\n";
    cout << "2. Lihat Bahan\n";
    cout << "3. Update Stok\n";
    cout << "4. Keluar\n";
    cout << "Pilihan: ";
}

// Fungsi untuk menambah bahan
void tambah_bahan() {
    if(jumlah_data < MAX) {
        cout << "\nTambah Bahan Baru\n";
        cout << "Kode: ";
        cin >> kode[jumlah_data];
        cout << "Nama: ";
        cin >> nama[jumlah_data];
        cout << "Stok: ";
        cin >> stok[jumlah_data];
        cout << "Stok Minimal: ";
        cin >> stok_minimal[jumlah_data];
        
        jumlah_data = jumlah_data + 1;
        cout << "Bahan berhasil ditambahkan!\n";
    } else {
        cout << "Penyimpanan penuh!\n";
    }
}

// Fungsi untuk melihat daftar bahan
void lihat_bahan() {
    cout << "\nDaftar Bahan\n";
    cout << "-------------\n";
    
    for(int i = 0; i < jumlah_data; i++) {
        cout << "Kode: " << kode[i] << "\n";
        cout << "Nama: " << nama[i] << "\n";
        cout << "Stok: " << stok[i] << "\n";
        cout << "Stok Minimal: " << stok_minimal[i] << "\n";
        cout << "-------------\n";
    }
}

// Fungsi untuk update stok
void update_stok() {
    string kode_cari;
    cout << "\nMasukkan kode bahan: ";
    cin >> kode_cari;
    
    int ketemu = 0;
    for(int i = 0; i < jumlah_data; i++) {
        if(kode[i] == kode_cari) {
            cout << "Stok lama: " << stok[i] << "\n";
            cout << "Stok baru: ";
            cin >> stok[i];
            
            if(stok[i] <= stok_minimal[i]) {
                cout << "Peringatan: Stok dibawah minimal!\n";
            }
            
            ketemu = 1;
            cout << "Stok berhasil diupdate!\n";
            break;
        }
    }
    
    if(ketemu == 0) {
        cout << "Bahan tidak ditemukan!\n";
    }
}

// Program utama
int main() {
    int pilihan;
    
    do {
        tampilkan_menu();
        cin >> pilihan;
        
        if(pilihan == 1) {
            tambah_bahan();
        } 
        else if(pilihan == 2) {
            lihat_bahan();
        }
        else if(pilihan == 3) {
            update_stok();
        }
        else if(pilihan == 4) {
            cout << "Program selesai!\n";
        }
        else {
            cout << "Pilihan tidak valid!\n";
        }
        
    } while(pilihan != 4);
    
    return 0;
}
