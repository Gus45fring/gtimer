#include<iostream>
#include<fstream>
#include "raylib.h"
using namespace std;

double avg() 
{
    double num;
    int count = 0;
    double sum = 0;
    double average = 0;
    ifstream file ("time.txt");
    while (file >> num) 
    {
        sum += num;
        count++;
    }
    if (count == 0) 
    {
        cerr << "no values in file";
    } else
    {
        double average = sum/count;
        
    }
    return average;
}

int main() 
{
    const int screenWidth = 800;
    const int screenHeight = 640;
    float time = 0;
    bool timerStarted = false;
    ofstream timedata("time.txt", ios::app);
    double average = 0;

    InitWindow(screenWidth,screenHeight, "gtimer");

    SetTargetFPS(60);
    //game loop
    while (!WindowShouldClose()) 
    {
        // start/stop the timer
        if (IsKeyReleased(KEY_SPACE) == true && timerStarted == false && time == 0.0) (timerStarted = true);
        if (IsKeyDown(KEY_SPACE) == false && timerStarted == true) 
        {
            time = time + GetFrameTime();
        }
        if (IsKeyDown(KEY_SPACE) == true && timerStarted == true) 
        {
            timerStarted = false;
            //saving time
            timedata << time << endl;
            
        }
        //reset time
        if (IsKeyDown(KEY_R) == true && timerStarted == false) (time = 0);

        //supposedly calculate the average
        
        double average = avg();

        //draw text
        BeginDrawing();
            ClearBackground(WHITE);
            DrawText(TextFormat("%03.03f", time), screenWidth/2, screenHeight/2, 40, BLACK);
            DrawText("average:", 10, screenHeight/2-100, 40, BLACK);
            DrawText(TextFormat("%03.03f", average), 10, screenHeight/2, 40, BLACK);
        EndDrawing();
    }

    CloseWindow(); 

    return 0;

}
