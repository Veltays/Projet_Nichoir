// injection du fichier html aside dans le body

function InjectAside() {
    fetch('../assets/fragment/aside.html', ) // because live-server is injection code in file named 
        .then(response => response.text())
        .then(data => {
            console.log(data);
            document.body.insertAdjacentHTML('afterbegin', data);
        })
        .catch(error => console.error(error));
}




function InjectTestData() {

    // recupeer fragment et l'inject dans la liste des oiseaux

    for (let i = 0; i < 1; i++) {
    fetch('../assets/fragment/bird_card.html') 
        .then(response => response.text())
        .then(data => {
            console.log(data);
            const birdList = document.querySelector('.main-section__liste-of-bird');

            if (birdList) {
                birdList.insertAdjacentHTML('beforeend', data);
            }
        })
        .catch(error => console.error('Erreur lors du chargement de la carte :', error));
    }
}

function EnableGalleryWheelScroll() {
    const gallery = document.querySelector('.bird__images-list');

    if (!gallery) {
        return;
    }

    gallery.addEventListener('wheel', event => {
        event.preventDefault();
        gallery.scrollLeft += event.deltaY;
    }, { passive: false });
}

function init(){
    InjectAside();
    InjectTestData();
    EnableGalleryWheelScroll();


}



init();
