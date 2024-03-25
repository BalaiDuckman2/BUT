import pygame
from pygame.locals import *

def solve_knight_problem(grid_size):
    # Créer une grille vide
    grid = [[0 for _ in range(grid_size)] for _ in range(grid_size)]

    # Liste des mouvements possibles du cavalier
    moves = [
        (2, 1), (1, 2), (-1, 2), (-2, 1),
        (-2, -1), (-1, -2), (1, -2), (2, -1)
    ]

    # Variable de comptage des chemins possibles
    count = 0

    # Liste pour stocker un chemin possible
    path = []

    # Demander le temps entre chaque chemin
    time_between_paths = int(input("Enter the time between each path (in milliseconds): "))

    # Initialiser pygame
    pygame.init()
    screen = pygame.display.set_mode((grid_size * 50, grid_size * 50))
    pygame.display.set_caption("Knight's Tour")
    clock = pygame.time.Clock()

    # Fonction BFS pour trouver tous les chemins possibles
    def find_paths(row, col):
        nonlocal count, path

        # Marquer la case actuelle avec le numéro de mouvement
        grid[row][col] = 1
        path.append((row, col))  # Ajouter la case au chemin

        # Si tous les mouvements ont été effectués, incrémenter le compteur
        if len(path) == grid_size * grid_size:
            count += 1
            print(f"Path {count}: {path}")  # Afficher le chemin
            draw_path(path)  # Dessiner le chemin sur l'échiquier
            pygame.display.flip()  # Mettre à jour l'affichage
            pygame.time.wait(time_between_paths)  # Attendre le temps spécifié

        else:
            # Essayer tous les mouvements possibles
            for move in moves:
                new_row, new_col = row + move[0], col + move[1]
                if 0 <= new_row < grid_size and 0 <= new_col < grid_size and grid[new_row][new_col] == 0:
                    find_paths(new_row, new_col)

        # Retirer la case du chemin et la marquer comme non visitée
        path.pop()
        grid[row][col] = 0

    def draw_path(path):
        screen.fill((255, 255, 255))  # Effacer l'échiquier
        for i, (row, col) in enumerate(path):
            pygame.draw.rect(screen, (0, 0, 0), (col * 50, row * 50, 50, 50))  # Dessiner une case noire
            pygame.draw.rect(screen, (255, 0, 0), (col * 50 + 5, row * 50 + 5, 40, 40))  # Dessiner un case rouge
            font = pygame.font.Font(None, 30)
            text = font.render(str(i + 1), True, (255, 255, 255))
            screen.blit(text, (col * 50 + 20, row * 50 + 20))  # Afficher le numéro du mouvement

    find_paths(0, 0)
    print(f"Total paths: {count}")

    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        clock.tick(60)

    pygame.quit()

solve_knight_problem(5)
