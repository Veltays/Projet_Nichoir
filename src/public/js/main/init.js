// injection du fichier html aside dans le body

function InjectAside() {
    fetch('../assets/fragment/aside.html', { cache: 'no-store' }) // because live-server is injection code in file named 
        .then(response => response.text())
        .then(data => {
            console.log(data);
            document.body.insertAdjacentHTML('afterbegin', data);
        })
        .catch(error => console.error(error));
}



function init(){
    InjectAside();


}



init();