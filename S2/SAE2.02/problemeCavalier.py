def solve_knight_problem(start_x, start_y, board_size):
    # Créer un échiquier vide
    board = [[-1] * board_size for _ in range(board_size)]

    # Liste des mouvements possibles du cavalier
    moves = [(2, 1), (1, 2), (-1, 2), (-2, 1),
             (-2, -1), (-1, -2), (1, -2), (2, -1)]

    # Fonction récursive pour trouver un chemin valide
    def dfs(x, y, move_count):
        # Marquer la case actuelle avec le nombre de mouvements
        board[x][y] = move_count

        # Vérifier si tous les mouvements ont été effectués
        if move_count == board_size ** 2 - 1:
            return True

        # Parcourir tous les mouvements possibles
        for dx, dy in moves:
            next_x, next_y = x + dx, y + dy

            # Vérifier si le mouvement est valide et la case n'a pas été visitée
            if 0 <= next_x < board_size and 0 <= next_y < board_size and board[next_x][next_y] == -1:
                # Récursivement explorer le prochain mouvement
                if dfs(next_x, next_y, move_count + 1):
                    return True

        # Si aucun mouvement valide n'a été trouvé, démarquer la case actuelle
        board[x][y] = -1
        return False

    # Appeler la fonction récursive avec les coordonnées de départ
    if dfs(start_x, start_y, 0):
        # Afficher le chemin trouvé
        for row in board:
            print(row)
    else:
        print("Aucun chemin trouvé")

# Exemple d'utilisation
solve_knight_problem(0, 0, 8)