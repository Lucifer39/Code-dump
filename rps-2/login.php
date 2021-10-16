<?php 
$error = "";
$username = "";
$password = "";
$salt = "XyZzy12*_";
$required_hash = hash('md5', $salt."php123");
if ( isset($_POST['submit']) )
{
    if( strlen($_POST['uid']) < 1)
    {
        $error = "No username entered";
    }
    elseif ( strlen($_POST['pwd']) < 1 )
    {
        $error = "No password entered";
    }
    else
    {
        $username = $_POST['uid'];
        $password = $_POST['pwd'];
        $try_hash = hash('md5', $salt.$password);
        if ( $try_hash === $required_hash)
        {
            header("Location: game.php?username=".urlencode(htmlentities($username)));
        }
        else
        {
            $username = "";
            $password = "";
            $error = "Incorrect password";
        }
    }
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Anubhab Rudra</title>
</head>
<body>
    <h1>Login</h1>
    <p>Enter username and password below</p>
    <form method="POST">
        <label for="inp1">Username : </label>
        <input type="text" id="inp1" name="uid" value="<?= htmlentities($username) ?>">
        <br>
        <br>
        <label for="inp2">Password : </label>
        <input type="text" id="inp2" name="pwd" value="<?= htmlentities($password) ?>">
        <br>
        <br>
        <input type="submit" name="submit" value="Log In">
        <input type="button" onclick="location.href='index.php'; return false;" value="Cancel">
    </form>
    <p style="color: red;">
    <?php
        if ( strlen($error) > 1)
            echo $error;
    ?>
    </p>
</body>
</html>