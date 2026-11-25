const serverStartTime = process.hrtime.bigint();

export function getCurrentDateTime() {
    return new Date().toISOString();
}

export function getUptimeMilliseconds() {
    const currentTime = process.hrtime.bigint();

    const elapsedNanoseconds = currentTime - serverStartTime;
    const elapsedMilliseconds = elapsedNanoseconds / 1_000_000n;

    return Number(elapsedMilliseconds);
}

export function getHighResolutionMilliseconds() {
    const currentNanoseconds = process.hrtime.bigint();
    const currentMilliseconds = currentNanoseconds / 1_000_000n;

    return Number(currentMilliseconds);
}