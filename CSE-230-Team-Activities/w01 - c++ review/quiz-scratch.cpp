// quiz scratch paper w01 - c++

#include <iostream>
using namespace std;
#define YO_WHAT 0

void question3() {
    cout << "_/\"-\"\\_\n"; // works
    // cout << "_///"-/"\_/n"; // ERROR
    // cout << "_/"-"\\_\n"; // nothing
    // cout << "_//"-"\_/n"; // ERROR
}

void question4() {
    //What is the output of the following code fragment:
   float a = 2;
   float b = 9 / 10 * a;
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
   cout << b << endl;
}

void question5() {
   int a =2;
   int b = ++a + 4;
   cout << b << endl;
}

void question6() {
    int i = 0;
    int x = 6 + 8 * 10 + 13;
    cout << x << endl;
    int a = (((6 + 8) * 10) + 13);
    cout << ++i << " " << (x == a) << endl;
    a = ((6 + 8) * (10 + 13));
    cout << ++i << " " << (x == a) << endl;
    a = (6 + (8 * (10 + 13)));
    cout << ++i << " " << (x == a) << endl;
    a = ((6 + (8 * 10)) + 13);
    cout << ++i << " " << (x == a) << endl;
}

void question7() {
   int a = 2;
   int b = a * 1.6;
   cout << b << endl;
}

void question8() {
   int a = 4;
   int b = 5 / a;
   cout << b << endl;
}

void question9() {
   cout << 4 + 17 % 2 * 3 << endl;
}

void question10() {
   cout << 10 - 5 * 3 + 1 << endl;
}

void question11() {
   cout.precision(1);
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout << 76 % 7 << endl;
}

void question12() {
    // cout << false * (3 || 2) + 8 << endl;
    // compiler keeps outputing warnings, uncomment this if
    // you want to run this question
}

void question13() {
   cout.precision(1);
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout << 10 / 3 << endl;
}

int compare(int x, int a, int &i) {
    cout << i << " " << (x == a) << endl;
    if (x == a) return i;
    return false;
}

void question14() {
    int i = 0;
    int correctAnswer = 0;
    int a = 5, b = 5, c = 5;

    // expression
    a = a + b * c++ / 4;

    // which is equivalent to expression?
    cout << "question " << ++i << endl;
    int x = ((a + b) * (c++)) / 4; // <<
    int result = compare(a, x, i);
    if (result != false) correctAnswer = result;
    
    cout << "question " << ++i << endl;
    x = a + (b * ((c++) / 4)); // <<
    result = compare(a, x, i);
    if (result != false) correctAnswer = result;
    
    cout << "question " << ++i << endl;
    x = a + ((b * (c++)) / 4); // <<
    result = compare(a, x, i);
    if (result != false) correctAnswer = result;
    
    cout << "question " << ++i << endl;
    x = (a + (b * (c++))) / 4; // <<
    result = compare(a, x, i);
    if (result != false) correctAnswer = result;

    if (correctAnswer != false)
        cout << "Correct answer: " << correctAnswer << endl;
}

void displayTrueOrFalse(bool x) {
    if (x) cout << "true";
    else if (!x) cout << "false";
}

void question15() {
    // What is the value of x after the following code is executed:
    bool x = 'f';
    displayTrueOrFalse(x); cout << endl;
}

void question16() {
    bool a = (3 != 3);
    bool b = (7 >= 3);
    bool c = a && b;
    displayTrueOrFalse(c); cout << endl;
}

void question17() {
    // What is the output of the following code?
    int value = 5;
    if (value > 5)
        cout << "Larger\n";
    else
        cout << "Smaller\n";
}

void question18() {
    // What is the output of the following code?
    float value = 4125.2;
    if (value > 5842.1)
        cout << 'a';
    else if (value > 4012.4)
        cout << 'b';
    else if (value > 3212.1)
        cout << 'c';
    else
        cout << 'd';

    cout << endl;
}

void question19() {
    int a = 10;
    if (a == 9)
        a = 8;
    else
        a = 7;
    cout << a << endl;
}

void question20() {
    // What is the output of the following code?
    int x = 5;

    if (x > 4)
    {
        if (x > 6)
            cout << "Highest\n";
        else
            cout << "High\n";
    }
    else
    {
        if (x > 2)
            cout << "Small\n";
        else
            cout << "Smallest\n";
    }
}

void question21() {
   int i = 0;

   for (int j = 0; j < 4; j++)
        i += 2;

    cout << i << endl;
}

void question22() {
   int j;

   for (j = 13; j < 9; --j)
      ;
   cout << j << endl;
}

void question23() {
   for (int count = 1; count < 5; count *= 2)
      cout << count;
   cout << endl;
}

void question24() {
   int a = 1;
   for (int b = 2; b <= 4; b++)
      a *= b;
   cout << a << endl;
}

void question25() {
   int c = 0;

   while (c < 5)
      c++;

   cout << c << endl;
}

void question26() {
   int count = 5;
   while (count--)
      ;
   cout << count << endl;
}

void question27() {
    // What is the output when the user inputs ‘a’, ‘b’, ‘x’?
    char input;

    do
    {
        cin >> input;
        cout << input;
    }
    while (input != 'x');

    cout << endl;
}

void question28() {
    // Which of the following code fragments will output the odd numbers under 11?

    int select = 4;
    
    switch (select) {
    case 1:
        for (int i = 1; i <= 11; i++)
            cout << i << " ";
        cout << endl;
        break;

    case 2:
        for (int i = 1; i < 10; i++)
            cout << i << " ";
        cout << endl;
        break;
    
    case 3:
        for (int i = 1; i <= 11; i += 2)
            cout << i << " ";
        cout << endl;
        break;
    
    case 4:
        for (int i = 1; i < 10; i += 2)
            cout << i << " ";
        cout << endl;
        break;

    default:
        cout << "none\n";
        break;
    }
}

void question29() {
    // What is the output of the following code?
    for (int i = 2; i < 5; i++)
        cout << "a";
    cout << endl;
}

void question30() {
    // Which of the following code fragments adds the numbers below 6?
    int a = 0;
    for (int select = 1; select <= 4; ++select) {
        cout << "Running answer #" << select << endl;
        switch (select) {
        case 1:
            a = 0;
            for (int b = 1; b < 6; b++)
                a += b;
            cout << a << endl;
            break;

        case 2:
            a = 0;
            for (int b = 1; b <= 6; b++)
                a += b;
            cout << a << endl;
            break;

        case 3:
            a = 0;
            for (int b = 1; b <= 6; b++)
                a++;
            cout << a << endl;
            break;
        
        case 4:
            a = 0;
            for (int b = 1; b < 6; b++)
                a++;
            cout << a << endl;
            break;

        default:
            break;
        }
    }
}

void question31() {
    int i = 5;
    while (i < 8)
    {
        cout << i << " ";
        i++;
    }

    cout << endl;
}

void question32() {
    int i;

    for (i = 0; i < 4; i++)
        ;
    cout << "i == " << i << endl;
}

void question33() {
    int i;

    for (i = 0; i <= 4; i++)
        ;
    cout << "i == " << i << endl;
}

void question34() {
    int sum = 0;
    int count;

    for (count = 1; count < 9; count *= 2)
        sum += count;

    cout << "sum == " << sum << endl;
}

void question35a();
void question35b();
void question35c();
void question35d();

void question35() {
    cout << "Given the following loop:\n";
    char text[] = "Some text";
    for (int i = 0; text[i] != 0x0; i++)
        cout << text[i];
    cout << endl;

    cout << "\nWhich code fragment will display the same results?\n";
    for (int select = 1; select <= 4; select++) {
        cout << "\nDisplaying fragment " << select << endl;
        switch(select) {
            case 1:
            question35a();
            break;

            case 2:
            // question35b();
            cout << "case (" << select << ") yielded segmentation fault\n";
            break;

            case 3:
            // question35c();
            cout << "case (" << select << ") yielded segmentation fault\n";
            break;

            case 4:
            question35d();
            break;

            default:
            cout << "invalid range for switch statment\n";
            break;
        }
        cout << endl;
    }
}

void question35a() {    
    char text[] = "Some text";
    for (char * p = text; *p; p++)
        cout << *p;
}

void question35b() {
    char text[] = "Some text";
    for (char * p = text; p; p++)
        cout << *p;
}

void question35c() {
    char text[] = "Some text";
    for (char * p = text; p; p++)
        cout << p;
}

void question35d() {
    char text[] = "Some text";
    for (char * p = text; *p; p++)
        cout << p;
}

void question39() {
    // What is the output?
    int nums[] = {4, 8, 12};
    int sum = 0;

    for (int i = 1; i <= 3; i++)
        sum += nums[i];

    cout << sum << endl;
}

void question41() {
    // Given the following array
    int nums[] = { 4, 21, 90, 34, 84};
    
    // Which of the following will output the number 34?
    cout << nums[4] << endl;
    cout << *(nums + 4) << endl;
    cout << *(nums + 3) << endl; // << this one
    cout << *nums + 4 << endl;
    cout << *nums + 3 << endl;
}

void question42() {
    // What is the output from the following code fragment?
    char a[3][10] =
        { "Red ", "Blue ", "Black " };

    for (int i = 2; i >= 0; i--)
        cout << a[i];
    cout << endl;
}

void question44() {
   char letters[] = "FFFFFFDCBAA";
   int number = 87;

   cout << letters[number / 10]
      << endl;
}

int main() {
    question44();
    return YO_WHAT;
}
