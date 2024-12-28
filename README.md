# Point of Sales (POS) System untuk UMKM
Final Project - Algoritma dan Pemrograman Dasar

## 1. Informasi Kelompok
### Detail Kelompok
- Nomor Kelompok: 02
- Nama & NIM Anggota:
  1. Johannes Ronald Elyeser Roparulian Hutagalung (24130400002)
  2. Fajar Dwiharjo (24130500010)
- UMKM Target:
  - Siomay Ikan Ibu Yati
  - Rotice (Waffle Ice Cream)

## 2. Executive Summary Gap Analysis
### Masalah Utama dan Impact Level:
1. Antrian yang panjang saat jam sibuk (Impact: HIGH)
   - Rata-rata waktu tunggu 15-20 menit
   - Pelanggan sering batal pesan
   - Peak hours: 10:00-11:00 dan 15:00-17:00

2. Kesalahan pencatatan pesanan (Impact: HIGH)
   - 3-4 kesalahan per hari
   - Pembuatan ulang pesanan = pemborosan
   - Customer complaints meningkat

3. Stok bahan baku tidak termonitor (Impact: MEDIUM)
   - Sering kehabisan menu favorit
   - Pembelian mendadak = harga tidak optimal
   - Waste rate 10-15% per minggu

### Quick Wins dengan Solusi Teknologi:
- Digital ordering system untuk kurangi antrian
- Inventory tracking untuk kontrol stok
- Simple membership system untuk retain customer

## 3. Implementasi Program
### A. Fitur yang Diimplementasikan:
1. Manajemen Bahan
   - Tambah bahan baru
   - Lihat daftar bahan
   - Update stok bahan
   - Peringatan stok minimum

### B. Teknologi yang Digunakan:
1. Bahasa: C++
2. Komponen:
   - Array untuk penyimpanan data
   - Fungsi-fungsi dasar
   - Input/output standar

### C. Cara Penggunaan:
1. Compile program:
   ```bash
   g++ pos_system.cpp -o pos_system
   ```

2. Jalankan program:
   ```bash
   ./pos_system
   ```

3. Menu Program:
   - Menu 1: Tambah bahan baru
   - Menu 2: Lihat daftar bahan
   - Menu 3: Update stok bahan
   - Menu 4: Keluar program

### D. Batasan Program:
- Maksimal 50 jenis bahan
- Data bersifat temporary
- Input terbatas pada angka dan huruf

## 4. Analisis dan Evaluasi
### A. Impact Analysis:
1. Dampak Operasional:
   - Mengurangi kesalahan pencatatan manual
   - Monitoring stok lebih efektif
   - Peringatan dini stok menipis

2. Before-After Comparison:
   - Sebelum: Pencatatan manual di buku
   - Sesudah: Pencatatan terkomputerisasi

### B. Rencana Pengembangan:
1. Jangka Pendek:
   - Implementasi fitur kasir
   - Sistem penyimpanan permanen
   - Print struk pembelian

2. Jangka Panjang:
   - Integrasi dengan sistem keuangan
   - Analisis penjualan
   - Prediksi kebutuhan stok

## 5. Struktur Project
```
project/
├── pos_system.cpp    # File program utama
└── README.md        # Dokumentasi program
```

## 6. Pengembang
Dikembangkan oleh Kelompok 2:
- Johannes Ronald Elyeser Roparulian Hutagalung
- Fajar Dwiharjo

Program Studi Sistem Teknologi Informasi  
Fakultas Ilmu Komputer  
Universitas Cakrawala
