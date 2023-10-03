#include <iostream>
#include <iomanip>
using namespace std;

class Waktu {
private:
   int detik, menit, jam;

public:
   Waktu(int detik, int menit, int jam) {
      this->detik = detik;
      this->menit = menit;
      this->jam = jam;
   }

   Waktu() {  // konstruktor default
      this->detik = 0;
      this->menit = 0;
      this->jam = 0;
   }

   int dapatkanDetik() {
      return this->detik;
   }

   int dapatkanMenit() {
      return this->menit;
   }

   int dapatkanJam() {
      return this->jam;
   }

   void aturDetik(int detik) {
      this->detik = detik;
   }

   void aturMenit(int menit) {
      this->menit = menit;
   }

   void aturJam(int jam) {
      this->jam = jam;
   }

   string toString() {
      // Menggunakan fungsi bawaan String.format() untuk membentuk String yang diformat
      return to_string(jam) + ":" + to_string(menit) + ":" + to_string(detik);
   }

   void aturWaktu(int detik, int menit, int jam) {
      // Tanpa validasi input
      this->detik = detik;
      this->menit = menit;
      this->jam = jam;
   }

   Waktu nextSecond() {
      ++detik;
      if (detik >= 60) {
         detik = 0;
         ++menit;
         if (menit >= 60) {
            menit = 0;
            ++jam;
            if (jam >= 24) {
               jam = 0;
            }
         }
      }
      return *this;   // Mengembalikan instance "this" untuk mendukung operasi berantai
                     // contohnya, w1.nextSecond().nextSecond()
   }
};

int main() {
   // Membuat instance Waktu
   Waktu waktu1(30, 15, 10);

   cout << "Jam: " << waktu1.dapatkanJam() << endl;
   cout << "Menit: " << waktu1.dapatkanMenit() << endl;
   cout << "Detik: " << waktu1.dapatkanDetik() << endl;

   // Mengatur detik, menit, dan jam
   waktu1.aturDetik(45);
   waktu1.aturMenit(20);
   waktu1.aturJam(5);

   cout << "Waktu setelah diatur: " << waktu1.toString() << endl;

   // Menambahkan satu detik
   waktu1.nextSecond();
   cout << "Waktu setelah satu detik: " << waktu1.toString() << endl;

   return 0;
}
