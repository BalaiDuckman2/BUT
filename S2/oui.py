import pygame
from pygame.locals import *

# Initialize Pygame
pygame.init()

# Set up the display
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Mouse Click Detection")

# Game loop
running = True
while running:
    for event in pygame.event.get():
        if event.type == QUIT:
            running = False
        elif event.type == MOUSEBUTTONDOWN:
            if event.button == 1:  # Left mouse button
                # Code to execute when left mouse button is clicked
                print("Left mouse button clicked at", event.pos)
            elif event.button == 3:  # Right mouse button
                # Code to execute when right mouse button is clicked
                print("Right mouse button clicked at", event.pos)

    pygame.display.update()

# Quit Pygame
pygame.quit()