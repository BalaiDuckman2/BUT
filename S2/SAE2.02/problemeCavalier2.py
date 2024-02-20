import tkinter as tk
from tkinter import messagebox

# Fonction pour résoudre le problème du cavalier
def solve_knight_problem():
    # Votre algorithme de résolution du problème du cavalier ici
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
            # Afficher une boîte de dialogue avec la solution
            messagebox.showinfo("Solution", "Voici la solution du problème du cavalier !")
        else:
            print("Aucun chemin trouvé")

    # Exemple d'utilisation
    solve_knight_problem(0, 0, 8)

# Créer la fenêtre principale
window = tk.Tk()
window.title("Problème du cavalier")

# Créer un canevas pour afficher le plateau
canvas = tk.Canvas(window, width=400, height=400)
canvas.pack()

# Fonction pour dessiner le plateau
def draw_board(board_size, board):
    square_size = 400 // board_size
    for i in range(board_size):
        for j in range(board_size):
            x1 = j * square_size
            y1 = i * square_size
            x2 = (j + 1) * square_size
            y2 = (i + 1) * square_size
            canvas.create_rectangle(x1, y1, x2, y2, fill="white")
            canvas.create_text((x1 + x2) // 2, (y1 + y2) // 2, text=str(board[i][j]))

# Fonction pour résoudre le problème du cavalier
def solve_knight_problem_gui():
    # Obtenir les valeurs des coordonnées de départ et de la taille du plateau depuis des entrées utilisateur
    start_x = int(start_x_entry.get())
    start_y = int(start_y_entry.get())
    board_size = int(board_size_entry.get())

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
            draw_board(board_size, board)
            messagebox.showinfo("Solution", "Voici la solution du problème du cavalier !")
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
        draw_board(board_size, board)
    else:
        messagebox.showinfo("Solution", "Aucun chemin trouvé")



# Créer des entrées pour les coordonnées de départ et la taille du plateau
start_x_label = tk.Label(window, text="Coordonnée X de départ:")
start_x_label.pack()
start_x_entry = tk.Entry(window)
start_x_entry.pack()

start_y_label = tk.Label(window, text="Coordonnée Y de départ:")
start_y_label.pack()
start_y_entry = tk.Entry(window)
start_y_entry.pack()

board_size_label = tk.Label(window, text="Taille du plateau:")
board_size_label.pack()
board_size_entry = tk.Entry(window)
board_size_entry.pack()

# Créer un bouton pour résoudre le problème du cavalier
solve_button = tk.Button(window, text="Résoudre", command=solve_knight_problem_gui)
solve_button.pack()

# Lancer la boucle principale de l'interface graphique
window.mainloop()