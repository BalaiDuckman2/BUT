import tkinter as tk
from tkinter import messagebox

def solve_knight_problem():
    # Demander à l'utilisateur de choisir la taille du plateau
    grid_size = int(input("Choisissez la taille du plateau : "))

    # Créer une grille vide
    grid = [[0 for _ in range(grid_size)] for _ in range(grid_size)]

    # Liste des mouvements possibles du cavalier
    moves = [
        (2, 1), (1, 2), (-1, 2), (-2, 1),
        (-2, -1), (-1, -2), (1, -2), (2, -1)
    ]

    # Variable de comptage des chemins possibles
    count = 0

    # Fonction récursive pour trouver tous les chemins possibles
    def find_paths(row, col, move_number):
        nonlocal count

        # Marquer la case actuelle avec le numéro de mouvement
        grid[row][col] = move_number

        # Si tous les mouvements ont été effectués, incrémenter le compteur
        if move_number == grid_size * grid_size:
            count += 1
            display_board()
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

    # Vérifier si un mouvement est valide
    def is_valid_move(row, col, grid):
        return 0 <= row < grid_size and 0 <= col < grid_size and grid[row][col] == 0

    # Afficher le plateau de jeu
    def display_board():
        window = tk.Tk()
        window.title("Problème du cavalier")
        window.geometry("400x400")

        for i in range(grid_size):
            for j in range(grid_size):
                label = tk.Label(window, text=str(grid[i][j]), width=4, height=2, relief="solid")
                label.grid(row=i, column=j)

        messagebox.showinfo("Nombre de chemins possibles", "Nombre de chemins possibles: " + str(count))

        window.mainloop()

    # Demander à l'utilisateur de choisir la ligne et la colonne
    row = int(input("Choisissez la ligne : "))
    col = int(input("Choisissez la colonne : "))

    # Appeler la fonction récursive pour trouver tous les chemins possibles
    find_paths(row, col, 1)

# Appeler la fonction pour résoudre le problème du cavalier
solve_knight_problem()
