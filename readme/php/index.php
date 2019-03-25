<?php
function debutDePage($css,$titre,$band)
  {
  $css = "<link rel='stylesheet' href='$css'><link rel='stylesheet' href='../css/bandeau.css'>";
  echo '<!DOCTYPE HTML>',
		'<html lang="fr">',
			'<head>',
				'<meta charset="UTF-8">',
				'<title>', $titre, '</title>',
				$css,
        '<link rel="shortcut icon" type="image/jpg" href="image/favicon.jpg"/>',
			'</head>', 
      '<body>',
      bandeau($band);
  }
  
function bandeau($page)
  {
  echo
    '<nav id="band">';
      if($page === 'Home')
            {
            echo
            '<a href="index.html" class="band_home"><div id="band_selec"><p>IG</p></div></a>';
            }
          else
            {
            echo
            '<a href="index.html" class="band_home"><div><p>IG</p></div></a>';
            }
            echo
      '<div id="band_lien">',
        '<ul id="band_menu">';
          if($page === 'Nageur')
            {
            echo
            '<li id="band_selec" class="band_depliant" id="pre_dep">Structure du projet';
            }
          else
            {
            echo
            '<li class="band_depliant" id="pre_dep">Structure du projet';
            }
            echo
            '<ul>',
              '<li><a href="#">Diagramme de classe</a></li>',
              '<li><a href="#">Choix d\'impl&eacute;mentations</a></li>',
              '<li><a href="#">Outils utilis&eacute;s</a></li>',
            '</ul>',
          '</li>';
          if($page === 'Groupe')
            {
            echo
            '<li id="band_selec" class="band_depliant">Travaux r&eacute;alis&eacute;s';
            }
          else
            {
            echo
            '<li class="band_depliant">Travaux r&eacute;alis&eacute;s';
            }
            echo
            '<ul>',
              '<li><a href="#">R&eacute;partition du travail</a></li>',
              '<li><a href="#">...</a></li>',
            '</ul>',
          '</li>';
          if($page === 'Seance')
            {
            echo
            '<li id="band_selec" class="band_depliant">Fonctionnement';
            }
          else
            {
            echo
            '<li class="band_depliant">Fonctionnement';
            }
            echo
            '<ul>',
              '<li><a href="#">Commandes</a></li>',
              '<li><a href="#">Physique de la voiture</a></li>',
            '</ul>',
          '</li>';
          if($page === 'Divers')
            {
            echo
            '<li id="band_selec" class="band_depliant"  id="der_dep">...';
            }
          else
            {
            echo
            '<li class="band_depliant"  id="der_dep">...';
            }
            echo
            '<ul>',
              '<li><a href="#">...</a></li>',
            '</ul>',
          '</li>',
        '</ul>',
      '</div>',
    '</nav>';
  }
  
function finDePage()
  {
  $res = '</body></html>';
  echo $res;
  }
  

debutDePage('../css/style.css','Projet IG','Home');

finDePage();
?>