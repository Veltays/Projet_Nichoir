from functools import partial
from torchvision.datasets import ImageFolder
from preprocessing.main import preprocess
from .species import SELECTED_SPECIES


class BirdDataset(ImageFolder):

    def find_classes(self, directory):
        classes, _ = super().find_classes(directory)

        classes = [name for name in classes if name in SELECTED_SPECIES]

        class_to_idx = {name: index for index, name in enumerate(classes)}

        return classes, class_to_idx


def load_dataset(path, training=False):
    return BirdDataset(path, transform=partial(preprocess, training=training))
