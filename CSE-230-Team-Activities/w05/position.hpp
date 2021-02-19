#pragma once

#include <iostream>
using namespace std;

class Position
{
  private:
    unsigned char position;

  public:
    Position()
    {
        position = 0;
    }

    int getRow() { return position / 8; }
    int getCol() { return position % 8; }

    void set(int row, int column)
    {
        if (row < 0 || column < 0 || row > 0 || column > 0) {
            cout << "Range error: cannot set this chess "
                 << "piece in the specified position(" 
                 << row << ", " << column << ").\n";
            return;
        }

        position = row * 8 + column;
    }

    void display()
    {
        cout << "Position: " << getRow() + 1;

        switch (getCol())
        {
        case 0: cout << "A\n"; break;
        case 1: cout << "B\n"; break;
        case 2: cout << "C\n"; break;
        case 3: cout << "D\n"; break;
        case 4: cout << "E\n"; break;
        case 5: cout << "F\n"; break;
        case 6: cout << "G\n"; break;
        case 7: cout << "H\n"; break;
        
        default:
          break;
        }
    }
};