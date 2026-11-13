# Nichoir connecte - M5Stack Timer-CAM

Ce firmware initialise l'OV3660, surveille le PIR sur GPIO13 et prend une
photo JPEG apres un front montant. GPIO4 commande l'eclairage infrarouge via
un MOSFET. La temporisation est non bloquante et un PIR qui reste a l'etat
haut ne provoque pas de captures en boucle.

La capture est actuellement validee dans le moniteur serie puis son tampon est
libere. Le stockage ou l'envoi du JPEG doit etre ajoute dans `takePhoto()`.

## Cablage

| Element | Timer-CAM |
| --- | --- |
| PIR VCC | 5 V |
| PIR GND | GND |
| PIR OUT | SCL / GPIO13 |
| Gate MOSFET | SDA / GPIO4 via 220 ohms |
| Gate MOSFET | GND via 100 kohms (pull-down) |
| Source MOSFET N | GND |
| Drain MOSFET N | Cathode LED IR |
| Anode LED IR | 5 V via resistance de limitation |

GPIO4 et GPIO13 ne sont utilises ni par l'OV3660 ni par le RTC interne de la
Timer-CAM. GPIO4 n'est pas une broche de strapping de l'ESP32-D0WDQ6-V3. Le
pull-down externe maintient la LED eteinte avant l'initialisation du firmware.

### Verification electrique

- Le SR-602 est souvent annonce avec une sortie voisine de 3,3 V meme lorsqu'il
  est alimente en 5 V, mais les clones varient. Mesurer OUT : il ne doit jamais
  depasser 3,6 V pour l'ESP32. Si la sortie atteint 5 V, ajouter un diviseur ou
  un convertisseur de niveau.
- Pour une LED IR 940 nm typique (Vf de 1,2 a 1,5 V), 220 ohms sous 5 V donne
  environ 16 a 17 mA. Cette valeur ne convient que si la fiche technique de la
  LED autorise ce courant continu. Calculer `R >= (5 V - Vf) / I_LED` et
  verifier la puissance de la resistance.
- Ne jamais brancher une LED directement au 5 V. Chaque LED en parallele doit
  posseder sa propre resistance.
- L'IRLZ44N supporte largement ce faible courant, mais son `RDS(on)` n'est
  garanti qu'a partir de 4 V de gate. A 3,3 V il n'est donc pas ideal, meme
  s'il devrait fonctionner ici. Preferer un petit MOSFET N dont `RDS(on)` est
  specifie a 2,5 V ou 3,3 V.
- Les resistances de gate 220 ohms et pull-down 100 kohms sont acceptables.
  Un pull-down de 10 kohms rendrait l'extinction au demarrage encore plus
  robuste, au prix d'environ 0,33 mA lorsque GPIO4 est haut.
- Toutes les masses doivent etre communes. Verifier que le 5 V et le cable USB
  supportent le courant de la carte, de la camera et de la LED.

## Compilation et televersement

La plateforme est verrouillee sur Espressif32 8.0.0, version utilisee pour la
compilation validee. Cela explique la difference avec les anciens logs en
7.0.0 et evite qu'une mise a jour implicite change l'environnement.

Le port n'est volontairement pas fixe dans `platformio.ini`. PlatformIO doit
detecter le port present au moment du televersement :

```powershell
& "$env:USERPROFILE\.platformio\penv\Scripts\platformio.exe" device list
& "$env:USERPROFILE\.platformio\penv\Scripts\platformio.exe" run
& "$env:USERPROFILE\.platformio\penv\Scripts\platformio.exe" run --target upload
```

Si plusieurs ports existent, utiliser ponctuellement le port observe :

```powershell
& "$env:USERPROFILE\.platformio\penv\Scripts\platformio.exe" run --target upload --upload-port COMx
```

Ne pas recopier `COM5`, `COM7` ou `COMx` sans verification. Si aucun port ne
figure dans le Gestionnaire de peripheriques ou dans `device list` :

1. utiliser un cable USB-C de donnees et essayer un autre port USB, sans hub ;
2. fermer le moniteur serie et toute application qui pourrait garder le port ;
3. installer/reinstaller le pilote FTDI VCP recommande par M5Stack ;
4. debrancher/rebrancher la carte et noter le port qui apparait ;
5. si la synchronisation automatique echoue, lancer l'upload puis appuyer
   brievement sur RESET lorsque `Connecting...` s'affiche. La Timer-CAM n'a
   pas de bouton BOOT utilisateur distinct ; ne pas court-circuiter de broche
   sans suivre le schema de la revision exacte.

`Chip is ESP32-D0WDQ6-V...` signifie que le port est correct et que le ROM
bootloader repond. Une erreur posterieure concerne plutot le mode boot, le
cable/l'alimentation ou l'ecriture de la flash. La vitesse de 115200 bauds est
conservee ici pour privilegier la fiabilite.

## Comportement temporel

- front montant du PIR requis ;
- attente de 300 ms avec l'eclairage IR avant la photo ;
- extinction immediate apres la capture ;
- delai anti-declenchement de 10 s ;
- une nouvelle transition LOW puis HIGH est necessaire apres un signal reste
  haut, meme si le delai est termine.
