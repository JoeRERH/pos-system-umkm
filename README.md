# Point of Sales (POS) System untuk UMKM
Sistem manajemen penjualan sederhana untuk UMKM, dibangun menggunakan C++.

## Tim Pengembang
- Johannes Ronald Elyeser Roparulian Hutagalung (24130400002)
- Fajar Dwiharjo (24130500010)

## Daftar Isi
- [Tentang Proyek](#tentang-proyek)
- [Fitur](#fitur)
- [Teknologi yang Digunakan](#teknologi-yang-digunakan)
- [Instalasi](#instalasi)
- [Penggunaan](#penggunaan)
- [Struktur Program](#struktur-program)
- [Dokumentasi Kode](#dokumentasi-kode)

## Tentang Proyek
Proyek ini dikembangkan sebagai solusi untuk manajemen penjualan di dua UMKM:
- Siomay Ikan Ibu Yati
- Rotice (Waffle Ice Cream)

Sistem ini dirancang untuk mengatasi beberapa masalah utama:
- Antrian yang panjang saat jam sibuk
- Kesalahan pencatatan pesanan
- Monitoring stok bahan baku
- Pencatatan keuangan manual

## Fitur

### Mode Admin
1. Manajemen Bahan
   - Tambah bahan baru
   - Lihat daftar bahan
   - Update stok bahan
   - Cek bahan hampir habis

2. Manajemen Menu
   - Tambah menu baru
   - Tambah komposisi menu
   - Lihat daftar menu
   - Lihat detail menu

### Mode Kasir
1. Manajemen Pesanan
   - Lihat menu tersedia
   - Tambah item ke pesanan
   - Lihat pesanan aktif
   - Selesaikan pesanan
   - Batalkan pesanan

## Teknologi yang Digunakan
- Bahasa: C++
- Compiler: g++ (C++11 atau lebih tinggi)
- IDE: HackerRank online IDE

## Instalasi

### Persyaratan Sistem
- C++11 compiler atau lebih tinggi
- Minimum 512MB RAM
- Terminal/Command prompt

### Langkah Instalasi
1. Clone repository
```bash
git clone https://github.com/username/pos-system.git
```

2. Masuk ke direktori proyek
```bash
cd pos-system
```

3. Compile program
```bash
g++ -std=c++11 main.cpp -o pos_system
```

4. Jalankan program
```bash
./pos_system
```

## Penggunaan

### Menu Utama
1. Mode Admin
   - Manajemen bahan
   - Manajemen menu

2. Mode Kasir
   - Manajemen pesanan
   - Cetak struk

### Format Input
1. Tambah Bahan
```
Kode Bahan: [string]
Nama Bahan: [string]
Stok Awal: [integer]
Stok Minimal: [integer]
```

2. Tambah Menu
```
Kode Menu: [string]
Nama Menu: [string]
Harga: [double]
```

3. Tambah Pesanan
```
Kode Menu: [string]
Jumlah: [integer]
```

## Struktur Program

### Class Utama
1. `Bahan`
   - Menyimpan informasi bahan
   - Manajemen stok

2. `Menu`
   - Informasi menu
   - Komposisi bahan

3. `ItemPesanan`
   - Detail item pesanan
   - Kalkulasi subtotal

4. `SistemPOS`
   - Logika utama sistem
   - Integrasi semua komponen

## Dokumentasi Kode

### Contoh Penggunaan

#### Tambah Bahan Baru
```cpp
sistem.tambahBahan("B001", "Tepung", 100, 20);
```

#### Tambah Menu
```cpp
sistem.tambahMenu("M001", "Siomay Ikan", 2500);
sistem.tambahKomposisiMenu("M001", "B001", 5);
```

#### Proses Pesanan
```cpp
sistem.tambahItemPesanan("M001", 3);
sistem.selesaikanPesanan();
```

## Optimasi dan Keterbatasan

### Optimasi yang Diterapkan
- Penggunaan array statis untuk manajemen memori yang efisien
- Validasi input untuk mencegah error
- Error handling untuk kasus-kasus khusus

### Keterbatasan Sistem
- Jumlah maksimum produk dan pesanan tetap
- Tidak ada penyimpanan data permanen
- Interface berbasis terminal

## Pengembangan Kedepan

### Rencana Jangka Pendek
1. Teknis
   - Implementasi database
   - UI/UX enhancement
   - Print functionality

2. Bisnis
   - Sistem membership
   - Diskon dan promo
   - Laporan penjualan

### Rencana Jangka Panjang
1. Sistem Integration
   - Cloud backup
   - Payment gateway
   - Accounting system

2. Business Analytics
   - Predictive analytics
   - Customer behavior
   - Inventory optimization

## Lisensi
Program ini dikembangkan sebagai bagian dari tugas mata kuliah Algoritma dan Pemrograman.

## Kontak
Untuk pertanyaan dan informasi lebih lanjut, silakan hubungi:
- Email: [joererh@gmail.com]
- Program Studi: Sistem Teknologi dan Informasi
- Fakultas Ilmu Komputer
- Universitas Cakrawala
