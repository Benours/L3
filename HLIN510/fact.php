<!DOCTYPE html>
<html>
<head>
    <title></title>
</head>
<body>

    <form name="F" method="get" action='<?php echo $_SERVER['PHP_SELF']; ?>'>
        <input type="number" name="valeur">
        <input type="submit" name="ok" value="Calculer">
    </form>

    <?php
    function fact($nbr) 
    { 
       if($nbr === 0) // condition d'arret 
       return 1;  
       else 
        return $nbr*fact($nbr-1); 
} 
if (isset($_GET['ok'])){
    echo "Resultat: ", $_GET['valeur'], "! = ", fact($_GET['valeur']);
}
?>
</body>
</html>