<!DOCTYPE html>
<html>
<head>
    <title></title>
</head>
<body>
    <?php
    $larticle=array('marteau'=>10, 'tenaille'=>5, 'vis'=>5.2, 'clou'=>5.8,'tournevis'=>7, 'ciseau'=>4, 'toile_emeri'=>3);

    if (isset($_GET['commandes'])) $commandes = unserialize($_GET['commandes']);
    else $commandes=array('marteau'=>0, 'tenaille'=>0, 'vis'=>0, 'clou'=>0,'tournevis'=>0, 'ciseau'=>0, 'toile_émeri'=>0);

    if (isset($_GET['article'])) {
        $commandes[$_GET['article']] += $_GET['valeur'];
    }
    $prix = 0;
    foreach ($commandes as $key => $value) {
        if($value > 0){
            echo $value, " ", $key, " : ", $larticle[$key], "€ fait ", $larticle[$key] * $value, "<br>";
            $prix += $larticle[$key] * $value;
        }
    };

    echo "<br> le prix est de ".$prix;

    if(isset($_GET['reset'])) $comSerie=array('marteau'=>0, 'tenaille'=>0, 'vis'=>0, 'clou'=>0,'tournevis'=>0, 'ciseau'=>0, 'toile_émeri'=>0); 
    $comSerie = serialize($commandes);
    
    ?>

    <form method="get" action='<?php echo $_SERVER['PHP_SELF']; ?>'>
        <select size="1" name="article">
            <option value="marteau">marteau</option>
            <option value="tenaille">tenaille</option>
            <option value="vis">vis</option>
            <option value="clou">clou</option>
            <option value="tournevis">tournevis</option>
            <option value="ciseau">ciseau</option>
            <option value="toile_emeri">toile_emeri</option>
        </select>
        <input type="number" size="10" min="0" name="valeur" value="0">
        <?php echo "<input type='hidden' name='commandes' value='".$comSerie."'/>"; ?>

        <input type="submit" name="ok" value="Ajouter">
    </form>
    <form>
        <input type="submit" name="reset" value="Reset">
    </form>

</body>
</html>