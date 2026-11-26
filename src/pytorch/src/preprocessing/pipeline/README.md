# Image Preprocessing Pipeline

## Objectif

Ce pipeline prépare les images d'oiseaux avant leur utilisation par un modèle de classification développé avec PyTorch.
Il permet d'uniformiser les dimensions, le format et les valeurs numériques des images, aussi bien pour l'entraînement que pour l'inférence.

## Étapes du pipeline

| Étape | Description |
|---|---|
| **Load Image** | Chargement de l'image et conversion au format RGB. |
| **Resize** | Redimensionnement du plus petit côté à 256 pixels en conservant les proportions, suivi d'un recadrage central de 224 × 224 pixels. |
| **Data Augmentation** | Application de transformations aléatoires, uniquement pendant l'entraînement. |
| **To Tensor** | Conversion de l'image en tenseur PyTorch de type `float32`, avec des valeurs comprises entre 0 et 1. |
| **Normalize** | Normalisation des valeurs selon les moyennes et écarts-types de référence d'ImageNet. |

## Data Augmentation

La Data Augmentation permet de générer différentes variations d'une même image afin d'améliorer la capacité de généralisation du modèle et de limiter le surapprentissage (*overfitting*).

Les transformations utilisées sont :

- Retournement horizontal (50 %).
- Rotation aléatoire (±15°).
- Variation de la luminosité (±30 %).
- Variation du contraste (±30 %).
- Conversion en niveaux de gris (30 %).
- Application d'un flou gaussien (15 %).

Ces transformations sont appliquées dynamiquement, sans modifier les images originales. La conversion en niveaux de gris simule partiellement la perte de couleur sous éclairage infrarouge, sans reproduire parfaitement une capture infrarouge réelle.

## Normalisation

La normalisation est effectuée indépendamment sur chaque canal RGB selon la formule suivante :

`x_normalized = (x - mean) / std`

Les valeurs utilisées correspondent aux références d'ImageNet :

| Canal | Mean | Standard deviation |
|---|---:|---:|
| Red | 0.485 | 0.229 |
| Green | 0.456 | 0.224 |
| Blue | 0.406 | 0.225 |

## Modes de fonctionnement

### Training — `training=True`

Load Image → Resize → Augmentation → To Tensor → Normalize

Ce mode prépare les images du dataset d'entraînement en générant des variations aléatoires.

### Inference — `training=False`

Load Image → Resize → To Tensor → Normalize

Ce mode est utilisé pour la validation, les tests et la classification de nouvelles images. Aucune augmentation aléatoire n'est appliquée afin de garantir un prétraitement déterministe.

## Résultat

Le pipeline retourne un tenseur présentant les caractéristiques suivantes :

| Propriété | Valeur |
|---|---|
| Dimensions | 3 × 224 × 224 |
| Canaux | RGB |
| Type | float32 |
| Normalisation | ImageNet |

Le pipeline ne réalise lui-même ni l'entraînement ni la classification des images. Sa responsabilité est uniquement de préparer les données d'entrée du réseau neuronal.