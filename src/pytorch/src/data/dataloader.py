from torch.utils.data import DataLoader
from core.config import BATCH_SIZE


def create_dataloader(dataset, batch_size=BATCH_SIZE, shuffle=False):
    return DataLoader(dataset, batch_size=batch_size, shuffle=shuffle)
