import { ansi } from "./color.js";
import { getCurrentDateTime, getUptimeMilliseconds } from "./time.js";

const levelColors = {
    DEBUG: ansi.gray,
    INFO: ansi.blue,
    WARN: ansi.yellow,
    ERROR: ansi.red,
    SUCCESS: ansi.green
};

function formatDuration(milliseconds) {
    if (milliseconds < 1000) {
        return `${milliseconds}ms`;
    }

    const seconds = milliseconds / 1000;

    return `${seconds.toFixed(2)}s`;
}

function formatMetadata(metadata) {
    if (!metadata || typeof metadata !== "object") {
        return "";
    }

    const validMetadata = {};

    for (const [key, value] of Object.entries(metadata)) {
        if (value !== undefined) {
            validMetadata[key] = value;
        }
    }

    if (Object.keys(validMetadata).length === 0) {
        return "";
    }

    return ` ${ansi.dim}${JSON.stringify(validMetadata)}${ansi.reset}`;
}

function writeLog(level, category, message, metadata) {
    const color = levelColors[level] || levelColors.INFO;
    const currentTime = getCurrentDateTime();
    const uptime = formatDuration(getUptimeMilliseconds());
    const categoryName = String(category || "APP").toUpperCase();
    const formattedMetadata = formatMetadata(metadata);

    const logMessage =
        `${color}[${level}]${ansi.reset} ` +
        `${ansi.cyan}[${categoryName}]${ansi.reset} ` +
        `${ansi.dim}[${currentTime}] +${uptime}${ansi.reset} ` +
        `${message}${formattedMetadata}`;

    if (level === "ERROR") {
        console.error(logMessage);
    } else if (level === "WARN") {
        console.warn(logMessage);
    } else {
        console.log(logMessage);
    }
}

export function createLogger(category) {
    return {
        debug: (message, metadata) => writeLog("DEBUG", category, message, metadata),
        info: (message, metadata) => writeLog("INFO", category, message, metadata),
        warn: (message, metadata) => writeLog("WARN", category, message, metadata),
        error: (message, metadata) => writeLog("ERROR", category, message, metadata),
        success: (message, metadata) => writeLog("SUCCESS", category, message, metadata)
    };
}

export const log = createLogger("APP");
