# Sistem POS (Point of Sales) UMKM
Project ini merupakan implementasi sistem POS sederhana untuk UMKM dalam bahasa C++.

## Anggota Kelompok 2
- Johannes Ronald Elyeser Roparulian Hutagalung (24130400002)
- Fajar Dwiharjo (24130500010)

## Fitur Sistem

### Mode Admin
1. Manajemen Bahan
   - Tambah bahan baru (kode, nama, stok awal, stok minimal)
   - Lihat daftar bahan dan stoknya
   - Update stok bahan
   - Melihat peringatan bahan yang hampir habis

2. Manajemen Menu
   - Tambah menu baru dengan informasi (kode, nama, harga)
   - Tambah komposisi bahan yang dibutuhkan
   - Lihat daftar menu beserta ketersediaan
   - Mengubah resep/komposisi menu

### Mode Kasir
1. Manajemen Pesanan
   - Membuat pesanan baru
   - Melihat menu yang tersedia
   - Sistem otomatis mengecek ketersediaan bahan
   - Mendapat peringatan jika stok tidak mencukupi
   - Melihat status pesanan (diterima/ditolak)

## Cara Penggunaan

### Mode Admin
1. Pilih menu Admin (1)
2. Pilih operasi yang diinginkan:
   - Manajemen Bahan (1-4)
   - Manajemen Menu (5-8)
3. Ikuti instruksi yang muncul di layar

### Mode Kasir
1. Pilih menu Kasir (2)
2. Pilih operasi yang diinginkan:
   - Lihat Menu (1)
   - Buat Pesanan (2)
   - Lihat Pesanan (3)
   - Selesaikan/Batalkan Pesanan (4/5)

## Implementasi
- Program dibuat dengan bahasa C++
- Dijalankan di Terminal/Command Prompt
- Menggunakan sintaks yang dipelajari di kelas
- Implementasi interaktif dan user-friendly
- Setiap requirement diimplementasikan dalam fungsi terpisah

## Struktur Program
- `struct Bahan`: Menyimpan informasi bahan
- `struct Menu`: Menyimpan informasi menu
- `struct ItemPesanan`: Menyimpan item pesanan
- `struct Pesanan`: Menyimpan pesanan aktif
- `class SistemPOS`: Class utama untuk manajemen sistem
