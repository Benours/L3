<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
	<?php include("css.php");
	include("entete.php"); ?>
	<div>
		<p>Bonjour <?php echo $_POST['prenom'].' '.$_POST['nom']; ?> !</p>
		<p>Voici ton message :</p>
		<p><?php echo ' "'.htmlspecialchars($_POST['message']).'" '; ?></p>
	</div>

	<?php include("piedpage.php"); ?>
</body>
</html>