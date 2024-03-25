import tkinter as tk
from tkinter import messagebox

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

    # Fonction récursive pour trouver tous les chemins possibles
    def find_paths(row, col, move_number):
        nonlocal count, path

        # Marquer la case actuelle avec le numéro de mouvement
        grid[row][col] = move_number
        path.append((row, col))  # Ajouter la case au chemin

        # Si tous les mouvements ont été effectués, incrémenter le compteur
        if move_number == grid_size * grid_size:
            count += 1
        else:
            # Essayer tous les mouvements possibles
            for move in moves:
                next_row = row + move[0]
                next_col = col + move[1]

                # Vérifier si le mouvement est valide et non visité
                if is_valid_move(next_row, next_col, grid):
                    find_paths(next_row, next_col, move_number + 1)

        # Réinitialiser la case actuelle
        grid[row][col] = 0
        path.pop()  # Retirer la case du chemin

    # Vérifier si un mouvement est valide
    def is_valid_move(row, col, grid):
        return 0 <= row < grid_size and 0 <= col < grid_size and grid[row][col] == 0

    # Fonction pour afficher la grille dans une fenêtre tkinter
    def draw_grid(grid):
        window = tk.Tk()
        window.title("Grille du problème du cavalier")
        for i in range(grid_size):
            for j in range(grid_size):
                label = tk.Label(window, text=str(grid[i][j]), width=4, height=2, relief="solid")
                label.grid(row=i, column=j)
        window.mainloop()

    # Demander à l'utilisateur de choisir la ligne et la colonne
    row = int(input("Choisissez la ligne : "))
    col = int(input("Choisissez la colonne : "))
    
    # Appeler la fonction récursive pour trouver tous les chemins possibles
    find_paths(row, col, 1)

    # Retourner le nombre de chemins possibles
    
    return count
    

# Demander à l'utilisateur de choisir la taille de la grille
grid_size = int(input("Choisissez la taille de la grille : "))

# Exemple d'utilisation avec la taille de grille choisie
num_paths = solve_knight_problem(grid_size)
print("Nombre de chemins possibles:", num_paths)

