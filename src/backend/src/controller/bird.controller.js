import { getAllBirds } from "../services/bird.service.js";
import { sendSuccess } from "../core/response.js";

export async function listBirds(request, response, next) {
    try {
        const birds = await getAllBirds();

        return sendSuccess(response, birds, "Liste des oiseaux récupérée");
    } catch (error) {
        return next(error);
    }
}
