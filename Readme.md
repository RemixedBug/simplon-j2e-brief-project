# Réalisation technique Simplon.co
## Prérequis
Ce projet utilise C++20 et compile avec GCC version 10.2.0. Il n'a aucune dépendances externe (il ne nécessite que la librairie standard C++).

## Build
Pour build et run le projet :
```
g++ -std=c++20 -o ./cpp/myapp ./cpp/main.cpp
./cpp/myapp
```
Il est aussi possible de le faire avec docker:
```
docker build -t my-gcc-app ./cpp
docker run -it --rm --name my-running-app my-gcc-app
```

## Remarques
Au vu de l'énoncer, il est inutile de stocker la salle comme un tableau à deux dimensions -> faire une liste du nombres de places réservées par rangée serait plus judicieux (il est seulement possible de réserver des places de manière contigue). Je l'ai construit de cette manière pour pouvoir retirer ou choisir des places en milieu de colonnes (me rendant compte après coup que ce n'était pas utile).

Je n'ai pas utiliser d'IDE ni de système de build, l'énoncé étant déjà très simple en lui même (principe KISS).
