# Arduino_Solar_Tracker
Arduino code for bi-axis solar tracker, open loop, closed loop, manual mode + hybrid
V.	Modélisation d’un « tracker » bi-axial
1.	Introduction 

Dans ce chapitre sera décrit le principe de fonctionnement et de conception de la maquette utilisée pour décrire les « trackers » solaire, on y retrouve une description du matériel utilisé pour le montage du mini-tracker, à citer le module principale comportant le microcontrôleur programmable, ainsi que les composantes qui commande et actionnent les moteurs, et l’IDE utilisé. 
Le modèle électronique proposé ici est une maquette miniature de ce que serait un « tracker » solaire actif.

2.	Principe de fonctionnement [12]

La maquette proposée est un modèle électronique, dont le but est de modéliser le fonctionnement des « trackers » solaire actifs, selon les différents codes Arduino compilés :
●	le modèle fera office de tracker, et ce en orientant le vérin d’élévation à un angle fixe et par activation du « SlideSwitch » les capteurs LDR auront pour consigne de suivre la lumière automatiquement lorsque ces derniers seront excités, ainsi l’angle de suivi (l’azimut) se fera en commande fermé par régulation. On parle ici de tracker mono-axial.
●	En compilant le code permettant le passage en suivi bi-axial, on aura le choix entre un suivi par commande en boucle ouverte (par calcul astronomique de la position du soleil), ou par commande en boucle fermée, et les capteurs LDR prendront le relai afin de suivre en temps réel la position du soleil (soleil ici modélisé par une lampe torche ou toute autre excitation lumineuse)
●	A noter qu’il est possible de Contrôler le « tracker » manuellement en « switchant » le slideswitch  en mode off, le control se fera dans ce cas par le biais du joystick.

3.	Description de l’Arduino et du matériel utilisé

●	La carte Arduino :

Une carte Arduino (Figure V.1) est une petite (5,33 x 6,85 cm) carte électronique équipée d'un microcontrôleur ATmega328P (Figure V.2) qui représente la partie programmable du module.

![image](https://user-images.githubusercontent.com/42687107/140045377-80a30bef-4b85-4b3e-a73b-c06ee7c1101b.png)

Figure V. 1 Carte Arduino Uno

![image](https://user-images.githubusercontent.com/42687107/140045404-b2515b84-ea75-47fc-8483-561e6b0c7022.png)
 
Figure V. 2 Microcontrôleur ATmega328P 

Le microcontrôleur permet, à partir d'évènements détectés par des capteurs, de programmer et commander des actionneurs ; la carte Arduino est donc une interface programmable.

●	Caractéristiques techniques de la carte Arduino Uno :

![image](https://user-images.githubusercontent.com/42687107/140045472-89113fe5-b9f7-4528-a892-05bd52f0d129.png)

Tableau V. 1 Caractéristiques techniques de la carte Arduino Uno
●	Différents usages de la carte : [14]

Les possibilités d'utilisation sont infinies : SI on peut détecter un ou plusieurs évènements (variation de température, mouvement, présence, distance …) ET en fonction de ces évènements, agir sur le monde réel à l'aide d'actionneurs (résistances chauffantes, moteurs ...), ALORS on peut tout faire : bras de robot, régulation de température, effets lumineux, instruments de musique, systèmes d'alarmes (Figure V.3).
De nombreuses cartes additionnelles (≪ shields ≫) ont été créées afin d'enrichir les applications potentielles, les seules limites sont notre imagination, le temps, et le budget (quelques dizaines d'euros (milliers de dinars) suffisent au départ pour s'équiper).

![image](https://user-images.githubusercontent.com/42687107/140045507-a089103c-8348-4cc5-8d11-3d91ff82f2f4.png)
 
Figure V. 3 Quelques projets réalisés à partir de la carte Arduino uno


●	Circuit interne et composants de la carte : [13]

La carte Arduino Uno se compose d’éléments électroniques variés (Figure VI.4), comprenant deux prises d’alimentation, d’un microcontrôleur, de PINS digitales et analogiques, de boutons et autres composants…

![image](https://user-images.githubusercontent.com/42687107/140045553-5bcc632c-86de-488d-8baf-b883e5dc13eb.png)
 
Figure V. 4 schémas des composants de la carte Arduino Uno

●	Connection électrique de la carte :

Une plaque d'essai communément appelée BreadBoard permet de réaliser des montages électroniques sans soudure. La plaque d'essai s'utilise avec des ≪ straps ≫ qui sont des fils de cuivre isolés, de longueur et couleur variables (Figure V.5). Plusieurs modèles existent.

![image](https://user-images.githubusercontent.com/42687107/140045634-d39653e8-cc6d-4c68-bf2d-d94a1b3e0469.png)
 
Figure V. 5 BreadBoard et "straps" utilisés lors de la connexion électrique de l'Arduino
La plaque d'essai comporte des connexions cachées, chaque bande de cuivre met en contact 5 trous. Les trous sont espacés exactement de 2,54 mm (un dixième de pouce).

●	Programmation de la carte :

L’IDE (Integrated Development Environment ou en français, environnement de développement intégré). L’IDE Arduino est une interface graphique simple d’utilisation qui regroupe tous les outils qui permettent de programmer pour l’Arduino. L’IDE Arduino est un logiciel open source (Libre d’accès et gratuit).

Une fois installé sur l’ordinateur, L’IDE Arduino se présente sous forme d’interface graphique permettant de sélectionner une multitude de produits (cartes programmables Arduino), une fois le type de carte sélectionner dans la barre d’outils (Arduino Uno dans notre cas) l’interface nous dirige vers un environnement de développement propre à notre carte (Figure V.6).

L’environnement se décompose en trois parties :

a.	Partie compilation et vérification du code du projet. 

b.	Partie de codage : 
Ou en déclare nos entrées/sorties (PINS), ainsi que la fonction « Setup() » où sont déclarées les types d'entrées voulues et la partie « Loop() » où le code interagit et se répète selon les évènements et les instructions.

c.	Partie de « débogage» afin de déceler toute anomalie/erreur dans le code

![image](https://user-images.githubusercontent.com/42687107/140045690-90f85acb-fb98-4c2b-bc6f-03227f21506b.png)
 
Figure V. 6 Composants de l’Interface de développement Arduino (IDE) en phase de codage

4.	Circuit du « tracker » 
Pour la réalisation de la maquette du « tracker » solaire ont étés utilisés différents module électroniques (Tableau V.2), dans le circuit montré ci-dessous (Figure V.7) :

![image](https://user-images.githubusercontent.com/42687107/140045745-5a90bf30-2ecb-4def-9f06-e52921989b47.png)
 
Figure V. 7 Circuit électrique de la maquette 

Reference composant	Image du composant	Nombre de composants utilisés
Carte Arduino Uno	 

![image](https://user-images.githubusercontent.com/42687107/140046107-f5596d5f-4dd9-448b-9154-90cca3dc5193.png)

Tableau V. 2 Composants utilisés dans la maquette
Ainsi que les fils (straps) nécessaires au branchement, et les boitiers et autres outils de soudure et de colle.

5.	Programmation de l’Arduino et implémentation du code de suivi du soleil

Afin de modéliser les différent types de « trackers » solaire actifs, ont étés développées différent codes pour commander la maquette, les codes ont le même principe de fonctionnement, câd on procède en trois étapes : 

●	Déclaration des Entrées/Sorties au niveau des pins analogiques et digitales et autres constantes et variables ainsi que les fonctions si nécessaires.
●	Puis dans la fonction setup() on introduit les type INPUT/OUTPUT afin que le code s’exécute une fois et mette en mémoire nos Entrées/Sorties.
●	Enfin la fonction loop() qui se répète comme son nom l’indique, tant que les événements occupants sont compris dans le code. 

On retrouve :

⮚	Code « tracker » mono-axial en boucle fermée :

Mode commande en boucle fermée (auto) :
Le code a pour principe de fixer le moteur d’élévation à un angle précis, selon l’hémisphère dans lequel on se trouve, une fois fixé le mouvement des moteurs se fait sur l’axe de l’azimut, et est régi par les variations lumineuses captées par les capteurs LDRs.
On y retrouve toutes les composantes électroniques, le basculement du mode manuel vers le mode commande en boucle fermée (auto) se fait via l’activation du slideswitch vers on, déclenchant le courant ver une LED indiquant le mode, ainsi après activation en mode auto les données d’excitations des capteurs PhotoSensible LDRs sont récoltés en temps réel, la moyenne des fréquences d’excitation des LDRs du côté gauche du panneau est comparée à la moyenne du côté droit, et la différence est transformé en signaux vers le pont H Bridge L298n qui traduit ces signaux vers le moteur provoquant son mouvement dans le sens où l'intensité lumineuse est la plus élevé. Et le principe se répète à chaque variation lumineuse.

Mode manuel commande par joystick :
Lorsque le slideswitch est off, la lampe LED n’est plus alimentée en courant et s’éteint, ce qui indique le basculement vers le mode manuel, dont le principe est de traiter les signaux émis par le joystick , dont la position de départ est initiée par une valeur médiane (512), la moitié de la plage maximale du modèle (0 à 1023), ainsi lors de la manipulation du joystick  un signal électrique est envoyé, portant la valeur à laquel se trouve la position du joystick  et sa direction, le signal est renvoyé au pont moteur qui les traduit en mouvement du moteur de le sens voulu.

On retrouve le code décomposé de la maquette du « tracker » mono-axial à commande en boucle fermée (Code V.1) :

![image](https://user-images.githubusercontent.com/42687107/140046140-92595860-7442-4ac0-8e0c-c5fddb46f3ae.png)
 
Code V. 1 Mosaïque du code du "tracker" mono-axial à commande en boucle fermée

⮚	Code « tracker » bi-axial en boucle fermée :

Mode commande en boucle fermée (auto) :
Dans ce mode, le code a pour principe de suivre le soleil sur les deux axes (Hauteur et Azimut), sur le même principe le mouvement du panneau est régi par les variations lumineuses captées par les capteurs LDRs.
Le basculement du mode manuel vers le mode commande en boucle fermée (auto) se fait comme par le biais de la slideswitch et l’indication du mode en cours se fait par la LED, les capteurs œuvrent de la même façon que sur le « tracker » mono-axial pour faire fonctionner le moteur sur l’angle azimutal, la différence est qu’on calcul de la même façon la différence des moyennes d’excitation des LDRs sur l’axe d’élévation, càd que la moyenne des LDRs se trouvant au top est comparée à la moyenne des LDRs se trouvant en bas, et la différence est transformé en signaux vers le pont H Bridge L298n qui traduit ces signaux vers le moteur provoquant son mouvement dans le sens où l'intensité lumineuse est la plus élevé. Et le principe se répète à chaque variation lumineuse.

Mode manuel commande par joystick :
Dans ce mode on retrouve le même principe appliqué au « tracker » mono-axial, et on rajoute l’interception du mouvement du joystick   dans le sens de l’élévation, et les signaux reçus seront traiter et envoyer aux moteurs selon la direction que l’on veut donner au panneau.
On retrouve le code décomposé de la maquette du « tracker » bi-axial à commande en boucle fermée (Code V.2) :

![image](https://user-images.githubusercontent.com/42687107/140046208-6158af7c-f0b9-4a95-a3d1-71db8489195b.png)
 
Code V. 2 Mosaïque du code du "tracker" bi-axial à commande en boucle fermée


⮚	Code « tracker » bi axial en boucle ouverte:

Dans le code du « tracker » bi-axial en boucle ouverte, le principe est le même que sur le code précédent (bi-axial à commande en boucle fermée manuel) à la différence qu’on ajoute une option de suivi de la position du soleil, calculée au préalable via les code développés en C (chapitre III) (Code V.3).

Sachant que la vitesse de rotation du panneau est égale à 0.000694 tr/min, nos moteurs ont une vitesse de rotation de 32 tr/min, ce qui implique :
Le rapport de réduction de notre maquette est égal à R = 32/0.000694 = 46109.510.

Afin de simuler les conditions réels de la course du soleil le long de la durée d’ensoleillement, et pour des raisons démonstratifs on « accélère le temps » en supposant dans le code que 1h équivaut à 1 seconde, il faudrait que chaque :
Au niveau de l’actionneur azimutal chaque 1h 🡺 0.0416 tour, ce qui équivaut à 1 impulsion qui dure 78ms chaque heure afin de couvrir l’intégralité de la course du soleil le temps de l’insolation. Une fois les 12 heures de suivi terminées, on inverse le sens de rotation du panneau avec une impulsion qui dure 937.5ms afin de faire un demi-tour et remettre le panneau en position initiale pour une nouvelle journée de suivi (sachant qu’un tour complet du panneau avec nos moteur durerait 1.875s).
Au niveau de l’actionneur élévation, la hauteur maximale moyenne en été est de 76° en partant de 0° au lever/coucher, ainsi chaque  1h🡺0.035 tour, ce qui équivaut à une impulsion de 60.9ms chaque heure jusqu’à la sixième heure et demi, ensuite on inverse les sens de rotation au niveau de l’actionneur et on garde la même impulsion pour les heures de la journée qui reste.

![image](https://user-images.githubusercontent.com/42687107/140046239-f580a956-ac98-4c01-b406-fcba6452763e.png)
 
Code V. 3 Mosaïque du code du "tracker" bi-axial à commande en boucle ouverte

6.	Montage de la maquette électronique

![image](https://user-images.githubusercontent.com/42687107/140046267-e8371b5b-a87c-42da-984c-835adc75ee67.png)

Figure V. 8 Maquette du projet 

![image](https://user-images.githubusercontent.com/42687107/140046290-bbe5ed44-8e75-4b3a-8cd8-4eb1f1340637.png)

Figure V. 9 Circuit électrique de la maquette 
Conclusion générale
Dans ce projet une étude théorique a été présenté dans le but de mettre en évidence l’aspect théorique du gisement solaire, comment le définir dans son ensemble, et quels sont les paramètres qui régissent et décrivent le mouvement apparent du soleil par rapport à la terre dans un premier temps, puis les calculs des coordonnées et positionnement, ainsi qu’une approche énergétique a été faite pour décrire le rayonnement solaire et son apport énergétique à une surface terrestre, à travers des calcul d’orientation de panneaux à fin de tirer profit au maximum de cette énergie, ensuite une brève description de l’outillage nécessaire à l’exploitation du rayonnement solaire que sont les panneaux photovoltaïques, dans le principe de fonctionnement d’une cellule, ainsi que les différents types de cellule et leurs performances.
Une fois l’aspect théorique traité, une description du suivi réel du soleil a été faite à travers les différents types de « trackers » solaires, le mode de fonctionnement et types de commandes intégrées, leurs aspects mécaniques et la comparaison entres les performances de ces derniers en termes de rendements, en concluant par le meilleur « trackers » solaire.
Dans la deuxième partie du projet, le code informatique permettant le calcul des ephémérides solaires a été développé et intégré à une maquette électronique, afin de décrire et illustrer le fonctionnement des « trackers », et enfin un programme en interface utilisateur a été développé et décrit afin de renforcer le traitement numérique et graphiques des données et coordonnées solaires.
Ce projet fut un réel plaisir à accomplir, il a permis de comprendre un peu plus les secrets du soleil, d'approfondir les connaissances et le désir de fusionner les différents domaine et technique appliqués et applicable aux énergie renouvelables, afin d’aller un peu plus vers une transition énergétique propre et durable, ne serait-ce qu’en théorie. 
