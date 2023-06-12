Jeu Vidéo : SpaceRush (Binôme : Maxime Chauveau - Allan Cueff)


	-ATTENTION : le programme nécessite le package qt multimedia (à installer) pour les images !

	-But du jeu :

	Vous allez incarner un vaisseau spatial attaqué par de nombreux ennemis ! Vous pouvez seulement vous déplacer de gauche à droite pour éviter les vaisseaux adverses. Ces vaisseaux pour la moitié vous poursuivrons sur la map, tandis que les autres ont des déplacements aléatoires.Vous êtes obligé de fournir un UserName, qui sera ajouté au leaderBoard à la fin de votre partie. Quand vous mourrez, vous pourrez recommencer la partie ou retourner au menu principal pour y voir le leaderBoard.


	-Déplacements et actions :

	Au début de la partie, vous ne pourrez que vous déplacer vers la gauche (Q) ou la droite (D), ce qui vous rend vulnérable aux ennemis. Sans défense, la moindre collision avec un ennemi vous tuera et la partie sera terminée. Fort heureusement, réussir un niveau garanti de nouveaux bonus utilisables !


	-PowerUps déblocables :

	À chaque téléportation en bas de la map, on débloque des nouveaux niveaux ces niveaux ne sont donc pas accessible au début :
- Le missile : à partir du niveau 2 (de la première téléportation), le vaisseau débloque la capacité de tirer des missiles : en appuyant sur "S", un missile apparaît et fait exploser les vaisseaux ennemis. Toutefois, le temps de recharger, cette arme n'est disponible que toutes les 2 secondes.
- Le bouclier : à partir du niveau 3, le vaisseau débloque un champ de force qui protège le vaisseau allié. Si un ennemi vient à taper ce champ, le vaisseau adverse meurt et le champ est détruit. Si vous voulez le récupérer, vous devez absolument réussir à finir le niveau ! La fin de ce niveau laisse le temps au personnel du vaisseau allié de refabriquer le champ de force.


	-Détails notables :

	La première vague d'ennemis arrive avec 15 ennemis. À chaque vague, les ennemis de la vague précédente sont détruits et des nouveaux sont créés. Chaque vague augmente le nombre n'ennemis. Un fichier qui sera créé dans le cmake-build-debug et stockeras les meilleurs scores, avec la date du jour où ce record est pris. Pour permettre la bonne lecture des fichiers image, un fichier assets.qrc est créé, ce qui permet de pouvoir mettre les images dans un fichier en dehors du cmake-build. Le son a essayé d'être rajouté, mais visiblement la WSL debian ne permet pas facilement l'utilisation de ces fichiers audio.
	

	-Note des développeurs :

	Après avoir bien lu ce ReadMe, vous devriez être en mesure de comprendre les principales fonctionnalités de notre jeu. Nous sommes joignables si besoin par mail pour répondre à certaines précisions. On espère que vous découvrirez et que vous apprécierez le jeu et il ne nous reste plus qu'à vous souhaiter de bonnes parties !


Maxime Chauveau
Allan Cueff
