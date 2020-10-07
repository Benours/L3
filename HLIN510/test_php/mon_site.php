<?php 
session_start();
?>
<!DOCTYPE html>
<html lang="fr">
<meta charset="utf-8">
<head>
	<title></title>
</head>
<body>
	<?php include("css.php"); ?>
	<?php include("entete.php"); ?>

	<div>
		<h2>Mon super site!</h2>
		<p>contenu du site blablabla</p>
	</div>

	<?php if (!isset($_POST['mdp']) or $_POST['mdp'] != "azerty")
	{
		?>

		<form method="post" action='mon_site.php'>
			<input type='text' name='nom' placeholder='NOM' pattern='[A-Z]*' required>
			<input type='text' name='prenom' placeholder='Prenom' pattern='[A-Z][a-z].*' required>
			<br>
			<input type='password' name='mdp' required>
			<br>
			<input type='submit' name='ok'>
		</form>
		<?php

		
	}
	else {
		$_SESSION['nom'] = $_POST['nom'];
		$_SESSION['prenom'] = $_POST['prenom'];
		?>

		<div>
			<p>Bonjour <?php echo $_SESSION['prenom'].' '.$_SESSION['nom']; ?> !</p>
		</div>

		<?php
	}
	include("piedpage.php"); ?>

</body>
</html>