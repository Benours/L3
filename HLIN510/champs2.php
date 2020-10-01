<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
	<?php
    $larticle=array('marteau'=>10, 'tenaille'=>5, 'vis'=>5.2, 'clou'=>5.8,'tournevis'=>7, 'ciseau'=>4, 'toile_emeri'=>3);
    if (isset($_GET['commandes']))
    	$commandes = unserialize($_GET['commandes']);
    else 
    	$commandes=array('marteau'=>0, 'tenaille'=>0, 'vis'=>0, 'clou'=>0,'tournevis'=>0, 'ciseau'=>0, 'toile_émeri'=>0);
    echo "Derniere commande :<br><ul>";
    $totaux = 0;
    foreach ($_GET as $art => $qu) {
    	if ($art != 'commandes' && $qu > 0)
    		echo "<li> $art : $qu </li>";
    		$totaux += $qu * $larticle[$art];
    }
    echo "</ul>";
    echo "Le prix total est de : ".$totaux."€";

    echo "</br><form> Nouvelle commandes :";
    echo "<table>";
    foreach ($larticle as $nom => $prix) {
    	echo "<tr><td>".$nom." (".$prix."€) </td><td> <input type='number' size='2' name='$nom'></td></tr>";
    }
    echo "</table></br>";
    $comSerialisees = serialize($commandes);
    echo "<input type='hidden' name='commandes' value='".$comSerialisees."'/>";
    echo "<input type='submit' value='Validez la commande'/>";
    echo "</form>";
    ?>

</body>
</html>