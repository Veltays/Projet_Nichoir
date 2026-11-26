from torchvision import transforms


def resize_keep_ratio(image):
    transform = transforms.Compose([transforms.Resize(256), transforms.CenterCrop(224)])

    return transform(image)
