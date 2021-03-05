
/* Name: Andrew Stade
Date: 1/24/2020
Section: 2 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include "house.h"

using namespace std;

House::House(int s, char b, char f)
// Initializes house in s, b, and f.
// s is size, b is border, f is fill.
{
    if (s < 3) // Ask for size integer
    {
        size = 3;
        s = 3;
    }
    else if (s > 37)
    {
        size = 37;
        s = 37;
    }
    else
    {
        size = s;
    }
    
    if (b >= '!' || b <= '~') // Ask for border character
    {
        border = b;
    }
    else 
    {
        border = 'X';
    }
    
    if (f >= '!' || f <= '~') // Ask for fill character
    {
        fill = f;
    }
    else 
    {
        fill = '*';
    }
}

int House::GetSize() const
// Grab the size of the house
{
    return size;
}

int House::Perimeter() const
// Calculates and then returns the perimeter.
{
    return (size + size + size + size+2 + size+2 + 2);
}

double House::Area() const
// Computes the area of the equilateral triangle and square.
{
    return (sqrt(3)/4 * (size+2) * (size+2) + size * size);
}

void House::Grow()
// Allows the house to grow by 1.
{
    if (size < 37)
    {
        size = size + 1;
    }
    else
    {
        size = size;
    }
}

void House::Shrink()
// Allows the house to shrink by 1.
{
    if (size > 3)
    {
        size = size - 1;
    }
    else
    {
        size = size;
    }
}

void House::SetBorder(char newB)
// Sets the border of the house to a new character.
{
    if (newB >= '!' && newB <= '~')
    {
        border = newB;
    }
    else 
    {
        border = 'X';
        newB = 'X';
    }
}


void House::SetFill(char newF)
// Sets the fill of the house to a new character.
{
    if (newF >= '!' && newF <= '~')
    {
        fill = newF;
    }
    else 
    {
        fill = '*';
        newF = '*';
    }
}
    

void House::Draw()
// Creates the house.
{
   int shape = 2;
   int side = 4;
    
   for(int i = shape; i <= size+2; i++) // Creates the roof (except for bottom row)
   {
        for (int j = 0; j <= size+2-i; j++)
        {
            cout << " ";
        }
        if (i > shape)
        {
            cout << border << " ";
        }
        if (i > shape)
        {
            for (int k = side; k <= i; k++)
            {
            cout << fill << " ";
            }
        } 
       cout << border << " ";
       cout << endl; 
   }
   for (int l = 0; l < 2; l++) // Drawing the end of the roof (border)
   {
       cout << border << " ";
   }
   for (int m = 0; m < size-2; m++) // Draws the middle of the roof base (fill)
   {
       cout << fill << " ";
   }
   for (int n = 0; n < 2; n++) // Draws the end of the roof (border)
   {
       cout << border << " ";
   }
   for (int o = shape; o < size; o++) // Draws the "inside" of the house
   {
       cout << endl;
       for (int p = 0; p < 1; p++)
       {
            cout << "  " << border << " ";
       }
       for (int q = 0; q < size-2; q++)
       {
            cout << fill << " ";
       }
       for (int r = 0; r < 1; r++)
       {
            cout << border << "  ";
       }
   }    
   cout << endl;
   for (int t = 0; t < 1; t++) // Draws the base of the house
   {
       cout << "  ";
   }
   for (int u = 0; u < size; u++)
   {        
       cout << border << " ";
   }
   for (int v = 0; v < 1; v++)
   {
       cout << "  ";
       cout << endl;
   }
}

void House::Summary()
// Displays information about the house.
{
    cout << fixed << showpoint << setprecision(2);
    cout << "House width and height base to roof = " << GetSize() << " units."; 
    cout << "\nPerimeter of house = " << Perimeter() << " units.";
    cout << "\nArea of house = " << Area() << " units.";
    cout << "\nHouse looks like: \n"; Draw();
}


