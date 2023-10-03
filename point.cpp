#include <iostream>
#include <cmath>
using namespace std;

class Titik {
private:
   int x, y;

public:
   Titik() {  // Konstruktor default
      this->x = 0;
      this->y = 0;
   }

   Titik(int x, int y) {
      this->x = x;
      this->y = y;
   }

   int dapatkanX() {
      return this->x;
   }

   void aturX(int x) {
      this->x = x;
   }

   int dapatkanY() {
      return this->y;
   }

   void aturY(int y) {
      this->y = y;
   }

   string toString() {
      return "(" + to_string(this->x) + "," + to_string(this->y) + ")";
   }

   int* dapatkanXY() {
      int* hasil = new int[2];
      hasil[0] = this->x;
      hasil[1] = this->y;
      return hasil;
   }

   void aturXY(int x, int y) {
      this->x = x;
      this->y = y;
   }

   double jarak(int x, int y) {
      int selisihX = this->x - x;
      int selisihY = this->y - y;
      return sqrt(selisihX * selisihX + selisihY * selisihY);
   }

   double jarak(Titik lain) {
      int selisihX = this->x - lain.dapatkanX();
      int selisihY = this->y - lain.dapatkanY();
      return sqrt(selisihX * selisihX + selisihY * selisihY);
   }

   double jarak() {
      return sqrt(this->x * this->x + this->y * this->y);
   }
};

int main() {
   // Membuat instance Titik
   Titik titik1(3, 4);

   cout << "X: " << titik1.dapatkanX() << endl;
   cout << "Y: " << titik1.dapatkanY() << endl;

   // Mengatur nilai X dan Y
   titik1.aturX(7);
   titik1.aturY(9);

   cout << "Titik setelah diatur: " << titik1.toString() << endl;

   // Menghitung jarak ke titik lain
   Titik titik2(5, 2);
   double jarak = titik1.jarak(titik2);
   cout << "Jarak ke titik lain: " << jarak << endl;

   return 0;
}
