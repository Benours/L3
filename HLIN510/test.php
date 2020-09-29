<?php
    // Active tout les warning. Utile en phase de développement
    // En phase de production, remplacer E_ALL par 0
    error_reporting(E_ALL);
    
    // Inclus le fichier contenant les fonctions personnalisées
    include_once 'mes_fonctions.php';
    
    // Fonction de connexion à la base de données
    connexion_DB('BASE_TEST');
    
    // Définit l'Id de la page d'accueil (1 dans cet exemple)
    // Pensez à le modifier si ce n'est pas le cas chez vous.
    $id_page_accueil = 1;
    
    // Récupère l'id de la page courante passée par l'URL
    // Si non défini, on considère que la page est la page d'accueil
    if (isset($_GET['id_page'])) {
        $_ENV['id_page'] = intval($_GET['id_page']);
    } else {
        $_ENV['id_page'] = $id_page_accueil;
    }
    
    // Extrait les informations correspondantes à la page en cours de la DB
    extraction_infos_DB();
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<!-- Insère les mots-clés extraits de la DB dans les meta -->
<META NAME="keywords" lang="fr" CONTENT="<?php echo $_ENV['mots_cles']; ?>">
<!-- Insère la description extraite de la DB dans les meta -->
<META NAME="Description" CONTENT="<?php echo $_ENV['description']; ?>">
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1">
<!-- Insère le titre extrait de la DB dans la balise correspondante -->
<title><?php echo $_ENV['titre']; ?></title>
<link rel="stylesheet" type="text/css" href="styles.css">
</head>
<body>
    <div id="menu_horizontal">
        <?php
            // Affiche le menu 'racine' => id de la page = id de la page d'accueil = 1
            echo affiche_menu($id_page_accueil);
        ?>
    </div>
    <div id="chemin_fer">
        <?php
            // Affiche le chemin de fer
            echo 'Vous ètes ici : '.affiche_chemin_fer($_ENV['id_page']);
        ?>
    </div>
    <div id="bloc_central">
        <div id="menu_vertical">
            <?php
                // Affiche le menu en cours => id de la page = id de la page en cours.
                echo affiche_menu($_ENV['id_page']);
            ?>
        </div>
        <div id="contenu">
            <?php
                // Affiche le contenu de la page en cours
                echo $_ENV['contenu'];
            ?>
        </div>
    </div>
    <div id="pied_page">
        <?php include("pied_page.html"); ?>
    </div>
    <?php deconnexion_DB(); ?>
</body>
</html>