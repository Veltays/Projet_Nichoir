import torch
from torch import nn
from torch.optim import Adam
from core.config import BATCH_SIZE, DATASET_DIR, EPOCHS, LEARNING_RATE, MODEL_PATH
from data.dataloader import create_dataloader
from data.dataset import load_dataset
from modeling.model import create_model
from training.checkpoint import save_model
from training.train import train_epoch
from training.validate import validate

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

train_dataset = load_dataset(DATASET_DIR / "train", training=True)
val_dataset = load_dataset(DATASET_DIR / "val")

train_loader = create_dataloader(train_dataset, batch_size=BATCH_SIZE, shuffle=True)
val_loader = create_dataloader(val_dataset, batch_size=BATCH_SIZE)

model = create_model(len(train_dataset.classes)).to(device)

criterion = nn.CrossEntropyLoss()

optimizer = Adam(model.classifier[-1].parameters(), lr=LEARNING_RATE)

print("Device:", device)


MODEL_PATH.parent.mkdir(exist_ok=True)

best_accuracy = 0


for epoch in range(EPOCHS):

    train_loss = train_epoch(model, train_loader, criterion, optimizer, device)

    val_loss, accuracy = validate(model, val_loader, criterion, device)

    print(f"Epoch {epoch + 1}/{EPOCHS}")
    print(f"Train Loss: {train_loss:.4f}")
    print(f"Val Loss: {val_loss:.4f}")
    print(f"Accuracy: {accuracy:.2%}")
    print()

    if accuracy > best_accuracy:
        best_accuracy = accuracy

        save_model(model, train_dataset.classes, MODEL_PATH)

        print("Best model saved!")
