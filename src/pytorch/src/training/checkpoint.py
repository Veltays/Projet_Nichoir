import torch


def save_model(model, classes, path):
    torch.save({"model_state_dict": model.state_dict(), "classes": classes}, path)
