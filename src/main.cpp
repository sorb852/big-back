#include <raylib.h>
#include <raymath.h>

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

int main() {
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "");
  SetConfigFlags(FLAG_VSYNC_HINT | FLAG_BORDERLESS_WINDOWED_MODE |
                 FLAG_WINDOW_UNDECORATED | FLAG_WINDOW_TOPMOST |
                 FLAG_WINDOW_TRANSPARENT);
  SetTargetFPS(60);
  SetExitKey(KEY_Q);

  TraceLog(LOG_DEBUG, "Hi???");

  float dt = 0.0;

  Vector2 velocity{200, 200};
  Vector2 pos = GetWindowPosition();
  Vector2 dimensions =
      Vector2{(float)GetMonitorWidth(0), (float)GetMonitorHeight(0)};

  size_t ran = 0;
  float anim_timer = 0.0;
  float anim_cd = 0.4;

  Texture2D big_back[3] = {
      LoadTexture("resource/big_back1.png"),
      LoadTexture("resource/big_back2.png"),
      LoadTexture("resource/big_back3.png"),
  };
  // Main loop
  while (!WindowShouldClose()) {
    dt = GetFrameTime();
    anim_timer += dt;
    if (anim_timer > anim_cd) {
      anim_timer -= anim_cd;
      ran += 1;
      if (ran > 3) {
        ran = 0;
      }
    }
    // Update
    if (pos.x + WINDOW_WIDTH > dimensions.x || pos.x < 0) {
      velocity.x *= -1;
    }
    if (pos.y + WINDOW_HEIGHT > dimensions.y || pos.y < 0) {
      velocity.y *= -1;
    }
    pos = Vector2Add(pos, Vector2Scale(velocity, dt));
    SetWindowPosition((int)pos.x, (int)pos.y);

    // Draw
    BeginDrawing();
    ClearBackground(BLACK);

    if (ran == 3) {
      DrawTexturePro(big_back[1],
                     Rectangle{0.0, 0.0, -(float)big_back[1].width,
                               (float)big_back[1].height},
                     Rectangle{0.0, 0.0, WINDOW_WIDTH, WINDOW_HEIGHT},
                     Vector2Zero(), 0.0f, WHITE);
    } else {
      DrawTexturePro(big_back[ran],
                     Rectangle{0, 0, (float)big_back[ran].width,
                               (float)big_back[ran].height},
                     Rectangle{0, 0, WINDOW_WIDTH, WINDOW_HEIGHT},
                     Vector2Zero(), 0.0f, WHITE);
    }

    EndDrawing();
  }

  // Clear
  for (auto &&i : big_back)
    UnloadTexture(i);
  CloseWindow();
  return 0;
}
