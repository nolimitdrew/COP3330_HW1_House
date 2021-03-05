
/* Name: Andrew Stade
Date: 1/24/2020
Section: 2 */

class House
{
public:
    House(int s, char b = 'X',  char f = '*');    // costructor with parameters
    
    // accessors
    int GetSize() const;
    int Perimeter() const;
    double Area() const;
    
    // mutators
    void Grow();
    void Shrink();
    
    void SetBorder(char newB);
    void SetFill(char newF);
    
    void Draw();
    void Summary();
    

private:
    int size;
    char border;
    char fill;
    
};