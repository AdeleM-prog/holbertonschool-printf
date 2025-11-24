# holbertonschool-printf

- Description: recodage de la fonction printf (nommee Ici _printf) en utilisant toutes les connaissances apprises jusqu'a present (switch, fonctions variadiques...). La fonction printf affiche une selection donnee et choisie par l'utilisateur, elle va lire les caracteres, les compter, detecter les %, analyser le format voulu par l'utilisateur (parser), appeler la bone fonction, et retourner le nombre de caracteres ecrits au format voulu.

Prototype : int _printf(const char *format, ...);

Liste des fichiers presents et fonction:
- main.h
- main.c
- ...

- Liste des fonctionnalites prises en charge:
  - %d
  - %3d
  - %ld
  - %lu
  - %x
  - %X
  - %f
  - %lf
  - %5.2lf
  - %c
  - %s
  - %10s
  - %p
  - %%

- Compilation : gcc -Wall -Werror -Wextra -pedantic -std=gnu89
