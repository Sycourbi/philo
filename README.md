# Philosopher

![C Language](https://img.shields.io/badge/language-C-blue)
![Threads](https://img.shields.io/badge/threads-yes-brightgreen)
![Mutex](https://img.shields.io/badge/mutex-yes-blue)
![Synchronization](https://img.shields.io/badge/synchronization-yes-yellow)
![Deadlock Prevention](https://img.shields.io/badge/deadlock%20prevention-yes-green)
![42](https://img.shields.io/badge/school-42-green)
![42 Paris](https://img.shields.io/badge/42-Paris-blue)

## Description

Bienvenue sur le dépôt du projet Philosopher de l'École 42. Ce projet consiste à simuler le problème classique des philosophes et du repas. Les philosophes doivent se partager des ressources limitées (fourchettes) pour manger et réfléchir, tout en évitant les situations de deadlock et de starvation.


## Badge et Note Obtenu

<div align="center">
  <img src="https://github.com/ayogun/42-project-badges/blob/main/badges/philosopherse.png?raw=true" alt="Badge du projet philosopher">
</div>

## Fonctionnalités
  - Simulation du Problème des Philosophes :
Le programme simule de manière réaliste le problème classique des philosophes et du repas, où plusieurs philosophes doivent partager des ressources (fourchettes) pour manger et réfléchir.

  - Gestion des Ressources :
Implémentation d'un mécanisme de gestion des ressources partagées (les fourchettes) pour éviter les conflits et garantir que les philosophes puissent manger sans provoquer de deadlock (interblocage) ou de starvation (privation).

  - Prévention des Situations de Blocage :
Une approche efficace pour éviter les situations de deadlock en utilisant des algorithmes de gestion des ressources comme la hiérarchisation des ressources ou la libération anticipée.

  - Paramétrage Dynamique :
La possibilité de paramétrer le nombre de philosophes, ainsi que les délais de temps avant la faim, de manger et de dormir, permettant une simulation flexible et personnalisée du problème.

## Installation

Pour installer le projet Philosopher, suivez ces étapes :

1. Clonez le dépôt :

   ```bash
   git clone https://github.com/Sycourbi/philosopher.git
   cd philosopher
   make
   ./philosopher 5 800 200 200
