#include <iostream>
#include <vector>
#include "console.h"
#include "gevent.h"
#include "gtimer.h"
#include "gwindow.h"
#include "random.h"

using namespace std;

volatile bool isDrawing = true;
const int TRIANGLE_POINTS = 3;

GPoint ClickPoint() {
    while(true) {
        GMouseEvent e = waitForEvent(MOUSE_EVENT);
        if(e.getEventType() == MOUSE_CLICKED) {
            return GPoint(e.getX(), e.getY());
        }
    }
}

GPoint GetMidpoint(const GPoint& pA, const GPoint& pB) {
    int mid_x = (pA.x + pB.x)/2;
    int mid_y = (pA.y + pB.y)/2;
    return GPoint(mid_x, mid_y);
}

void DrawAndUpdatePoint(GWindow& gw, const vector<GPoint>& points, GPoint& prev) {
    int draw_idx = randomInteger(0, TRIANGLE_POINTS-1);
    prev = GetMidpoint(points[draw_idx], prev);
    gw.fillOval(prev.x, prev.y, 3, 3);
}

void StopDrawing(GEvent e) {
    if(e.getEventType() == MOUSE_CLICKED) isDrawing = false;
}

void ChaosGame(GWindow& gw, const vector<GPoint>& points) {
    gw.setColor("black");
    GPoint prev = points[randomInteger(0, TRIANGLE_POINTS-1)];
    gw.setMouseListener(StopDrawing);
    while(isDrawing) {
        DrawAndUpdatePoint(gw, points, prev);
        gw.repaint();
    }
}

int main2() {
    GWindow gw;
    vector<GPoint> points(TRIANGLE_POINTS);
    cout << "Click three points to create a triangle." << endl;
    for(int i = 0; i < TRIANGLE_POINTS; i++) {
        points[i] = ClickPoint();
    }

    cout << "Starting Chaos Game. Click to end Chaos Game." << endl;
    ChaosGame(gw, points);
    return 0;
}
