export function sendSuccess(response, data = null, message = "OK", statusCode = 200) {
    return response.status(statusCode).json({
        success: true,
        message,
        data
    });
}

export function sendError(response, message = "Une erreur est survenue", statusCode = 500, details) {
    return response.status(statusCode).json({
        success: false,
        message,
        details
    });
}
