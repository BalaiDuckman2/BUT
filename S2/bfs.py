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

    # Fonction BFS pour trouver tous les chemins possibles
    def find_paths(row, col):
        nonlocal count, path

        # Marquer la case actuelle avec le numéro de mouvement
        grid[row][col] = 1
        path.append((row, col))  # Ajouter la case au chemin

        # Si tous les mouvements ont été effectués, incrémenter le compteur
        if len(path) == grid_size * grid_size:
            count += 1
        else:
            # Essayer tous les mouvements possibles
            for move in moves:
                new_row, new_col = row + move[0], col + move[1]
                if 0 <= new_row < grid_size and 0 <= new_col < grid_size and grid[new_row][new_col] == 0:
                    find_paths(new_row, new_col)

        # Retirer la case du chemin et la marquer comme non visitée
        path.pop()
        grid[row][col] = 0

    find_paths(0, 0)
    print(f"Total paths: {count}")

solve_knight_problem(5)