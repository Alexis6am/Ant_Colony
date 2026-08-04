#include <raylib.h>

int main() {
    InitWindow(800, 600, "Hormiguero");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawCircle(400, 300, 30, GREEN);
        EndDrawing();
    }
    CloseWindow();
}