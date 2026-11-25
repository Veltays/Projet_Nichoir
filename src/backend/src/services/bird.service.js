// data d'exemple pour simuler une base de données en mémoire.
const birds = [
    { id: 1, name: "Sparrow" },
    { id: 2, name: "Robin" },
    { id: 3, name: "Blue Jay" }
];

export function getAllBirds() {
    // Retourne une copie pour empêcher une route de modifier la source en mémoire.
    return [...birds];
}
