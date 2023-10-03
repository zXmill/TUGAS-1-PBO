#include <iostream>
#include <iomanip>
using namespace std;

class Tanggal {
private:
   int tahun, bulan, hari;

public:
   Tanggal(int tahun, int bulan, int hari) {
      this->tahun = tahun;
      this->bulan = bulan;
      this->hari = hari;
   }

   int dapatkanTahun() {
      return tahun;
   }

   int dapatkanBulan() {
      return bulan;
   }

   int dapatkanHari() {
      return hari;
   }

   void aturTahun(int tahun) {
      this->tahun = tahun;
   }

   void aturBulan(int bulan) {
      this->bulan = bulan;
   }

   void aturHari(int hari) {
      this->hari = hari;
   }

   string toString() {
      // Menggunakan fungsi bawaan String.format() untuk membentuk String yang diformat
      return to_string(bulan) + "/" + to_string(hari) + "/" + to_string(tahun);
   }

   void aturTanggal(int tahun, int bulan, int hari) {
      this->tahun = tahun;
      this->bulan = bulan;
      this->hari = hari;
   }
};

int main() {
   // Membuat instance Tanggal
   Tanggal tanggal1(2023, 10, 3);

   cout << "Tahun: " << tanggal1.dapatkanTahun() << endl;
   cout << "Bulan: " << tanggal1.dapatkanBulan() << endl;
   cout << "Hari: " << tanggal1.dapatkanHari() << endl;

   // Mengatur tahun, bulan, dan hari
   tanggal1.aturTahun(2024);
   tanggal1.aturBulan(11);
   tanggal1.aturHari(15);

   cout << "Tanggal setelah diatur: " << tanggal1.toString() << endl;

   return 0;
}
