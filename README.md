# cub3D-linux
Cub3d est un projet graphique qui utilise comme libraire la minilibx.

Le but est de produire un mini-jeu, utilisant la technique du raycasting comme le FPS Wolfenstein 3D. Il existe de nombreux sites, tuto pour creer le jeu. J'ai utilisé Pikuma. 

Le programme doit :

- Se fermer avec ESC ou red cross
- Utiliser uniquement les fleches ou AWSD
- Etre fluide
- Avoir 4 textures de murs differentes
- Changer la position du joueur selon le NSWE

## Qu'est ce que le raycasting ?

Le principe du raycasting est de tirer des rayons par colonne de pixel, selon la distance de celui ci, le mur apparaitra plus ou moins grand. Plus le rayon est grand, plus le mur est petit, et inversement. 

## Comment utiliser la mlx ?

Pour utiliser la mlx il faut initialiser une fenêtre avec mlx_init.

```c
mlx = mlx_init;
mlx_win = mlx_new_window(mlx, 1920, 1080, "Cub3d");
mlx_loop(mlx);
```

Pour dessiner nos pixels on utilise les images. On recupère ladresse ou mettre nos pixels avec mlx_get_data_addr afin de les envoyer dans notre image. L'image est un color_buffer. Ce qui veut dire que chaque pixel de couleur va etre enregistrer dans un tableau afin de connaitre sa position.

```bash
mlx_new_image(mlx, 1920, 1080);
mlx_get_data_addr(...);
```

 Une fois tous les pixels enregistrés, on affiche tout avec mlx_put_img_to_win.

```c
mlx_put_image_to_window(mlx, win, img, 0, 0);
```

### Gerer les evenements avec loop_hook

```c
mlx_loop_hook(mlx, &render, strc);
```

La fonction loop_hook crée une boucle infinie avec en parametre un pointeur sur fonction (ici render). Pendant tout le jeu, render va être exécuté, ce qui permet de redessiner par dessus a chaque fois avec les nouveaux calculs faits.

```c
int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
```

mlx_hook appelle une fonction lorsque l'événement x_event au masque x_mask se déroule.

## Pour plus de details sur ma facon de faire le projet
Notion https://glow-virgo-496.notion.site/Cub3d-read_me-7a2198b081eb404b91bde32acc15c014
