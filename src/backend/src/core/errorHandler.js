import { createLogger } from "./logger/index.js";
import { sendError } from "./response.js";

const errorLogger = createLogger("API");

// Express nécessite quatre paramètres pour identifier un middleware d'erreur.
export function handleError(error, request, response, next) {
    const statusCode = error.statusCode || error.status || 500;
    const message = error.message || "Erreur interne du serveur";

    errorLogger.error(message, {
        method: request.method,
        path: request.originalUrl,
        stack: error.stack
    });

    return sendError(response, message, statusCode, error.stack);
}