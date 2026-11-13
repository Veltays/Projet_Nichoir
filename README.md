# Projet Nichoir

Le Projet Nichoir consiste à concevoir un nichoir intelligent capable de détecter la présence d'oiseaux et de les prendre en photo. Les images capturées pourront ensuite être consultées par l'utilisateur.

## Architecture

```text
Projet_Nichoir/
├── documentation/
│   ├── consigne/       # Consignes et présentation du projet
│   ├── datasheet/      # Fiches techniques des composants
│   ├── maquette/       # Documents liés à la maquette
│   └── schematic/      # Schémas électroniques
└── src/
    ├── backend/        # Traitement, stockage et envoi des données
    ├── firmware/       # Programme embarqué dans la carte ESP32
    └── public/         # Fichiers destinés à l'interface utilisateur
```

## Organisation du projet

Le dossier `documentation` rassemble toutes les informations nécessaires à la conception du nichoir : les consignes, les fiches techniques des composants et les schémas électroniques.

Le dossier `src` contient la partie logicielle du projet. `firmware` regroupe le programme exécuté par la carte ESP32 Timer-CAM : il permet de lire le détecteur de mouvement et de commander l'éclairage infrarouge. Le fichier principal se trouve dans `src/firmware/esp32_TimerCam/src/main.cpp`.

Le dossier `backend` est prévu pour la réception, le traitement et le stockage des photos. Le dossier `public` accueillera les fichiers de l'interface permettant à l'utilisateur de consulter les images capturées.
