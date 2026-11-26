import express from "express";
import apiRouter from "./src/api/index.js";
import { handleError } from "./src/core/errorHandler.js";
import { createLogger } from "./src/core/logger/index.js";
import { requestLogger } from "./src/core/logger/middleware.js";
import { sendError } from "./src/core/response.js";


// express permet de créer un serveur HTTP facilement.
const app = express();
// Le port sur lequel le serveur écoute les requêtes HTTP.
const port = Number(process.env.PORT) || 3000;

// Création d'un logger générique pour le serveur.
const serverLogger = createLogger("SERVER");


initializeMiddleware(app);


app.listen(port, () => {
    serverLogger.success(`Serveur démarré sur http://localhost:${port}`);
});




function initializeMiddleware(app) {
    // Middleware pour parser le corps des requêtes en JSON.
    app.use(express.json());

    // Middleware pour logger les requêtes HTTP.
    app.use(requestLogger);

    // Middleware pour servir les fichiers statiques.
    app.use(express.static("public"));

    // Middleware pour gérer les routes de l'API.
    app.use("/api", apiRouter);

    // Middleware pour gérer les routes introuvables.
    app.use((request, response) => {
        return sendError(response, "Route introuvable", 404);
    });

    // Middleware pour gérer les erreurs.
    app.use(handleError);
}
