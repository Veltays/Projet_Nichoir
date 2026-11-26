def train_step(model, images, labels, criterion, optimizer):
    optimizer.zero_grad()

    outputs = model(images)
    loss = criterion(outputs, labels)

    loss.backward()
    optimizer.step()

    return loss.item()


def train_epoch(model, dataloader, criterion, optimizer, device):
    model.eval()
    model.classifier.train()

    total_loss = 0

    for images, labels in dataloader:
        images = images.to(device)
        labels = labels.to(device)

        loss = train_step(model, images, labels, criterion, optimizer)

        total_loss += loss * images.size(0)

    return total_loss / len(dataloader.dataset)
