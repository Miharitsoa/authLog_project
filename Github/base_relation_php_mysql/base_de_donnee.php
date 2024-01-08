<?php
try
{
// On se connecte à MySQL
$bdd = new PDO('mysql:host=localhost;dbname=test', 'phpmyadmin','12345678');
}
catch(Exception $e)
{
// En cas d'erreur, on affiche un message et on arrête tout
die('Erreur : '.$e->getMessage());
}
// Si tout va bien, on peut continuer
// On récupère tout le contenu de la table jeux_video
/*$reponse = $bdd->query('SELECT * FROM jeu_video');
// On affiche chaque entrée une à une
while ($donnees = $reponse->fetch())
{
?>
<p>
<strong>Jeu</strong> : <?php echo $donnees['nom']; ?><br />
Le possesseur de ce jeu est : <?php echo $donnees['possesseur'];
?>, et ce jeu fonctionne sur <?php echo $donnees['console']; ?> <br />
Il le vend <?php echo $donnees['prix']; ?> Euros et on
peut y jouer à <?php echo $donnees['nbre_joueurs_max']; ?> au
maximum<br />
<?php echo $donnees['possesseur']; ?> a laissé ces commentaires
sur <?php echo $donnees['nom']; ?> : <em><?php echo
$donnees['commentaires']; ?></em>
c
<?php
}*/
/*$reponse = $bdd->query('SELECT nom, possesseur FROM jeu_video WHERE
possesseur=\'Florent\' AND prix<20');
while ($donnees = $reponse->fetch())
{
echo $donnees['nom'] . ' appartient à ' . $donnees['possesseur'] .
'<br />';
}
$reponse->closeCursor(); // Termine le traitement de la requête*/
$reponse = $bdd->query('SELECT nom, prix FROM jeu_video ORDER BY prix DESC LIMIT 5,16');
while ($donnees = $reponse->fetch())
{
echo $donnees['nom'] . ' coûte ' . $donnees['prix'] . ' EUR<br />';
}
$reponse->closeCursor();
?>
