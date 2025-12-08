# Snake Game - STM32F429I-DISCO (TouchGFX)

This project is a classic **Snake Game** implementation running on the **STM32F429I-DISCO** board, built using **TouchGFX** and **STM32CubeIDE**.

## 🎮 How to Play
* **Start Game:** Swipe in any direction to begin moving.
* **Controls:** **Swipe** Up, Down, Left, or Right on the touchscreen to change direction.
* **Game Over:** If the snake hits a wall or its own tail, the game freezes.
* **Restart:** **Tap (Click)** After game over **Swipe** to start a new game.

## ✨ Key Features
* **MVP Architecture:** Logic is handled in the `Model`, strictly separated from the UI (`View`).
* **Procedural Graphics:** The chessboard grid background is drawn programmatically using `Box` widgets to save memory (no large background images required).
* **Smart Spawning:** The food generation algorithm ensures the random spawn property
* **Visuals:**
    * **Grid:** Procedural Purple/Violet pattern.
    * **Snake:** Green body with a Blue head.
    * **Apple:** Red square.

## 🛠 Hardware & Resolution
* **Board:** STM32F429I-DISCO (Rev D01)
* **Resolution:** 320 x 240 pixels @ 16bpp

## 🔨 Development
The default IDE is set to **STM32CubeIDE**.
1.  **TouchGFX Designer:** Used for layout configuration (Screen, Container, Wildcards).
2.  **STM32CubeIDE:** Used for C++ game logic implementation (`Model.cpp`, `Screen1View.cpp`).

### Performance Testing Signals (GPIO)
* **VSYNC_FREQ:** Pin PE2
* **RENDER_TIME:** Pin PE3
* **FRAME_RATE:** Pin PE4
* **MCU_ACTIVE:** Pin PE5