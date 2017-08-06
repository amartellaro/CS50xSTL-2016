<?php 
    
    $stock = lookup($_POST["symbol"]);
    
    if ($stock === false)
    {
        apologize("That is not a valid stock option.");
    }

    print ("A share of ". $stock["name"] . " costs " . "<b>" . $stock["price"] . "</b>.");
?>