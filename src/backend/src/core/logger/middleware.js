import { createLogger } from "./index.js";
import { getHighResolutionMilliseconds } from "./time.js";

const httpLogger = createLogger("HTTP");

export function requestLogger(request, response, next) {
    const startTime = getHighResolutionMilliseconds();

    response.on("finish", () => {
        const durationMilliseconds = getHighResolutionMilliseconds() - startTime;

        httpLogger.info(
            `${request.method} ${request.originalUrl} - ${response.statusCode} - ${durationMilliseconds.toFixed(1)}ms`
        );
    });

    next();
}
