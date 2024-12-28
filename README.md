# Sistem POS UMKM Sederhana
Program Point of Sales sederhana untuk manajemen bahan UMKM.

## Informasi Kelompok
- Nomor Kelompok: 2
- Anggota:
  1. Johannes Ronald Elyeser Roparulian Hutagalung (24130400002)
  2. Fajar Dwiharjo (24130500010)
- UMKM Target: 
  - Siomay Ikan Ibu Yati
  - Rotice (Waffle Ice Cream)

## Tujuan Program
Program ini dibuat untuk membantu UMKM dalam:
1. Pencatatan dan manajemen stok bahan
2. Peringatan stok minimum
3. Mengurangi kesalahan pencatatan manual

## Fitur Program
1. Tambah data bahan baru
2. Lihat daftar bahan dan stoknya
3. Update stok bahan
4. Peringatan jika stok dibawah minimal

## Cara Menggunakan Program
1. Compile program:
   ```
   g++ pos_system.cpp -o pos_system
   ```

2. Jalankan program:
   ```
   ./pos_system
   ```

3. Pilih menu yang tersedia:
   - Menu 1: Tambah bahan baru
   - Menu 2: Lihat daftar bahan
   - Menu 3: Update stok bahan
   - Menu 4: Keluar program

## Batasan Program
- Maksimal menyimpan 50 jenis bahan
- Data bersifat sementara (hilang saat program ditutup)
- Input hanya menerima angka dan huruf

## Struktur Project
```
project/
├── pos_system.cpp
└── README.md
```

## Rencana Pengembangan
1. Penambahan fitur kasir
2. Sistem penyimpanan permanen
3. Perhitungan otomatis kebutuhan bahan
4. Laporan penjualan

## Kontak
- Email: [Email Anggota Kelompok]
- Kelas: Algo5
