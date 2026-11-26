import sys
import json
import torch

from core.config import MODEL_PATH
from modeling.model import create_model
from preprocessing.main import preprocess_image

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")


def predict(image_path):
    checkpoint = torch.load(MODEL_PATH, map_location=device, weights_only=True)

    classes = checkpoint["classes"]

    model = create_model(len(classes), pretrained=False)
    model.load_state_dict(checkpoint["model_state_dict"])
    model.to(device)
    model.eval()

    image = preprocess_image(image_path)
    image = image.unsqueeze(0).to(device)

    with torch.inference_mode():
        outputs = model(image)
        probabilities = torch.softmax(outputs, dim=1)

    confidence, index = probabilities.max(dim=1)

    return {"species": classes[index.item()], "confidence": round(confidence.item(), 4)}


if __name__ == "__main__":
    result = predict(sys.argv[1])
    print(json.dumps(result))
