from torchvision.transforms import ToTensor


def image_to_tensor(image):
    return ToTensor()(image)
