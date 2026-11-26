from torch import nn
from torchvision.models import mobilenet_v3_small
from torchvision.models import MobileNet_V3_Small_Weights


def create_model(num_classes, pretrained=True):
    model = mobilenet_v3_small(
        weights=MobileNet_V3_Small_Weights.DEFAULT if pretrained else None
    )

    for param in model.parameters():
        param.requires_grad = False

    model.classifier[-1] = nn.Linear(model.classifier[-1].in_features, num_classes)

    return model
