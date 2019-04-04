<?php  
include("bibli.php");

debutDePage('../css/style.css','Projet IG','Home');

echo  
      '<h1>Informatique Graphique</h1>','<div id="main">',
      '<p>Dans le carde du cours d\'Infographie 2018/2019 UFR-ST, nous avons eut l\'opportunit&eacute; de d&eacute;velopper un programme graphique en openGL/C++, complet&eacute; par les librairies glut et glu.</p>',
      '<p>L\'alternative quant au choix du sujet, &eacute;tait la suivante :</p>', 
      '<ul><li>D&eacute;veloppement d\'un grand-huit en 3D',
      '<li>D&eacute;veloppement d\'une course sur circuit</ul>',

      '<p>Pour ce projet, r&eacute;alis&eacute; en bin&ocirc;me, nous avons opt&eacute; pour La course sur circuit car le sujet est un grand classique des programmes graphiques, et que l\'aspect de gestion des contr&ocirc;les clavier est tr&agrave;s interessante &agrave; comprendre, puis a d&eacute;velopper (m&eacute;canique, vectoriel de deplacement :vitesse/acceleration/direction).</p>',

      '<p>Le sujet a &eacute;t&eacute; d&eacute;finit en ces termes :</p>', 

      '<p>La mod&eacute;lisation doit &ecirc;tre effectu&eacute;e en 3D, mais le circuit est plan. Un circuit ferm&eacute; est d&eacute;fini avec lignes droites et virages repr&eacute;sentant un parcours d&eacute;limit&eacute; par des bords. Un mobile se d&eacute;place sur ce circuit &agrave; partir d\'une ligne de d&eacute;part. Il subit le contr&ocirc;le de l\'utilisateur du programme qui peut acc&eacute;l&eacute;rer, ralentir et changer de direction mais ne peut pas sortir du circuit. Des &eacute;l&eacute;ments de d&eacute;cor devront &ecirc;tre ajout&eacute;s en dehors du circuit lui-m&ecirc;me faute de quoi l\'interpr&eacute;tation des distances risque d\'&ecirc;tre difficile.</p>',

      '<p>Suggestions :</p><ul>',
      '<li>- Un probl&egrave;me complexe consiste &agrave; interdire au mobile de sortir du circuit. On aura tout int&eacute;r&ecirc;t &agrave; se mettre en situation de g&eacute;rer l\'aspect math&eacute;matique de ce probl&egrave;me de fa&ccedil;on aussi simple que possible. Pour ce faire, les bords du circuit pourront &ecirc;tre mod&eacute;lis&eacute;s en utilisant des fonctions math&eacute;matiques simples : droites, arcs de cercle, ...',
      '<li>- Il est possible de construire le circuit en assemblant des morceaux &eacute;l&eacute;mentaires "simples" : morceaux de ligne droite, virages &agrave; 45 ou 90 degr&eacute;s, ...</ul>',

      '<p>A partir de ces instructions concises, nous avions carte blanche afin de d&eacute;velopper le programme comme il nous plaisait de le faire.</p>',

      '<p>Vous trouverez ainsi dans ce site web, un compte rendu du travail effectu&eacute; durant la dur&eacute;e de ce projet, choix de dev, organisation etc.</p>',

      '<p>Bonne lecture &agrave; vous</p>',
      '<p id="signature">Gauthier Ferre, R&eacute;mi Kouidria</p>',
      '</div>';

finDePage();
?>