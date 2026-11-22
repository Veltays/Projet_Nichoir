# Bibliothèques Altium du projet

Les bibliothèques nécessaires au schéma sont conservées dans le dossier `Libraries` afin que le projet reste portable après un clone Git.

## Installation dans Altium Designer

1. Ouvrir le panneau **Components**.
2. Ouvrir le menu du panneau, puis **File-based Libraries Preferences**.
3. Dans l'onglet **Installed**, choisir **Install**.
4. Installer les deux fichiers suivants :
   - `Libraries/AltiumCAOQ2_2023/AltiumCAOQ2_2023.IntLib`
   - `Libraries/First Integrated Library/First Integrated Library.IntLib`

Les fichiers `.SchLib`, `.PcbLib` et `.LibPkg` sont également inclus pour permettre de modifier et recompiler les bibliothèques.
