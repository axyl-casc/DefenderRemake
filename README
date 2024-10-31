# Atari ST Game - Defender

## Overview

Defender is a 2D side-scrolling space shooter game developed for the Atari ST as part of the COMP 2659 course project. The player controls a spaceship to defend Earth against alien invaders. This game supports single-player mode and includes animated graphics, sound effects, and a mouse-driven main menu.

## Features

- **Gameplay**: The player navigates a spaceship and fights waves of aliens. Aliens spawn at random positions and shoot at the player. The objective is to destroy as many aliens as possible while avoiding incoming fire.
- **Input**: Both keyboard and mouse are utilized. Keyboard controls are used for gameplay, while mouse input is primarily for the splash screen and menu navigation.
- **Graphics and Animation**: The game employs double-buffered graphics for flicker-free animation at approximately 70 FPS, leveraging the vertical blank (VBL) interrupt for timing.
- **Sound**: Music and sound effects are generated directly through the PSG chip, with simple melodies and sound effects to enhance gameplay.
- **Main Menu**: A mouse-driven splash screen is displayed at startup, where players can choose between game modes or exit.

## Technical Details

### Game Loop and Interrupts

The game loop is driven by a VBL interrupt service routine (ISR) running at 70Hz, synchronized with the screen refresh rate:
- **Double Buffering**: Ensures smooth animation by timing the page flipping for each frame in sync with the VBL ISR.
- **Sound and Music**: Music and effects are managed independently through custom PSG routines.
- **Mouse and Keyboard Input**: A custom IKBD ISR handles all mouse and keyboard input, maintaining smooth input handling independent of the game loop.

### Key Modules

- **Main Game Loop**: Handles the primary game actions, such as rendering frames, updating the model, and processing input events.
- **ISRs**:
  - **VBL ISR**: Manages double-buffered graphics, music timing, and synchronous events like animation.
  - **IKBD ISR**: Processes mouse and keyboard input, including mouse position updates to ensure real-time responsiveness.
- **PSG Sound Control**: Low-level routines manage the PSG chip for direct sound production, allowing control over tone, volume, and noise channels.
- **Mouse-Driven Splash Screen**: Initializes with menu options ("1 Player", "2 Player", and "Quit") and is navigated using mouse clicks. The cursor position is updated by the IKBD ISR, providing smooth pointer movement on the splash screen.

### Known Issues

- **Menu Mouse Lag**: The mouse moves slowly in the main menu due to the current setup of buffer redraws each frame.
- **ISR `_enable_channel` Conflict**: A double definition error for `_enable_channel` exists but does not impact gameplay.
- **Global Variable Use**: Future improvements could focus on reducing global variable usage for better modularity.

### Dependencies

- **Steem Emulator**: The game is designed to run on the Steem Atari ST emulator, in monochrome resolution with black and white display.

## Compilation and Setup

To compile and run the game:
1. Ensure you have the Steem emulator configured for Atari ST with monochrome settings.
2. Compile using the 'make' file
3. Run the game using ./defend~1.tos

## Acknowledgments

Developed by Axyl Carefoot-Schulz (ID: 201694318) for COMP 2659 under the guidance of instructor Paul Pospisil.

## Future Improvements

- Optimize the menu rendering to reduce mouse input lag.
- Modularize code to reduce reliance on global variables.
- Improve sound effects synchronization with game actions.

