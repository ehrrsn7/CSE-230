
#include <iostream>
using namespace std;

void question1() {
   int a = 14;
   int b = 10;
   cout << a++ - b << " ";
   cout << a++ - b << endl;
}


void question2() {
    // What is the output of the following code fragment:
   int f = 34;
   float c = (f - 32) * 5 / 9;
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
   cout << c << endl;
}

void question3() {
    // What is the output of the following code?
   int a = 5;
   int b = 6 + a++;
   cout << b << endl;
}

void question4() {
    // output
   int dateOfBirth = 1987;
   int currentYear = 2006;

   cout << "age is "
        << currentYear++ - dateOfBirth
        << endl;

   cout << "age is "
        << currentYear++ - dateOfBirth
        << endl;
}

void question5() {
    // val of d
   bool a = ('a' > 'b');
   bool b = 65 * 3 < 100;
   bool c = 14 / 10;
   bool d = a || b || c;
   cout << d << endl;
}

void question6() {
    // output
   bool a = false;
   int b = a;
   cout << b << endl;
}

void question7() {
    // output
    /** (uncomment this section to run function, I commented it because the compiler throws warnings and I got sick of reading them)
   int i = 0;
   cout << '[';
   while (++i < 4);
      cout << i;
   cout << "]\n";
   **/
}

void question8() {
    // what is the purpose of the function
   int a = 1;
   for (int b = 1; b < 3; b++)
      a += a;
   cout << a << endl;
}

void question9() {
    // output
   int i = 0;
   for (int j = 2; j < 7; j += 2)
      i++;
   cout << i << endl;
}

void question10() {
    // What is the output when the input is ‘a’, ‘b’, ‘x’?
   int c = 0;
   char d;

   cin >> d;

   while (d != 'x')
   {
      c++;
      cin >> d;
   }

   cout << c << endl;
}

void question11() {
    // output
   int i = 1;
   while (i < 3)
      i++;

   cout << i << endl;
}

void question12() {
    // output
    /** block has error, I commented it to hide the messages
   int j = 10;

   for (int i = 1; i < 3; i++)
      j++;
   cout << i << endl;

   return 0;
   **/
}

void question13() {
    // output
   int sum = 0;
   int count;

   for (count = 0; count < 4; count++)
      sum += count;
   cout << "sum == " << sum << endl;
}

void question14() {
    // output
   char text[] = {'a', '\0', 'b', 'c', '\0'};

   for (int i = 0; i <= 4; i++)
   {
      bool b = text[i];
      cout << b;
   }
   cout << endl;
}

void question15() {
    /** commented to hide error msgs
    // Given the following array:
    int numbers[3][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    int i = 1;
    // Which code fragment will output the number 6
    cout << i++ << ") " << numbers[3][2] << endl;
    cout << i++ << ") " << numbers[2][3] << endl;
    cout << i++ << ") " << numbers[2][1] << endl;
    cout << i++ << ") " << numbers[1][2] << endl;
    // answer: answer no. 4
    **/
}

void helper16(int x1, int &x2) {
   x1 = 4;
   x2 = 5;
}

int question16() {
    // output
   int x1 = 2;
   int x2 = 3;
   helper16(x1, x2);
   cout << x1 * x2 << endl;
   return 0;
}

bool helper17(bool b) {
   b = false;
   return true;
}

int question17() {
    // what is the value of b at the end of execution
   bool b;

   helper17(b);

    // my code here
    cout << b << endl; // (0 - false; 1 - true)
   return 0;
}

void helper18(int a, int &b) {
   a = 0;
   b = 0;
}

void question18() {
    // output
   int a = 1;
   int b = 2;

   helper18(a, b);

   cout << "a == " << a << '\t'
       << "b == " << b << endl;
}

// TYPO - fixed copy constructor function call, instead of ) there was }
// TYPO - method didn't have 'void'
class Silly {
   public:
      Silly()                { cout << "Default Constructor\n"; }
      Silly(const Silly & s) { cout << "Copy Constructor\n";    }
      ~Silly()               { cout << "Destructor\n";          }
      void method()          { cout << "Method\n";              }
};

int question23() {
   Silly s1;
   if (true)
   {
      Silly s2(s1);
      s2.method();
   }
   s1.method();
   return 0;
}

// TYPO - original code doesn't compile since bullet 3 is out of scope. use bullet 1 or 2 instead
class Bullet
{
   public:
      Bullet()         { numBullet++;      }
     ~Bullet()         { --numBullet;      }
      int getBullets() { return numBullet; }
   private:
      static int numBullet;
};

int Bullet::numBullet = 0;

int question24()
{
   Bullet b1;
   Bullet b2;

   {
      Bullet b3;
      Bullet b4;
      cout << b3.getBullets() << endl;
   }
   cout << b2.getBullets() << endl;
   return 0;
}

int output(int * a, int * b) {
   *a += *b;

   return *a;
}

void question25() {
    // what is the output (error)
    /**
   cout << output(15, 20) << endl;
   return 0;
   **/
}

void question26() {
    // output
   int a = 21;
   int *b = &a;

   while (*b > 16)
      (*b)--;

   cout << a << endl;
}

void question27() {
    // output
   int *a = 0;
   int b = 11;
   int *c = &b;
   a = c;
   *c += 4;

   cout << *a << endl;
}

void question28() {
    // output
    /**
   char a[] = "Brother";
   char b[] = "Baker";
   char *c;

   if (a == b)
      c = b;
   else
      c = a;

   cout << *c << endl;
   **/
}

void question29() {
    // output
   int *a;
   int b = 1;
   int *c = a;
   int d = 2;

   c  = &b;
   a  = c;
   *a = 3;
   *c = 4;

   cout << d << endl;
}

void question30() {
   int  a = 0;
   int  b = 1;
   int *c = &b;
   *c = 2;
   int *d = &a;
   b  = 3;
   d  = &b;
   *d = 4;
   //find val of b
   cout << b << endl;
}

void question31() {
    // output
   char text[] = "Banana";

   char *pA = text + 2;

   cout << *pA << endl;
}

void question32() {
    // output
   char text[] = "Software";

   int a = 0;
   for (char *p = text; *p; p++)
      a++;

   cout << a << endl;
}

// question-answer TYPO in quiz - answer only includes '99' where output is "*b == 99"
void question33() {
    // output
   int  a = 16;
   int *b = &a;
   int  c = *b;
   a  = 42;
   int *d = &c;
   a  = *b;
   d  = &a;
   *d = 99;
   cout << "*b == " << *b << endl;
}

void question34() {
    // output
   int a = 10;
   int *b = &a;

   while (*b > 5)
      (*b)--;

   cout << "Answer: " << a << endl;
}


void funky(int *a) {
   *a = 8;
   return;
}

int question35() {
    // output
   int b = 9;
   funky(&b);
   cout << b << endl;

   return 0;
}

void question36() {
   char *a;
   char *b = a;
   char  c = 'x';
   char  d = 'y';
   b  = &c;
   a  = &d;
   *b = 'z';
   *a = *b;
   // value of d
   cout << d << endl;
}

void question37() {
    // output when input == 'y'
   char input;
   cin >> input;

   if (input == 'x')
      cout << "Great ";
      cout << "Job!\n";
}

int helper38(int a, int b) {
   return a - b;
}

void question38() {
    // output
   int a = 7;
   int b = 9;
   cout << helper38(b, a) << endl;
}

void question39() {
    // output
    /** hide warning
    int value = 1;
    if (value = 2)
        value = 3;
    else
        value = 4;
    cout << value << endl;
    **/
}

void question40() {
    // output
   int z = 4;
   if (z == 5)
      cout << "a";
      cout << "b";
   cout << "c" << endl;
}

void question41() {
    // output
   int value = 23;

   switch (value)
   {
      case 23:
         value++;
      case 24:
         value++;
      case 25:
         value++;
   }

   cout << value << endl;
}

void question42() {
    // output
    /** hide warnings
   char x = 'a';

   if (x > 'b');
      x = 'c';

   cout << x << endl;
   **/
}

void question43() {
    // output
   int a = 2;
   if (true)
   {
      int a = 4;
      if (true)
      {
         int a = 8;
      }
      cout << a << " ";
    }
    cout << a << " " << endl;
}

void question44() {
    // output
    /** hide warnings
   int x = 5;
   if (x = 6)
      x = 7;
   cout << x << endl;
   **/
}

void question45() {
    // output
    /**
     * hide error msgs
   float feet = 7;
   float yards = (1/3) feet;
   // val of yards
   cout << yards << endl;
   **/
}

void question46() {
    bool e = 100 > 90 > 80;
    // evaluate e
    cout << e << endl;
}

void helper47(int b, int a)
{
   cout << "a == " << a << '\t'
        << "b == " << b << endl;
}

int question()
{
   int a = 10;
   int b = 20;

   cout << "a == " << a << '\t'
        << "b == " << b << endl;
   helper47(a, b);

   return 0;
}


int main() {
    question();
    int yeet = 0;
    return yeet;
}