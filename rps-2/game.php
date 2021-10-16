<?php
$choice = -1;
if ( ! isset($_GET['username']) || strlen($_GET['username']) < 1)
{
    die("Name Parameter Missing");
}
if ( isset($_POST['submit']) )
    $choice = $_POST['choice'];
function call()
{
    global $choice;
    if ($choice != -1)
        echo " Output : \n";
    if ($choice == 3)
        test();
    else if ($choice > -1)
        check($choice, mt_rand(0,2));
}
function test()
{
    for ($h = 0; $h < 3; $h++)
    {
        for ($c = 0; $c < 3; $c++)
        {
            check($h, $c);
        }
    }

}
function check($h, $c)
{
    $play = array("Rock","Paper","Scissors");
    if ( ($h+1)/($c+1) == 1)
        $r = "Draw";
    else if ( ((($h+1)%3)+1)/($c+1) == 1)
        $r = "You Lose";
    else    
        $r = "You Win";
    echo "Your play : ".$play[$h]." Computer Play : ".$play[$c]." Result = ".$r."\n";
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
    <h1>Rock Paper Scissor</h1>
    <p>Welcome <?= htmlentities($_REQUEST['username']) ?></p>
    <form method="POST">
        <select name="choice">
            <option value="-1">Select</option>
            <option value="0">Rock</option>
            <option value="1">Paper</option>
            <option value="2">Scissors</option>
            <option value="3">Test</option>
        </select>
        <input type="submit" name='submit' value="Play">
        <input type="button" onclick="location.href='index.php'; return false;" value="Logout">
    </form>
    <pre><?php call(); ?></pre>
</body>
</html>