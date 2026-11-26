from torchvision.transforms import Normalize


def normalize_image(tensor):
    return Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])(tensor)
