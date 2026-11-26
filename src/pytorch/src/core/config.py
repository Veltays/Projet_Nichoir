from pathlib import Path


# Point de départ commun pour construire les chemins du projet PyTorch.
PROJECT_DIR = Path(__file__).resolve().parents[2]

# Emplacements utilisés par l'entraînement, l'analyse et la prédiction.
DATASET_DIR = PROJECT_DIR / "dataset" / "curated_50"
MODEL_PATH = PROJECT_DIR / "models" / "best_model.pth"

# Paramètres simples à ajuster avant un nouvel entraînement.
EPOCHS = 20
LEARNING_RATE = 0.001
BATCH_SIZE = 32
