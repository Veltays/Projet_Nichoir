from .pipeline.load import load_image
from .pipeline.resize import resize_keep_ratio
from .pipeline.augmentation import augment_image
from .pipeline.to_tensor import image_to_tensor
from .pipeline.normalize import normalize_image


def preprocess(image, training=False):
    image = resize_keep_ratio(image)

    if training:
        image = augment_image(image)

    tensor = image_to_tensor(image)
    tensor = normalize_image(tensor)

    return tensor


def preprocess_image(path, training=False):
    return preprocess(load_image(path), training)
