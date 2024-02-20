import tkinter as tk

# Fonction pour résoudre le problème du cavalier
def solve_knight_problem():
    # Votre algorithme de résolution du problème du cavalier ici

    # Exemple de déplacement du cavalier
    moves = [(2, 1), (1, 2), (-1, 2), (-2, 1), (-2, -1), (-1, -2), (1, -2), (2, -1)]

    # Création de la fenêtre Tkinter
    window = tk.Tk()
    window.title("Problème du cavalier")

    # Création d'un canevas pour afficher le déplacement du cavalier
    canvas = tk.Canvas(window, width=400, height=400)
    canvas.pack()

    # Position initiale du cavalier
    x, y = 200, 200

    # Affichage du déplacement du cavalier
    for move in moves:
        dx, dy = move
        x += dx * 50
        y += dy * 50
        canvas.create_oval(x-25, y-25, x+25, y+25, fill="red")
        canvas.update()
        canvas.after(500)  # Délai de 500 millisecondes entre chaque déplacement

    # Fermeture de la fenêtre Tkinter
    window.mainloop()

# Appel de la fonction pour résoudre le problème du cavalier
solve_knight_problem()