#include <raylib.h>
#include <iostream>
// Window --
int screenHeight = 600;
int screenWidth = 800;
// Ball -- 
float radius = 30;
Vector2 ballP =  {400.0f, 300.0f};
Vector2 ballV = {0.0f,380.0f};
float gravity = 9.8; //positive since positive y points downwards 
float floorAt = screenHeight;
// Functions -- 
void checkCollision(){
    if((ballP.y+radius) >= floorAt){
        ballP.y = floorAt-radius;
        ballV.y *= -1;
    }
}

void updateScreen(float deltaTime){
    //first changing the velocity 
    ballV.y += deltaTime * gravity;
    //displacement (Velocity * time which is deltaTime here)

    float displacementY = ballV.y * deltaTime;
    ballP.y += displacementY;
}

//Main -- 
int main() {
    
    SetTargetFPS(60);
    

    InitWindow(screenWidth, screenHeight, "Hormiguero");
    while (!WindowShouldClose()) {
        //time of last frame drawn
        float deltaTime = GetFrameTime();
        
        BeginDrawing();
        ClearBackground(BLACK);
        //std::cout << "DeltaTime: " << deltaTime << "\n";
        updateScreen(deltaTime);
        checkCollision();
        DrawCircleV(ballP, radius, RED);
        EndDrawing();
    }
    CloseWindow();
}

