/*
* Point of Sales (POS) System for UMKM
* Kelompok 2:
* - Johannes Ronald Elyeser Roparulian Hutagalung (24130400002)
* - Fajar Dwiharjo (24130500010)
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Struktur untuk Bahan
struct Bahan {
    string kode;
    string nama;
    int stok;
    int stokMinimal;
    
    Bahan(string k, string n, int s, int sm) {
        kode = k;
        nama = n;
        stok = s;
        stokMinimal = sm;
    }
};

// Struktur untuk Menu
struct Menu {
    string kode;
    string nama;
    double harga;
    vector<pair<string, int>> komposisiBahan; // pair<kode_bahan, jumlah>
    
    Menu(string k, string n, double h) {
        kode = k;
        nama = n;
        harga = h;
    }
    
    void tambahBahan(string kodeBahan, int jumlah) {
        komposisiBahan.push_back(make_pair(kodeBahan, jumlah));
    }
};

// Struktur untuk Item Pesanan
struct ItemPesanan {
    string kodeMenu;
    int jumlah;
    double subTotal;
    
    ItemPesanan(string kode, int jml, double total) {
        kodeMenu = kode;
        jumlah = jml;
        subTotal = total;
    }
};

// Struktur untuk Pesanan
struct Pesanan {
    vector<ItemPesanan> items;
    double totalHarga;
    bool statusDiterima;
    
    Pesanan() {
        totalHarga = 0;
        statusDiterima = false;
    }
};

// Class utama sistem POS
class SistemPOS {
private:
    vector<Bahan> daftarBahan;
    vector<Menu> daftarMenu;
    Pesanan pesananAktif;
    
public:
    // Fungsi untuk admin - Manajemen Bahan
    void tambahBahan(string kode, string nama, int stokAwal, int stokMin) {
        // Cek apakah kode sudah ada
        for(const auto& bahan : daftarBahan) {
            if(bahan.kode == kode) {
                cout << "Error: Kode bahan sudah digunakan!\n";
                return;
            }
        }
        Bahan bahan(kode, nama, stokAwal, stokMin);
        daftarBahan.push_back(bahan);
        cout << "Bahan berhasil ditambahkan!\n";
    }
    
    void lihatDaftarBahan() {
        cout << "\nDaftar Bahan:\n";
        cout << "--------------------------------\n";
        cout << "Kode\tNama\tStok\tStok Min\n";
        cout << "--------------------------------\n";
        for(const auto& bahan : daftarBahan) {
            cout << bahan.kode << "\t" 
                 << bahan.nama << "\t" 
                 << bahan.stok << "\t"
                 << bahan.stokMinimal << "\n";
        }
        cout << "--------------------------------\n";
    }
    
    void updateStokBahan(string kode, int jumlahBaru) {
        for(auto& bahan : daftarBahan) {
            if(bahan.kode == kode) {
                bahan.stok = jumlahBaru;
                cout << "Stok bahan " << bahan.nama << " berhasil diupdate!\n";
                if(bahan.stok <= bahan.stokMinimal) {
                    cout << "PERINGATAN: Stok " << bahan.nama << " sudah di bawah batas minimal!\n";
                }
                return;
            }
        }
        cout << "Bahan dengan kode " << kode << " tidak ditemukan!\n";
    }
    
    void cekBahanHampirHabis() {
        cout << "\nDaftar Bahan yang Hampir Habis:\n";
        cout << "--------------------------------\n";
        cout << "Kode\tNama\tStok\tStok Min\n";
        cout << "--------------------------------\n";
        bool ada = false;
        for(const auto& bahan : daftarBahan) {
            if(bahan.stok <= bahan.stokMinimal) {
                cout << bahan.kode << "\t" 
                     << bahan.nama << "\t" 
                     << bahan.stok << "\t"
                     << bahan.stokMinimal << "\n";
                ada = true;
            }
        }
        if(!ada) {
            cout << "Tidak ada bahan yang hampir habis\n";
        }
        cout << "--------------------------------\n";
    }

    // Fungsi untuk admin - Manajemen Menu
    void tambahMenu(string kode, string nama, double harga) {
        // Cek apakah kode sudah ada
        for(const auto& menu : daftarMenu) {
            if(menu.kode == kode) {
                cout << "Error: Kode menu sudah digunakan!\n";
                return;
            }
        }
        Menu menu(kode, nama, harga);
        daftarMenu.push_back(menu);
        cout << "Menu berhasil ditambahkan!\n";
    }

    void tambahKomposisiMenu(string kodeMenu, string kodeBahan, int jumlah) {
        for(auto& menu : daftarMenu) {
            if(menu.kode == kodeMenu) {
                // Cek apakah bahan ada
                bool bahanDitemukan = false;
                for(const auto& bahan : daftarBahan) {
                    if(bahan.kode == kodeBahan) {
                        bahanDitemukan = true;
                        break;
                    }
                }
                if(!bahanDitemukan) {
                    cout << "Error: Bahan tidak ditemukan!\n";
                    return;
                }
                menu.tambahBahan(kodeBahan, jumlah);
                cout << "Komposisi berhasil ditambahkan ke menu!\n";
                return;
            }
        }
        cout << "Error: Menu tidak ditemukan!\n";
    }

    void lihatDaftarMenu() {
        cout << "\nDaftar Menu:\n";
        cout << "----------------------------------------\n";
        cout << "Kode\tNama\tHarga\tStatus\n";
        cout << "----------------------------------------\n";
        for(const auto& menu : daftarMenu) {
            bool tersedia = true;
            // Cek ketersediaan bahan
            for(const auto& komposisi : menu.komposisiBahan) {
                for(const auto& bahan : daftarBahan) {
                    if(bahan.kode == komposisi.first) {
                        if(bahan.stok < komposisi.second) {
                            tersedia = false;
                            break;
                        }
                    }
                }
                if(!tersedia) break;
            }
            cout << menu.kode << "\t" 
                 << menu.nama << "\t" 
                 << menu.harga << "\t"
                 << (tersedia ? "Tersedia" : "Tidak Tersedia") << "\n";
        }
        cout << "----------------------------------------\n";
    }

    void lihatDetailMenu(string kodeMenu) {
        for(const auto& menu : daftarMenu) {
            if(menu.kode == kodeMenu) {
                cout << "\nDetail Menu: " << menu.nama << "\n";
                cout << "Kode: " << menu.kode << "\n";
                cout << "Harga: " << menu.harga << "\n";
                cout << "Komposisi Bahan:\n";
                for(const auto& komposisi : menu.komposisiBahan) {
                    for(const auto& bahan : daftarBahan) {
                        if(bahan.kode == komposisi.first) {
                            cout << "- " << bahan.nama << ": " 
                                 << komposisi.second << " unit\n";
                            break;
                        }
                    }
                }
                return;
            }
        }
        cout << "Menu tidak ditemukan!\n";
    }

    // Fungsi untuk kasir - Manajemen Pesanan
    bool cekKetersediaanMenu(string kodeMenu, int jumlah) {
        for(const auto& menu : daftarMenu) {
            if(menu.kode == kodeMenu) {
                // Cek ketersediaan semua bahan
                for(const auto& komposisi : menu.komposisiBahan) {
                    for(const auto& bahan : daftarBahan) {
                        if(bahan.kode == komposisi.first) {
                            if(bahan.stok < komposisi.second * jumlah) {
                                cout << "Stok " << bahan.nama << " tidak mencukupi!\n";
                                return false;
                            }
                            break;
                        }
                    }
                }
                return true;
            }
        }
        cout << "Menu tidak ditemukan!\n";
        return false;
    }

    void tambahItemPesanan(string kodeMenu, int jumlah) {
        if(!cekKetersediaanMenu(kodeMenu, jumlah)) {
            return;
        }

        for(const auto& menu : daftarMenu) {
            if(menu.kode == kodeMenu) {
                // Kurangi stok bahan
                for(const auto& komposisi : menu.komposisiBahan) {
                    for(auto& bahan : daftarBahan) {
                        if(bahan.kode == komposisi.first) {
                            bahan.stok -= komposisi.second * jumlah;
                            break;
                        }
                    }
                }

                double subTotal = menu.harga * jumlah;
                pesananAktif.items.push_back(ItemPesanan(kodeMenu, jumlah, subTotal));
                pesananAktif.totalHarga += subTotal;
                cout << "Item berhasil ditambahkan ke pesanan!\n";
                return;
            }
        }
    }

    void lihatPesananAktif() {
        if(pesananAktif.items.empty()) {
            cout << "Tidak ada pesanan aktif!\n";
            return;
        }

        cout << "\nPesanan Aktif:\n";
        cout << "----------------------------------------\n";
        cout << "Menu\tJumlah\tHarga\tSubTotal\n";
        cout << "----------------------------------------\n";
        
        for(const auto& item : pesananAktif.items) {
            for(const auto& menu : daftarMenu) {
                if(menu.kode == item.kodeMenu) {
                    cout << menu.nama << "\t" 
                         << item.jumlah << "\t"
                         << menu.harga << "\t"
                         << item.subTotal << "\n";
                    break;
                }
            }
        }
        cout << "----------------------------------------\n";
        cout << "Total: " << pesananAktif.totalHarga << "\n";
        cout << "Status: " << (pesananAktif.statusDiterima ? "Diterima" : "Pending") << "\n";
        cout << "----------------------------------------\n";
    }

    void selesaikanPesanan() {
        if(pesananAktif.items.empty()) {
            cout << "Tidak ada pesanan aktif untuk diselesaikan!\n";
            return;
        }

        pesananAktif.statusDiterima = true;
        cout << "\nPesanan selesai diproses!\n";
        lihatPesananAktif();
        
        // Reset pesanan aktif
        pesananAktif = Pesanan();
    }

    void batalkanPesanan() {
        if(pesananAktif.items.empty()) {
            cout << "Tidak ada pesanan aktif untuk dibatalkan!\n";
            return;
        }

        // Kembalikan stok bahan
        for(const auto& item : pesananAktif.items) {
            for(const auto& menu : daftarMenu) {
                if(menu.kode == item.kodeMenu) {
                    for(const auto& komposisi : menu.komposisiBahan) {
                        for(auto& bahan : daftarBahan) {
                            if(bahan.kode == komposisi.first) {
                                bahan.stok += komposisi.second * item.jumlah;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }

        pesananAktif = Pesanan();
        cout << "Pesanan dibatalkan!\n";
    }
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
            case '1': {
                char menuAdmin;
                do {
                    cout << "\nMenu Admin:\n";
                    cout << "=== Manajemen Bahan ===\n";
                    cout << "1. Tambah Bahan Baru\n";
                    cout << "2. Lihat Daftar Bahan\n";
                    cout << "3. Update Stok Bahan\n";
                    cout << "4. Cek Bahan Hampir Habis\n";
                    cout << "=== Manajemen Menu ===\n";
                    cout << "5. Tambah Menu Baru\n";
                    cout << "6. Tambah Komposisi Menu\n";
                    cout << "7. Lihat Daftar Menu\n";
                    cout << "8. Lihat Detail Menu\n";
                    cout << "0. Kembali ke Menu Utama\n";
                    cout << "Pilihan: ";
                    cin >> menuAdmin;

                    switch(menuAdmin) {
                        case '1': {
                            string kode, nama;
                            int stokAwal, stokMin;
                            
                            cout << "Masukkan kode bahan: ";
                            cin >> kode;
                            cout << "Masukkan nama bahan: ";
                            cin.ignore();
                            getline(cin, nama);
                            cout << "Masukkan stok awal: ";
                            cin >> stokAwal;
                            cout << "Masukkan stok minimal: ";
                            cin >> stokMin;
                            
                            sistem.tambahBahan(kode, nama, stokAwal, stokMin);
                            break;
                        }
                        case '2': {
                            sistem.lihatDaftarBahan();
                            break;
                        }
                        case '3': {
                            string kode;
                            int stokBaru;
                            cout << "Masukkan kode bahan: ";
                            cin >> kode;
                            cout << "Masukkan jumlah stok baru: ";
                            cin >> stokBaru;
                            sistem.updateStokBahan(kode, stokBaru);
                            break;
                        }
                        case '4': {
                            sistem.cekBahanHampirHabis();
                            break;
                        }
                        case '5': {
                            string kode, nama;
                            double harga;
                            
                            cout << "Masukkan kode menu: ";
                            cin >> kode;
                            cout << "Masukkan nama menu: ";
                            cin.ignore();
                            getline(cin, nama);
                            cout << "Masukkan harga menu: ";
                            cin >> harga;
                            
                            sistem.tambahMenu(kode, nama, harga);
                            break;
                        }
                        case '6': {
                            string kodeMenu, kodeBahan;
                            int jumlah;
                            
                            cout << "Masukkan kode menu: ";
                            cin >> kodeMenu;
                            cout << "Masukkan kode bahan: ";
                            cin >> kodeBahan;
                            cout << "Masukkan jumlah bahan: ";
                            cin >> jumlah;
                            
                            sistem.tambahKomposisiMenu(kodeMenu, kodeBahan, jumlah);
                            break;
                        }
                        case '7': {
                            sistem.lihatDaftarMenu();
                            break;
                        }
                        case '8': {
                            string kodeMenu;
                            cout << "Masukkan kode menu: ";
                            cin >> kodeMenu;
                            sistem.lihatDetailMenu(kodeMenu);
                            break;
                        }
                        case '0': {
                            cout << "Kembali ke menu utama...\n";
                            break;
                        }
                        default: {
                            cout << "Pilihan tidak valid!\n";
                            break;
                        }
                    }
                } while(menuAdmin != '0');
                break;
            }
            case '2': {
                char menuKasir;
                do {
                    cout << "\nMenu Kasir:\n";
                    cout << "1. Lihat Menu Tersedia\n";
                    cout << "2. Tambah Item ke Pesanan\n";
                    cout << "3. Lihat Pesanan Aktif\n";
                    cout << "4. Selesaikan Pesanan\n";
                    cout << "5. Batalkan Pesanan\n";
                    cout << "0. Kembali ke Menu Utama\n";
                    cout << "Pilihan: ";
                    cin >> menuKasir;

                    switch(menuKasir) {
                        case '1': {
                            sistem.lihatDaftarMenu();
                            break;
                        }
                        case '2': {
                            string kodeMenu;
                            int jumlah;
                            
                            cout << "Masukkan kode menu: ";
                            cin >> kodeMenu;
                            cout << "Masukkan jumlah: ";
                            cin >> jumlah;
                            
                            sistem.tambahItemPesanan(kodeMenu, jumlah);
                            break;
                        }
                        case '3': {
                            sistem.lihatPesananAktif();
                            break;
                        }
                        case '4': {
                            sistem.selesaikanPesanan();
                            break;
                        }
                        case '5': {
                            sistem.batalkanPesanan();
                            break;
                        }
                        case '0': {
                            cout << "Kembali ke menu utama...\n";
                            break;
                        }
                        default: {
                            cout << "Pilihan tidak valid!\n";
                            break;
                        }
                    }
                } while(menuKasir != '0');
                break;
            }
            case '0': {
                cout << "Terima kasih telah menggunakan sistem!\n";
                break;
            }
            default: {
                cout << "Pilihan tidak valid!\n";
                break;
            }
        }
    } while(pilihan != '0');
    
    return 0;
}
