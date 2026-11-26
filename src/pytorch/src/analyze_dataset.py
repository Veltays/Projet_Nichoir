import sys

from collections import Counter
from torchvision.datasets import ImageFolder
from core.config import DATASET_DIR

sys.stdout.reconfigure(encoding="utf-8")

train = ImageFolder(DATASET_DIR / "train")
val = ImageFolder(DATASET_DIR / "val")

train_counts = Counter(train.targets)
val_counts = Counter(val.targets)

for name, index in train.class_to_idx.items():

    val_index = val.class_to_idx.get(name)

    print(
        f"{name} | " f"Train: {train_counts[index]} | " f"Val: {val_counts[val_index]}"
    )
