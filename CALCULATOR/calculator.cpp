#include <graphics.h>
#include <conio.h>
#include <iostream>
using namespace std;

// functions
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
float divi(int a, int b) { return (float)a / b; }

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Calculator box
    rectangle(100, 100, 400, 400);
    outtextxy(200, 110, "Calculator");

    // Buttons
    rectangle(130, 160, 190, 210); outtextxy(155, 180, "+");
    rectangle(210, 160, 270, 210); outtextxy(235, 180, "-");
    rectangle(130, 230, 190, 280); outtextxy(155, 250, "*");
    rectangle(210, 230, 270, 280); outtextxy(235, 250, "/");

    int a = 10, b = 5;
    int result = add(a, b);
    char res[20];
    sprintf(res, "Result: %d", result);
    outtextxy(150, 320, res);

    getch();
    closegraph();
}

