<?php 
session_start();
?>
<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
	<?php
	include("jeu.php");
	if ($_SESSION['resultat'] == null){
		$array = new Jeu();
		$_SESSION['resultat'] = $array->getRes();
	}
	print_r($_SESSION['resultat']);
	?>
	<form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
		<input type="number" name="premier" min="0" max="9">
		<input type="number" name="deuxieme" min="0" max="9">
		<input type="number" name="troisieme" min="0" max="9">
		<input type="number" name="quadrireme" min="0" max="9">
		<br>
		<input type="submit" name="ok">
		<br>
	</form>

	<?php 
	$_SESSION['reponse'] = array($_POST['premier'], $_POST['deuxieme'], $_POST['troisieme'], $_POST['quadrireme']);

	$x = 0;
	$y = 0;

	for ($i = 0; $i < 4; $i++) {
		for ($j = 0; $j < 4; $j++) {
			if($i == $j and $_SESSION['resultat'][$i] == $_SESSION['reponse'][$j]){
				$x++;
				$j++;
			}
			elseif($_SESSION['resultat'][$i] == $_SESSION['reponse'][$j]) {
				$y++;
			}

			if ($x == 4){
				$_SESSION['resultat'] = null;
				header('Location: mastermind.php');
				echo "<script type='text/javascript'>alert('BIEN JOUE!'')</script>";
				$x = 0;
				$y = 0;
			}
		}
	}

	echo $y." valeur n'est pas bien placé";
	echo "<br>";
	echo $x." valeur est bien placé";
	?>

</body>
</html>
