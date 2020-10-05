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

	<form method="post" action="bonjour.php">
		<input type="text" name="nom" placeholder="NOM" pattern="[A-Z]*" required>
		<input type="text" name="prenom" placeholder="Prenom" pattern="[A-Z][a-z].*" required>
		<textarea name="message" rows="8" cols="44" placeholder="Ton message ici."></textarea><br>
		<input type="submit" name="ok">		
	</form>

	<?php include("piedpage.php"); ?>

</body>
</html>