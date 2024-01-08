<?php
$host="localhost";
$username="phpmyadmin";
$password="12345678";
$database="test";

$connexion=mysqli_connect($host,$username,$password,$database);

if(!$connexion){
	die("Erreur de connexion a la base de donnee:". mysqli_connect_error());
}

$query="SHOW GRANTS FOR 'root'@'localhost'";

$result=mysqli_query($connexion,$query);

if($result){
	$row=mysqli_fetch_assoc($result);
	$privileges=$row["Grants"];
	echo "Privileges de l'utlisateur root:".$privileges;
}
else{
	echo "Erreur lors de la recuperation des privileges:".mysqli_error($connexion);
}

mysqli_close($connexion);
?>