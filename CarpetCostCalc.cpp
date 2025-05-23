#include <iostream>
#include <iomanip>
using namespace std;

class FeetInches
{
private:
    int feet;
    int inches;

public:
    FeetInches(int f = 0, int i = 0) : feet(f), inches(i) {}

    void addInches(int additionalInches)
    {
        inches += additionalInches;
        while (inches >= 12)
        {
            inches -= 12;
            feet++;
        }
    }

    FeetInches multiply(int factor)
    {
        int totalInches = (feet * 12 + inches) * factor;
        int resultFeet = totalInches / 12;
        int resultInches = totalInches % 12;
        return FeetInches(resultFeet, resultInches);
    }

    int toInches() const
    {
        return feet * 12 + inches;
    }

    void display() const
    {
        cout << feet << "' " << inches << "\"";
    }
};

class RoomDimension
{
private:
    FeetInches length;
    FeetInches width;

public:
    RoomDimension(FeetInches l, FeetInches w) : length(l), width(w) {}

    FeetInches calculateArea()
    {
        int areaInInches = length.toInches() * width.toInches();
        int areaFeet = areaInInches / 144;
        int areaInchesRemaining = areaInInches % 144;
        return FeetInches(areaFeet, areaInchesRemaining);
    }
};

class RoomCarpet
{
    
private:
    RoomDimension room;
    double pricePerSqFt;

public:
    RoomCarpet(RoomDimension r, double price) : room(r), pricePerSqFt(price) {}

    double calculateCost()
    {
        FeetInches area = room.calculateArea();
        int totalAreaInInches = area.toInches();
        double totalAreaInSquareFeet = totalAreaInInches / 144.0;
        return totalAreaInSquareFeet * pricePerSqFt;
    }
};

int main()
{
    int lengthFeet, lengthInches, widthFeet, widthInches;
    double pricePerSquareFoot;

    cout << "Enter the length of the room (feet): ";
    cin >> lengthFeet;
    cout << "Enter the length of the room (inches): ";
    cin >> lengthInches;

    cout << "Enter the width of the room (feet): ";
    cin >> widthFeet;
    cout << "Enter the width of the room (inches): ";
    cin >> widthInches;

    cout << "Enter the price per square foot of carpet: $";
    cin >> pricePerSquareFoot;

    FeetInches length(lengthFeet, lengthInches);
    FeetInches width(widthFeet, widthInches);

    RoomDimension room(length, width);
    RoomCarpet carpet(room, pricePerSquareFoot);

    double totalCost = carpet.calculateCost();

    cout << "\nThe area of the room is: ";
    room.calculateArea().display();
    cout << " square feet." << endl;
    cout << "The total cost of the carpet is: $" << fixed << setprecision(2) << totalCost << endl;

    return 0;
}
