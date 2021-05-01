#include <iostream>
#include "gwindow.h"
#include "gevents.h"

using namespace std;

GPoint ClickPoint()
{
    cout << "1" << endl;
    while(true)
    {
        GMouseEvent e = waitForEvent(MOUSE_EVENT);
        cout << "2" << endl;
        if(e.getEventType() == MOUSE_CLICKED)
        {
            return GPoint(e.getX(), e.getY());
        }
    }
}

void DrawAndUpdatePoint(GWindow& gw, GPoint& pA, GPoint& pB, GPoint& pC)
{

}

void ChaosGame(GWindow& gw, GPoint& pA, GPoint& pB, GPoint& pC)
{
    while(true)
    {
        GMouseEvent e = waitForEvent(MOUSE_EVENT);
        if(e.getEventType() == MOUSE_CLICKED)
        {
            return;
        }
        gw.drawOval(pA.getX(), pA.getY(), 5, 5);
        gw.drawOval(pB.getX(), pB.getY(), 5, 5);
        gw.drawOval(pC.getX(), pC.getY(), 5, 5);
    }
}

int main()
{
    GWindow gw;

    cout << "Click three points to create a triangle." << endl;
    GPoint pA = ClickPoint();
    cout << "Click two more points." << endl;
    GPoint pB = ClickPoint();
    cout << "Click one more point." << endl;
    GPoint pC = ClickPoint();
    cout << "Done! Starting Chaos Game. Click to end." << endl;

    ChaosGame(gw, pA, pB, pC);
    return 0;
}