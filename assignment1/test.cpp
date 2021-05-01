#include <iostream>
#include "gwindow.h"
#include "gevents.h"
#include "gtypes.h"

using namespace std;

int main() {
    GWindow gw;
    cout << "This program lets the user draw lines by dragging." << endl;
        GMouseEvent e = waitForEvent(MOUSE_EVENT);
        GPoint a; GPoint b;
        if (e.getEventType() == MOUSE_PRESSED) {
            a = GPoint(e.getX(), e.getY());
        } else if (e.getEventType() == MOUSE_DRAGGED) {
            gw.drawLine(e.getX(), e.getY(), e.getX(), e.getY());
            line->setEndPoint(e.getX(), e.getY());
        }
        gw.drawLine(e.getX(), e.getY(), e.getX(), e.getY());
    }
}
